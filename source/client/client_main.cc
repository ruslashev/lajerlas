#include "client.hh"

#include <fstream>

int main()
{
	puts("I am a client AMA");
	Client client;
	
	client.Connect();

	return 0;
}

