#pragma once

#include <WinSock2.h>
#include <Ws2tcpip.h>
#include "NetworkPacket.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include "ThreadPool.h"
using namespace std;

bool wsa_init();
void wsa_cleanup();

void *get_in_addr(struct sockaddr *sa);
class Peer // utility class, the main action happens in NetworkController
{
public:
	sockaddr_storage addr;
	int socket;

	string GetIP();
};

struct InitDetails
{
	bool gotStartInit, gotEndInit;

	InitDetails() : gotStartInit(false), gotEndInit(false) {};
};

class World;
class SimBody;

// You should only ever need one of these. NetworkController manages sending and receiving data between peers for
// the physics application
class NetworkController
{
public:

	CriticalSection cs;
	bool netAlive;

	// Binary OR modes together to get functionality. E.g. once connected Connected bit will always be set
	enum ExecutionMode
	{
		Listening = 1,
		Connected = 2,
		Authorisation = 4,
		Initialisation = 8,
		Simulating = 16,
		OwnerUpdate = 32, //?
	};

	enum ConnectionType
	{
		// In ClientConnection mode, we don't accept connections. This is used
		// when one machine connects to the other and they need to exchange data.
		// The other machine is in ServerConnection mode, as it accepted a connection.
		// When the connection is broken, both machines should flip back into ServerConnection
		// mode, so they can both accept new connections

		ClientConnection, // used when we connect to the other machine
		ServerConnection, // used when the other machine connects to us
	};

	int activeUpdateCache;
	vector<SimBody*> position_orientation_update_cache[2];

	vector<Peer> peers;
	fd_set masterSet, readSet, writeSet;
	int fdmax;
	int sock;
	unsigned short port;
	
	static const int NETWORK_READ_BUFFER_SIZE = 8096*4; //32k buffer
	char buff[NETWORK_READ_BUFFER_SIZE];
	int writeOffset; // what offset into buff do we start reading?

	NetworkPacketType currentMessageType; // what message are we currently processing?

	InitDetails init;

	int mode;

	ConnectionType connectionType;

	World *world;

public:
	NetworkController(void);
	~NetworkController(void);

	void ClearActiveCache();
	void AddToActiveUpdateCache(SimBody *s);

	void SetWorldPointer(World *w) { world = w; };

	// test function to make sure we can connect to the listener
	bool Connect(const char *ipAddr, unsigned short port);

	bool StartListening(unsigned short port=9171, int backlog=1); // if reopen=true, the socket will be closed and recreated
	void Shutdown(); // stops all sending and receiving

	bool AcceptNewConnection(Peer &outputPeer);

	// this contains the main networking loop. Put the network controller on its own thread and call NetThread(&controller)
	// this could implement much of our networking protocol and state managent
	void Run();

	void SendData(char *data, int size);

	// Close the socket and set it to INVALID_SOCKET.
	// Use this when you need to refresh it, either to start listening,
	// or to connect to another machine.
	// If you try and use a socket already in use for listening/connected,
	// the functions will fail
	void Close();
};

void NetThread(void *networkController);