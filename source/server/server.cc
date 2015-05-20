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
			"An error occurred while trying to create an ENet host.");
}

Server::~Server()
{
	enet_host_destroy(host);
	enet_deinitialize();
}

