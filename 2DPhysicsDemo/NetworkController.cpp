#include "NetworkController.h"
#include <fcntl.h>
#include "World.h"

static int INIT_COUNT=0;
bool wsa_init()
{
#ifdef _WIN32
	if(INIT_COUNT) return true; // dont initialise more than once

	WORD wVersionRequested = MAKEWORD( 2, 0 );
	WSADATA wsaData;
	if(WSAStartup(wVersionRequested, &wsaData))
	{
		cout << "socket initialisation failed" << endl;
		return false;
	}

	++INIT_COUNT;
	return true;
#else
	return true;
#endif
};
void wsa_cleanup()
{
	if(INIT_COUNT == 1) // cleanup if we're the last NetworkController left. Dont cleanup Windows networking stack if in use!
	{
		WSACleanup();
		INIT_COUNT = 0;
	}
};

void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) // ipv4
	{
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}
	//ipv6
	return &(((struct sockaddr_in6*)sa)->sin6_addr);
};

bool EnoughData(char **f, int sz, char **last)
{
	return (f+sz)<=last;
};

void NetThread(void *networkController)
{
	NetworkController *c = (NetworkController*)networkController;
	c->Run();
};

string Peer::GetIP()
{
	char remoteIP[64];
	inet_ntop(addr.ss_family,  get_in_addr((struct sockaddr*)&addr), remoteIP, INET_ADDRSTRLEN);
	return string(remoteIP);
};

NetworkController::NetworkController(void)
{
	wsa_init();
	sock = INVALID_SOCKET;
	writeOffset = 0;
	connectionType = ServerConnection;
	netAlive = true;
	activeUpdateCache = 0;
}

NetworkController::~NetworkController(void)
{
	wsa_cleanup();
}

void NetworkController::Shutdown()
{
	shutdown(sock, SD_BOTH);
};

bool NetworkController::StartListening(unsigned short _port, int backlog)
{
	if(sock == INVALID_SOCKET)
	{
		sock = socket(AF_INET, SOCK_STREAM, 0);
		if(sock == INVALID_SOCKET)
		{
			return false;
		}
	}

	// allow address reuse (to stop "socket already in use" problems)
	int ys; setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char*)&ys, sizeof(int));

	port = 0;

	sockaddr_in peer;
	peer.sin_family = AF_INET;
	peer.sin_port = htons(_port);	// default port 9171
	peer.sin_addr.S_un.S_addr = htonl( INADDR_ANY );

	// bind socket
	if (bind(sock, (sockaddr*)&peer, sizeof(peer)) < 0)
	{
		closesocket(sock);
		sock=INVALID_SOCKET;
		return false;
	}

	// start listening with backlog (default 1)
	if(listen(sock, backlog) == -1) // start listening (non-blocking operation)
	{
		closesocket(sock);
		sock=INVALID_SOCKET;
		return false;
	}

	port = _port;

	return true;
};

bool NetworkController::Connect(const char *ipAddr, unsigned short _port)
{
	FD_ZERO(&masterSet);
	FD_ZERO(&readSet);
	FD_ZERO(&writeSet);

	if(sock == INVALID_SOCKET)
	{
		sock = socket(AF_INET, SOCK_STREAM, 0);
		if(sock == INVALID_SOCKET)
		{
			return false;
		}
	}

	port = 0;

	sockaddr_in peer;
	peer.sin_family = AF_INET;
	peer.sin_port = htons(_port);	// port 9171
	peer.sin_addr.S_un.S_addr = inet_addr(ipAddr);

	int nf = connect(sock, (sockaddr *)&peer, sizeof(peer));
	if(nf == SOCKET_ERROR)
	{
		cout << "Connect to peer failed with " << WSAGetLastError() << endl;
		return false;
	}

	FD_SET(sock, &masterSet);

	connectionType = ClientConnection;

	port = _port;

	mode = Connected | Authorisation;

	fdmax = sock;

	return true; // we've made a connection on socket "sock"
};

