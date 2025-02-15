#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "Tile.h"
#include "Chance.h"
#include "Community.h"


class Board
{
public:
	Board() = default;
	Board(std::ifstream& input, Chance& chance, Community& community);
	~Board();
	Board(const Board& brd) = delete; // only one Board is used
	Board operator=(const Board& brd) = delete; // only one Board is used
	Tile& GetCurrentTile(int index);
	Tile::Type CheckCurrentType(int bPos) const;
	Tile::Owner CheckCurrentOwner(int bPos) const;
	int GetCurrentRent(int bPos) const;
	std::string GetTileName(int bPos) const;
private:
	static constexpr int nTiles = 40;
	Tile boardTiles[nTiles];
};

