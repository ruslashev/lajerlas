#include "server.hh"

#include <fstream>

int main()
{
	Server server;
	puts("[Server] Loaded");

	puts("[Server] Polling");
	while (1) {
		server.Poll();
	}
	puts("[Server] Exit");

	return 0;
}

