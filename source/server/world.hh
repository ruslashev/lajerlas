#ifndef WORLD_HH
#define WORLD_HH

#include "../utils.hh"
#include "../constants.hh"

#include <ctype>
#include <string>

typedef uint16_t tile;

class World
{
public:
	std::string name;
	uint16_t width;
	uint16_t height;
};

#endif

