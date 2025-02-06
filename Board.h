#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "Tile.h"


class Board
{
public:
	Board() = default;
	Board(std::ifstream& input);
	~Board();
	Board(const Board& brd);
	Board operator=(const Board& brd);
	Tile& GetCurrentTile(int index);
	Tile::Type CheckCurrentType();
private:
	static constexpr int nTiles = 40;
	Tile boardTiles[nTiles];
};

