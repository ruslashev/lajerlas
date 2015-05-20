#ifndef CLIENT_HH
#define CLIENT_HH

#include "../utils.hh"
#include "../constants.hh"

#include <enet/enet.h>
#include <cstring>

class Client
{
	ENetHost *host;
public:
	Client();
	~Client();

	void Send(ENetPeer*);
};

#endif