bool NetworkController::AcceptNewConnection(Peer &outputPeer)
{
	sockaddr_storage remoteaddr;
	socklen_t addrlen = sizeof(remoteaddr);

	int newfd = accept(sock, (struct sockaddr*)&remoteaddr, &addrlen);
	if(newfd == -1) return false;

	FD_SET(newfd, &masterSet);
	if(newfd > fdmax) fdmax=newfd;

	// maintain peer list - not actually used but makes it easier to get details
	Peer p;
	p.socket = newfd;
	p.addr = remoteaddr;
	peers.push_back(p);

	outputPeer = peers.back();

	// print out some details
	char remoteIP[64];
	PCSTR d = inet_ntop(remoteaddr.ss_family,  get_in_addr((struct sockaddr*)&remoteaddr), remoteIP, INET_ADDRSTRLEN);
	int onSocket = newfd;
	sockaddr_storage addr_in;
	socklen_t len = sizeof(addr_in);
	getpeername(sock, (struct sockaddr*)&addr_in, &len);
	sockaddr_in *s = (sockaddr_in*)&addr_in;
	int port = ntohs(s->sin_port);
	cout << "New connection from " << d << " on socket " << onSocket << ", and on port " << port << endl;

	return true;
};

void NetworkController::SendData(char *data, int size)
{
	int i=0;
	while(i<size)
	{
		i += send(sock, data, size, 0);
	}
};

void NetworkController::Close()
{
	closesocket(sock);
	sock = INVALID_SOCKET;
};

void NetworkController::ClearActiveCache()
{
	//int acache = activeUpdateCache % 2;
	//position_orientation_update_cache[acache].clear();
}
void NetworkController::AddToActiveUpdateCache(SimBody *s)
{
	//int acache = activeUpdateCache % 2;
	//position_orientation_update_cache[acache].push_back(s);
};

struct pos_orientation_send_buffer_cache
{
	SimBody *body;
	int index;
};

