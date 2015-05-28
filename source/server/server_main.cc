#include "server.hh"

#include <fstream>

int main()
{
	Server server;
	debug("[Server] Loaded");

	debug("[Server] Polling");
	while (1) {
		server.Poll();
	}
	debug("[Server] Exit");

	return 0;
}

