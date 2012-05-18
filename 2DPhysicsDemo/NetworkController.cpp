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

// make sure you delete[] after using this data
char * BuildInitBuffer(World *w, int &out_bufferSize)
{
	const vector<SimBody*> &objects = w->objects;

	// Set correct ownership  on each object
	float minx = objects[4]->position.x; float maxx = minx;
	for(int i=5;i<objects.size();++i)
	{
		minx = min(objects[i]->position.x, minx);
		maxx = max(objects[i]->position.x, maxx);
	}
	const float midX = (minx + maxx) * 0.5f;
	for(int i=4;i<objects.size();++i)
	{
		if(objects[i]->position.x >= midX)
			objects[i]->owner = 2;
		else
			objects[i]->owner = 1; // other person owns objects
	}

	// Now start building the buffer for the objects
	out_bufferSize = sizeof(StartInitPacket) +  sizeof(EndInitPacket) + sizeof(InitObjectPacket)*(objects.size()-4);
	char *initBuff = new char[out_bufferSize];
	memset(initBuff, 0, out_bufferSize);

	const int TotalNumberOfObjects = objects.size();
	const int FirstTriangleIndex = w->firstTriangleIndex;

	const StartInitPacket startInitPacket(1,1,1, FirstTriangleIndex-4, TotalNumberOfObjects-FirstTriangleIndex);
	const EndInitPacket endInitPacket;

	// put the start in
	char *s = initBuff;
	memcpy(s, &startInitPacket, sizeof(startInitPacket));
	s += sizeof(startInitPacket);

	// Package all the objects and put them in the buffer
	for(int i=4;i<objects.size();++i)
	{
		SimBody *b = objects[i];
		InitObjectPacket iop;
		iop.Prepare(b->owner, i, b->position, b->velocity, b->rotation_in_rads, b->mass, b->angularVelocity, b->inertia);

		memcpy(s, &iop, sizeof(iop));
		s += sizeof(iop);
	}

	// EndInit
	memcpy(s, &endInitPacket, sizeof(endInitPacket));

	return initBuff;

};

int GetSizeFromPacketType(int type)
{
	if(type == ConnectAuth)
		return sizeof(ConnectAuthPacket);
	if(type == StartInit)
		return sizeof(StartInitPacket);
	if(type == InitObject)
		return sizeof(InitObjectPacket);
	if(type == EndInit)
		return sizeof(EndInitPacket);
	if(type == PositionOrientationUpdate)
		return sizeof(PositionOrientationUpdatePacket);
	if(type == OwnershipUpdate)
		return sizeof(OwnershipUpdatePacket);

	return 1;
};

