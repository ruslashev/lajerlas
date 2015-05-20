#include "server.hh"

Server::Server()
{
	assertf(enet_initialize() == 0,
			"Failed to initialize ENet");

	address.host = ENET_HOST_ANY;
	address.port = Constants.ServerPort;

	host = enet_host_create(&address,
			Constants.MaxClients,
			2, 0, 0);
	assertf(host,
			"An error occurred while trying to create a server.");
}

Server::~Server()
{
	enet_host_destroy(host);
	enet_deinitialize();
}

void Server::Poll()
{
	ENetEvent event;
	while (enet_host_service(host, &event, 0) > 0) {
		switch (event.type) {
			case ENET_EVENT_TYPE_CONNECT:
				printf("A new client connected from %x:%u.\n",
						event.peer->address.host,
						event.peer->address.port);
				memcpy(event.peer->data, "Client data",
						strlen("Client data"));
				break;
			case ENET_EVENT_TYPE_RECEIVE:
				printf("A packet of length %u containing %s was received from %s on channel %u.\n",
						event.packet->dataLength,
						event.packet->data,
						event.peer->data,
						event.channelID);
				enet_packet_destroy (event.packet);
				break;
			case ENET_EVENT_TYPE_DISCONNECT:
				printf ("%s disconnected.\n", event.peer -> data);
				event.peer -> data = NULL;
		}
	}
}

void Server::DisconnectClient(ENetPeer* peer)
{
	ENetEvent event;
	enet_peer_disconnect(peer, 0);
	while (enet_host_service(host, &event, 3000) > 0) {
		switch (event.type) {
			case ENET_EVENT_TYPE_RECEIVE:
				enet_packet_destroy(event.packet);
				break;
			case ENET_EVENT_TYPE_DISCONNECT:
				puts("Disconnection succeeded.");
				return;
		}
	}
	enet_peer_reset(peer);
}

