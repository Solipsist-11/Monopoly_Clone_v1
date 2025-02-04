#pragma once
#include <string>
#include <fstream>
#include "Tile.h"


class Board
{
public:
	Board() = default;
	~Board();
	Board(const Board& brd);
	Board operator=(const Board& brd);
private:
	Tile tile_arr[40];
};