void NetworkController::Run()
{
	if(sock == INVALID_SOCKET)
		return;

	FD_ZERO(&masterSet);
	FD_ZERO(&readSet);
	FD_ZERO(&writeSet);

	FD_SET(sock, &masterSet);
	fdmax = sock;

	if(connectionType == ServerConnection)
	{
		mode = Listening;
	}


	bool f = true;

	while(f)
	{
		cs.Lock();
		f = netAlive;
		cs.Unlock();

		readSet = masterSet;
		writeSet = masterSet;

		timeval to; to.tv_sec = to.tv_sec = 0;

		// can we read?
		if(select(fdmax+1, &readSet, 0,0,&to) == -1)
			continue;

		for(int i=0;i<=fdmax;++i)
		{
			if(!FD_ISSET(i, &readSet)) continue;

			if(i == sock && connectionType == ServerConnection)
			{
				Peer out;
				if(!AcceptNewConnection(out)) continue;

				// If we accept a connection, it is now the "parent" of the connection.
				mode = Connected | Authorisation;

				world->alive = false;
				world->primaryTaskPool_physThread->Join();

				// Send ConnectAuth packets to tell the other machine what it is
				// On connection send a packet describing "who" each machine is (specifically the ID they will put in objects to identify them as personally owned)
				// Note: the numbers 1 and 2 have been chosen specifically. These numbers will allow us to differentiate between 2 different owners using binary logic
				// e.g. owner & 0x01. If we set the number to 3 however, the object will have 2 owners (a combination of 1 and 2 in binary). Thus, if (owner && 3) it has 2 owners

				ConnectAuthPacket cup;
				cup.Prepare(2,1); // we give the machine connecting to us ID 2, we keep ID 1

				SimBody::whoami = 1;

				send(out.socket, (const char*)&cup, sizeof(ConnectAuthPacket), 0);

				mode = Connected | Initialisation;

				int initBuffSz = sizeof(StartInitPacket) + 
					(sizeof(InitObjectPacket) * (world->objects.size()-4)) +
					sizeof(EndInitPacket);
				char *initialisationBuffer = new char[initBuffSz];
				memset(initialisationBuffer, 0, initBuffSz);

				int total_cnt = world->objects.size(), first_tri_cnt = world->firstTriangleIndex;

				// Put the start and end packets in the buffer
				f32 box_width    = meters(world->conf.Read("BoxWidth"  ,      1.0f));
				f32 box_height   = meters(world->conf.Read("BoxHeight" ,      1.0f));
				f32 triangle_len = meters(world->conf.Read("TriangleLength",  1.0f));

				StartInitPacket sip(box_width,box_height,triangle_len, first_tri_cnt-4, total_cnt-first_tri_cnt);
				memcpy(initialisationBuffer, (char*)&sip, sizeof(sip));
				EndInitPacket eip; memcpy(&initialisationBuffer[initBuffSz-sizeof(EndInitPacket)], &eip, sizeof(EndInitPacket));

				char *st = &initialisationBuffer[sizeof(StartInitPacket)];

				float min_x = world->objects[4]->position.x;
				float max_x = min_x;

				for(unsigned int i=5;i<world->objects.size();++i)
				{
					SimBody *s = world->objects[i];
					if(s->position.x < min_x) min_x = s->position.x;
					else if(s->position.x >= max_x) max_x = s->position.x;
				}
				float midX = (min_x + max_x) * 0.5f;

				for(unsigned int i=4;i<world->objects.size();++i)
				{
					SimBody* s = world->objects[i];

					InitObjectPacket iop;

					int index=1;
					if(s->position.x >= midX)
					{
						index=2;
					}
					s->owner = index; // set index for ourselves so we no longer update the side the other is going to update

					iop.Prepare(index, i, s->position, s->velocity, s->rotation_in_rads, s->mass, s->angularVelocity, s->inertia);

					memcpy(st, ((char*)&iop), sizeof(iop));
					st += sizeof(InitObjectPacket);
				}

				// At this point the initialisation buffer should be full with all the data we need, so send it down the pipes :)
				int sentBytes=0;
				while(sentBytes<initBuffSz)
				{
					sentBytes += send(out.socket, initialisationBuffer, initBuffSz, 0);
				}

				delete [] initialisationBuffer;

				connectionType = ClientConnection;

				world->alive = true;
				world->primaryTaskPool_physThread->AddTask(Task(physthread, world));
			}
			else
			{
				char *readPos = &buff[writeOffset];
				int maxToRead = NetworkController::NETWORK_READ_BUFFER_SIZE - writeOffset;

				// For safety and to ensure we don't read any rubbish, set the rest of the buffer to 0
				memset(readPos, 0, sizeof(char)*maxToRead);

				int bytesRead = recv(i, readPos, maxToRead, 0);

				if(bytesRead <= 0)
				{
					printf("Disconnected\n");

					closesocket(i); // bye!
					FD_CLR(i, &masterSet);

					FD_ZERO(&readSet);
					FD_ZERO(&writeSet);

					FD_SET(sock, &masterSet);
					fdmax = sock;

					cout << "Started listening " << endl;
					Close();
					connectionType = ServerConnection;
					this->StartListening(this->port);
					writeOffset = 0;
					memset(buff,0,sizeof(buff));
					peers.clear();

					break;
				}

				// first byte to process is at: buff (start of array)
				// last byte to process is at:  readPos + bytesRead
				char *lastByte = readPos + bytesRead;

				char *f = buff;
				// when we haven't got enough data for a full packet, 'f' should end up
				// pointing to the start of the last incomplete packet. We then need to copy
				// from f to lastByte (lastByte-f # bytes) to the start of the array, and set the
				// write offset to lastByte-f. We should also nullify the rest of the array so
				// it only contains the incomplete data

				// note: regardless of the application mode, we should ALWAYS process the packet enough to get the data out of the buffer
				// otherwise it will be stuck there and we will be in trouble as 'f' will never be moved :(

				PositionOrientationUpdatePacket posOrientationPacket;
				char *tmp=0;

				while(f < lastByte)
				{
					char type = *f; // get the type (assumed at start), process the packet and move f as far forward as required

					if(mode & Simulating)
					{
						switch(type)
						{
						case PositionOrientationUpdate:

							tmp = f + sizeof(PositionOrientationUpdatePacket);

							if(tmp <= lastByte)
							{
								//cout << "gotpou" << endl;

								memcpy(&posOrientationPacket, f, sizeof(PositionOrientationUpdatePacket));
								f += sizeof(PositionOrientationUpdatePacket);
								PositionOrientationData pod = posOrientationPacket.Unprepare();

								if(pod.objectIndex < world->objects.size() && pod.objectIndex >= 0)
								{
									vector<SimBody*> &objects = world->objects;
									objects[pod.objectIndex]->position = pod.pos;
									objects[pod.objectIndex]->rotation_in_rads = pod.orientation;
									objects[pod.objectIndex]->UpdateWorldSpaceProperties();
								}

							}
							else
							{
								char *dataPosition = f;
								int amountOfDataToMoveBack = lastByte - dataPosition;
								writeOffset = amountOfDataToMoveBack;
								memcpy(buff, dataPosition, amountOfDataToMoveBack);
								f = lastByte;
							}

							break;

						default:
							++f;
							break;
						}

						continue;
					}

					ConnectAuthPacket authPacket;
					StartInitPacket startInitPacket;
					InitObjectPacket initObjectPacket;
					EndInitPacket endInitPacket;
					PositionOrientationUpdatePacket posOrientationPacket;
					char *tmp=0;

					// Process all the packets from the buffer
					switch(type)
					{
					case KeepAlive:
						cout << "Got a KeepAlive packet!" << endl;
						f += sizeof(KeepAlivePacket);
						//++f; // keep alive is a single byte packet, so just increment 'f'
						break;
					case ConnectAuth:

						tmp = f + sizeof(ConnectAuthPacket);
						if(tmp <= lastByte)
						{
							cout << "Got a ConnectAuth packet!" << endl;

							memcpy(&authPacket, f, sizeof(ConnectAuthPacket)); // easiest way to get the data out :)
							f += sizeof(ConnectAuthPacket);

							cout << "Assigned Owner ID: " << (int)authPacket.assignedOwnerIdentifier << " ,  " <<
								"Other Owner ID: " << (int)authPacket.otherMachineIdentifier << endl;

							if(mode & Authorisation)
							{
								// once we know who we are, switch into initialisation mode
								mode = Connected | Initialisation;

								SimBody::whoami = authPacket.assignedOwnerIdentifier;
							}
						}
						else
						{
							char *dataPosition = f;
							int amountOfDataToMoveBack = lastByte - dataPosition;
							writeOffset = amountOfDataToMoveBack;
							memcpy(buff, dataPosition, amountOfDataToMoveBack);
							f = lastByte;
						}
						break;

					case StartInit:

						tmp = f + sizeof(StartInitPacket);

						if( tmp <= lastByte )
						{
							cout << "Got a StartInit packet!" << endl;

							memcpy(&startInitPacket, f, sizeof(StartInitPacket));
							f += sizeof(StartInitPacket);

							StartInitData initData2 = startInitPacket.Unprepare();
							cout << "Box Count: " << initData2.boxCount << " , Triangle Count: " << initData2.triangleCount << endl;

							if(mode & Initialisation)
							{
								StartInitData initData = startInitPacket.Unprepare();

								init.gotStartInit = true;
								init.gotEndInit = false;

								world->alive = false;
								world->primaryTaskPool_physThread->Join();

								// Allocate all the memory we need for objects, so we can later just index into them
								world->CreateBaseObjects(initData.boxWidth, initData.boxHeight, initData.triangleSideLength,
									initData.boxCount, initData.triangleCount);
							}
						}
						else
						{
							char *dataPosition = f;
							int amountOfDataToMoveBack = lastByte - dataPosition;
							writeOffset = amountOfDataToMoveBack;
							memcpy(buff, dataPosition, amountOfDataToMoveBack);
							f = lastByte;
						}

						break;
					case InitObject:

						tmp = f + sizeof(InitObjectPacket);

						if(tmp <= lastByte)
						{
							memcpy(&initObjectPacket, f, sizeof(InitObjectPacket));
							f += sizeof(InitObjectPacket);

							if(mode & Initialisation)
							{
								// only process it if we've got startInit but NOT endInit. This check may
								// not be required (for !init.gotEndInit), as when EndInit is received we
								// will switch to initialisation mode
								if(init.gotStartInit && !init.gotEndInit)
								{
									// Process the data:
									InitObjectData iod = initObjectPacket.Unprepare();

									// TODO: SETUP OBJECT BASED ON DATA IN iod
									// SETUP OBJECT BASED ON DATA IN iod
									vector<SimBody*> &objects = world->objects;
									objects[iod.objectIndex]->owner = iod.originalOwner;
									objects[iod.objectIndex]->position = iod.pos;
									objects[iod.objectIndex]->velocity = iod.velocity;
									objects[iod.objectIndex]->angularVelocity = iod.angularVelocity;
									objects[iod.objectIndex]->mass = iod.mass;
									objects[iod.objectIndex]->invMass = 1.0f/iod.mass;
									objects[iod.objectIndex]->inertia = iod.inertia;
									objects[iod.objectIndex]->invInertia = 1.0f/iod.inertia;
									objects[iod.objectIndex]->rotation_in_rads = iod.orientation;
									objects[iod.objectIndex]->UpdateWorldSpaceProperties();

								}
							}
						}
						else
						{
							// We've found an incomplete packet. Move it back to the start of the array and
							// get out of this loop (by setting f=lastByte)
							char *dataPosition = f;
							int amountOfDataToMoveBack = lastByte - dataPosition;
							writeOffset = amountOfDataToMoveBack;
							memcpy(buff, dataPosition, amountOfDataToMoveBack);
							f = lastByte;
						}

						break;
					case EndInit:

						cout << "Got an EndInit packet!" << endl;

						// EndInit packet is a single byte packet, so we dont need to check we have enough
						// data :)
						memcpy(&endInitPacket, f, sizeof(EndInitPacket));
						f += sizeof(EndInitPacket);

						if(mode & Initialisation)
						{
							if(init.gotStartInit && !init.gotEndInit)
							{
								init.gotEndInit = true;

								mode = Connected | Simulating; // once we've got the EndInit, we can flip into simulation mode.

								world->physicsPaused=false;

								// restart the physics thread
								world->alive=true;
								world->arbiters.clear();

								world->primaryTaskPool_physThread->AddTask(Task(physthread, world));

							}
						}

						break;

					case PositionOrientationUpdate:

						tmp = f + sizeof(PositionOrientationUpdatePacket);

						if(tmp <= lastByte)
						{
							//cout << "Got a PositionOrientationUpdate packet!" << endl;

							memcpy(&posOrientationPacket, f, sizeof(PositionOrientationUpdatePacket));
							f += sizeof(PositionOrientationUpdatePacket);

							PositionOrientationData pod = posOrientationPacket.Unprepare();
							//cout << "Position: " << pod.pos.x << "," << pod.pos.y << " ; "
							//	<< "Orientation: " << pod.orientation << endl;

							//cout << "got pos update packet" << endl;

							mode = Connected | Simulating;

							if(mode & Simulating)
							{
								// Process the data here (add the new update to the update delta list)
								PositionOrientationData pod = posOrientationPacket.Unprepare();

								if(pod.objectIndex < world->objects.size() && pod.objectIndex >= 0)
								{
									cout << "got pos update packet" << endl;

									vector<SimBody*> &objects = world->objects;
									objects[pod.objectIndex]->position = pod.pos;
									objects[pod.objectIndex]->rotation_in_rads = pod.orientation;
									objects[pod.objectIndex]->UpdateWorldSpaceProperties();
								}
								else
								{
									cout << "read invalid packet" << endl;
								}
							}
						}
						else
						{
							char *dataPosition = f;
							int amountOfDataToMoveBack = lastByte - dataPosition;
							writeOffset = amountOfDataToMoveBack;
							memcpy(buff, dataPosition, amountOfDataToMoveBack);
							f = lastByte;
						}

						break;
					}
				}

				//char buff[100]; memset(buff,0,100);
				//recv(i, buff, 100, 0); // receive from client i

				// send to all
				//for(int j = 0; j <= fdmax; j++)
				//{
				//	if (FD_ISSET(j, &masterSet))
				//	{
				//		if (j != sock && j != i)
				//		{
				//			send(j, buff, 100,0);
				//		}
				//	}
				//}
			}
		}
	}

	/*
	The Run function must do the following:

	* If the socket is valid
	* While True
	* Call select() with a timeout of 0 to find if there is data
	to 'read' from the stream
	* If yes, read the data and parse it, appending changes to a "delta-update"
	list. The delta-update list is used at the end of each physics step to
	change positions/orientations of objects (etc)
	* Call select() to find if we can write to the stream
	* If yes, write the data to the stream (apparently, we can send
	floats directly over the network, no need to marshal the data :)
	*/
};