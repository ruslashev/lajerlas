#include "client.hh"

Client::Client()
{
	assertf(enet_initialize() == 0,
			"Failed to initialize ENet");

	host = enet_host_create(nullptr,
			1,
			2,
			0,
			0);
	assertf(host,
			"An error occurred while trying to create a client.");
}

Client::~Client()
{
	enet_host_destroy(host);
	enet_deinitialize();
}

void Client::Send(ENetPeer *peer)
{
	ENetPacket *packet = enet_packet_create("packet",
			strlen("packet") + 1,
			ENET_PACKET_FLAG_RELIABLE);

	enet_peer_send (peer, 0, packet);

	enet_host_flush (host);
}

