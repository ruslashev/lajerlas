#include "client.hh"

#include <fstream>

int main()
{
	Client client;
	puts("[Client] Loaded");
	
	puts("[Client] Connecting");
	client.Connect();

	puts("[Client] Exit");

	return 0;
}

