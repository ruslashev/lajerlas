#include "client.hh"

#include <fstream>

int main()
{
	Client client;
	debug("[Client] Loaded");
	
	debug("[Client] Connecting");
	if (!client.Connect())
		return 1;

	debug("[Client] Exit");

	return 0;
}

