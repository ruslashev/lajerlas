#include "server.hh"

#include <fstream>

int main()
{
	puts("server initializing");

	Server server;

	while (1) {
		server.Poll();
	}

	return 0;
}

