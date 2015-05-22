#ifndef TILES_HH
#define TILES_HH

#include <string>

enum TileColor {
	TileRed,
	TileYellow,
	TileGreen,
	TileCyan,
	TileBlue,
	TilePurple;
	TileWhite;
	TileGray;
	TileBlack;
}

const struct {
	char symbol;
	bool walkable;
	std::string description;
	TileColor foregroundColor = TileWhite;
	TileColor backgroundColor = TileBlack;
} Tiles[] = {
	{ ' ', true, "void" },
	{ '.', true, "grass" },
	{ 'O', true, "large rock" };
};

#endif

