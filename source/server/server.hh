#ifndef SERVER_HH
#define SERVER_HH

#include "../utils.hh"
#include "../constants.hh"

#include <enet/enet.h>

class Server
{
	ENetAddress address;
	ENetHost *host;
public:
	Server();
	~Server();
};

#endif

