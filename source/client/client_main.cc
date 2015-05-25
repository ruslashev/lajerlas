#include "client.hh"

#include <fstream>

int main()
{
	Client client;
	puts("[Client] Loaded");
	
	puts("[Client] Connecting");
	if (client.Connect())
		client.Send();

	puts("[Client] Exit");

	return 0;
}

