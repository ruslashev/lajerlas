#include "client.hh"

#include <fstream>

int main()
{
	puts("I am a client AMA");
	Client client;
	
	client.Send();

	return 0;
}