void NetworkController::Run()
{
	if(sock == INVALID_SOCKET) return;

	FD_ZERO(&masterSet);
	FD_ZERO(&readSet);
	FD_ZERO(&writeSet);
	
	FD_SET(sock, &masterSet);
	fdmax = sock;

	if(connectionType == ServerConnection)
		mode = Listening;

	memset(buff, 0, sizeof(buff));

	while(netAlive)
	{
		readSet = masterSet;
		writeSet = masterSet;

		timeval to; to.tv_usec = to.tv_sec = 0;
		if(select(fdmax+1, &readSet, 0, 0, &to) == -1)
		{
			printf("select() failed\n");
			return;
		}

		for(int i = 0;i <= fdmax; ++i)
		{
			if(!FD_ISSET(i, &readSet)) continue;

			if(i == sock && connectionType == ServerConnection) // accept new connection
			{
				Peer out;
				if(!AcceptNewConnection(out))
				{
					printf("Failed to accept new connection!\n");
					continue;
				}

				printf("Got a new connection!\n");

				world->alive = false;
				world->primaryTaskPool_physThread->Join();

				ConnectAuthPacket authPacket(2,1);
				SimBody::whoami = 1; // server always takes ID of 1

				// send initial authorisation
				int sent=0;
				while(sent<sizeof(authPacket)) sent+=send(out.socket, (char*)&authPacket, sizeof(authPacket), 0);

				// send the initialisation buffer
				mode = Connected | Initialisation;

				int buffSz=0;
				char *initBuff = BuildInitBuffer(world, buffSz);

				sent = 0;
				while(sent < buffSz) sent += send(out.socket, initBuff, buffSz, 0);

				delete [] initBuff;

				//Sleep(1000); // sleep for a second to let the other client catch up

				connectionType = ClientConnection;

				mode = Connected | Simulating;

				// we will bring physics back to life when we get EndInit
				world->alive = true;
				world->primaryTaskPool_physThread->AddTask(Task(physthread, world));
			}
			else
			{
				// READ DATA
				char *readPos = &buff[writeOffset];
				int maxToRead = NETWORK_READ_BUFFER_SIZE - writeOffset;
				int bytesRead = recv(i, readPos, maxToRead, 0);
				char *lastbyte = readPos + bytesRead;
				writeOffset = 0;

				if(bytesRead <= 0)
				{
					printf("Disconnected\n");

					FD_CLR(i, &masterSet);
					
					connectionType = ServerConnection;

					FD_SET(sock, &masterSet);
					fdmax = sock;
					readSet = writeSet = masterSet;

					for(int i=0;i<world->objects.size();++i)
					{
						world->objects[i]->owner = SimBody::whoami;
					}
				}

				char *buffPos = buff;

				if(mode & Authorisation)
				{
					world->alive = false;
					world->primaryTaskPool_physThread->Join();

					while(buffPos < lastbyte)
					{
						char _type = buffPos[0]; // since we move data back to start, the type will be at the start of the packet
						const int typeSize = GetSizeFromPacketType(_type);

						/**********************************/
						/******  CONNECT AUTH PACKET ******/
						/**********************************/
						if(_type == ConnectAuth) // Parse the ConnectAuth packet
						{
							char *tmp = buffPos + typeSize;
							if(tmp <= lastbyte)
							{
								printf("Got ConnectAuth packet!\n");
								ConnectAuthPacket authPacket;
								memcpy(&authPacket, buffPos, typeSize);
								buffPos = tmp;
								SimBody::whoami = authPacket.assignedOwnerIdentifier;

								init.gotStartInit = init.gotEndInit = false;

								mode = Connected | Initialisation;
								break;
							}
							else
							{
								int amountToCopy = lastbyte - buffPos;
								writeOffset = amountToCopy;
								memcpy(buff, buffPos, amountToCopy);
								buffPos = lastbyte; // get out of the loop as we have an incomplete packet!!!
								continue;
							}
						}

						/****************************/
						/** OTHER PACKETS (IGNORE) **/
						/****************************/
						else
						{
							buffPos += typeSize; // ignore all other packets until we get what we want (ConnectAuth)
						}
					}
					
				}
				if(mode & Initialisation)
				{
					while(buffPos < lastbyte)
					{
						char _type = buffPos[0]; // since we move data back to start, the type will be at the start of the packet
						const int typeSize = GetSizeFromPacketType(_type);

						/**********************************/
						/*******  START INIT PACKET *******/
						/**********************************/
						if(_type == StartInit && !init.gotStartInit && !init.gotEndInit) // only accept StartInit once
						{
							char *tmp = buffPos + typeSize;
							if(tmp <= lastbyte)
							{
								printf("Got StartInit packet!\n");

								StartInitPacket start;
								memcpy(&start, buffPos, sizeof(start));
								buffPos = tmp;

								init.gotStartInit = true;

								StartInitData startData = start.Unprepare();

								world->CreateBaseObjects(1,1,1,startData.boxCount, startData.triangleCount);
							}
							else
							{
								int amountToCopy = lastbyte - buffPos;
								writeOffset = amountToCopy;
								memcpy(buff, buffPos, amountToCopy);
								buffPos = lastbyte; // get out of the loop as we have an incomplete packet!!!
								continue;
							}
						}

						/**********************************/
						/******  INIT OBJECT PACKET *******/
						/**********************************/
						else if(_type == InitObject && init.gotStartInit && !init.gotEndInit) // only accept InitObject if we've got StartInit but not EndInit yet
						{
							char *tmp = buffPos + typeSize;
							if(tmp <= lastbyte)
							{
								//printf("Got InitObject packet!\n");

								InitObjectPacket iop;
								memcpy(&iop, buffPos, sizeof(iop));
								buffPos = tmp;

								// setup object
								InitObjectData iod = iop.Unprepare();
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
							else
							{
								int amountToCopy = lastbyte - buffPos;
								writeOffset = amountToCopy;
								memcpy(buff, buffPos, amountToCopy);
								buffPos = lastbyte; // get out of the loop as we have an incomplete packet!!!
								continue;
							}
						}

						/**********************************/
						/********  END INIT PACKET ********/
						/**********************************/
						else if(_type == EndInit && init.gotStartInit && !init.gotEndInit) // only accept EndInit if we have got the StartInit packet so far
						{
							char *tmp = buffPos + typeSize;
							if(tmp <= lastbyte)
							{
								printf("Got EndInit packet!\n");

								init.gotEndInit = true;

								mode = Connected | Simulating;

								// Bring the physics  thread back to life
								world->alive=true;
								world->arbiters.clear();
								world->primaryTaskPool_physThread->AddTask(Task(physthread, world));

								break; // break out of Initialisation checks, we can now move on to simulation stuff
							}
							else
							{
								int amountToCopy = lastbyte - buffPos;
								writeOffset = amountToCopy;
								memcpy(buff, buffPos, amountToCopy);
								buffPos = lastbyte; // get out of the loop as we have an incomplete packet!!!
								continue;
							}
						}


						/****************************/
						/** OTHER PACKETS (IGNORE) **/
						/****************************/
						else
						{
							buffPos += typeSize; // ignore all other packets until we get what we want (StartInit, InitObject and EndInit packets)
						}
					}
				}
				if(mode & Simulating)
				{
					while(buffPos < lastbyte)
					{
						char _type = buffPos[0]; // since we move data back to start, the type will be at the start of the packet
						const int typeSize = GetSizeFromPacketType(_type);

						/*************************************/
						/** POSITION AND ORIENTATION UPDATE **/
						/*************************************/
						if(_type == PositionOrientationUpdate)
						{
							//printf("Got position/orientation update packet\n");
							
							char *tmp = buffPos + typeSize;
							if(tmp <= lastbyte)
							{
								PositionOrientationUpdatePacket posPacket;
								memcpy(&posPacket, buffPos, sizeof(posPacket));
								buffPos = tmp;

								PositionOrientationData pod = posPacket.Unprepare();

								vector<SimBody*> &objects = world->objects;
								objects[pod.objectIndex]->position = pod.pos;
								objects[pod.objectIndex]->rotation_in_rads = pod.orientation;
								objects[pod.objectIndex]->UpdateWorldSpaceProperties();
							}
							else
							{
								int amountToCopy = lastbyte - buffPos;
								writeOffset = amountToCopy;
								memcpy(buff, buffPos, amountToCopy);
								buffPos = lastbyte; // get out of the loop as we have an incomplete packet!!!
								continue;
							}
						}

						/*************************************/
						/********** OWNERSHIP UPDATE *********/
						/*************************************/
						else if(_type == OwnershipUpdate)
						{
							char *tmp = buffPos + typeSize;
							if(tmp <= lastbyte)
							{
								OwnershipUpdatePacket opack;
								memcpy(&opack, buffPos, sizeof(opack));
								buffPos = tmp;

								OwnershipUpdateData odata = opack.Unprepare();

								vector<SimBody*> &objects = world->objects;
								objects[odata.objectIndex]->owner = SimBody::whoami;
							}
							else
							{
								int amountToCopy = lastbyte - buffPos;
								writeOffset = amountToCopy;
								memcpy(buff, buffPos, amountToCopy);
								buffPos = lastbyte; // get out of the loop as we have an incomplete packet!!!
								continue;
							}
						}

						/****************************/
						/** OTHER PACKETS (IGNORE) **/
						/****************************/
						else
						{
							buffPos += typeSize;
						}
					}
				}
			}
		}
	}
};