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

void Client::Connect()
{
	ENetAddress address;
	ENetEvent event;
	enet_address_set_host(&address, "127.0.0.1");
	address.port = Constants.ServerPort;
	server = enet_host_connect(host, &address, 2, 0);
	assertf(server,
			"No available peers for initiating an ENet connection.");

	// Wait up to 5 seconds for the connection attempt to succeed.
	if (enet_host_service(host, &event, 5000) > 0 &&
			event.type == ENET_EVENT_TYPE_CONNECT) {
		puts ("Connection succeeded.");
		Send();
	} else {
		/* Either the 5 seconds are up or a disconnect event was */
		/* received. Reset the peer in the event the 5 seconds   */
		/* had run out without any significant event.            */
		enet_peer_reset(server);
		puts("Connection failed.");
	}
}

void Client::Send()
{
	ENetPacket *packet = enet_packet_create("packet",
			strlen("packet") + 1,
			ENET_PACKET_FLAG_RELIABLE);

	enet_peer_send(server, 0, packet);

	enet_host_flush(host);
}

