#include "client.hh"

Client::Client()
{
	assertf(enet_initialize() == 0,
			"[Client] Failed to initialize ENet");

	host = enet_host_create(nullptr,
			1,
			2,
			0,
			0);
	assertf(host,
			"[Client] An error occurred while trying to create a client.");
}

Client::~Client()
{
	enet_host_destroy(host);
	enet_deinitialize();
}

bool Client::Connect()
{
	ENetAddress address;
	enet_address_set_host(&address, "127.0.0.1");
	address.port = Constants.ServerPort;

	server = enet_host_connect(host, &address, 2, 0);
	assertf(server,
			"[Client] No available peers for initiating an ENet connection.");

	// Wait up to 5 seconds for the connection attempt to succeed.
	int tries = 2;
	ENetEvent event;
	while (tries > 1) {
		if (enet_host_service(host, &event, 5000) > 0 &&
				event.type == ENET_EVENT_TYPE_CONNECT) {
			puts("[Client] Connection succeeded.");
			return true;
		} else {
			enet_peer_reset(server);
			--tries;
		}
	}
	puts("[Client] Connection failed after 2 retries.");
}

void Client::Send()
{
	puts("[Client] Sending");
	ENetPacket *packet = enet_packet_create("packet",
			strlen("packet") + 1,
			ENET_PACKET_FLAG_RELIABLE);

	enet_peer_send(server, 0, packet);

	enet_host_flush(host);
}

