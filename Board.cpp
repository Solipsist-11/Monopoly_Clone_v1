#include "Board.h"

Board::Board(std::ifstream& input)
{
	for (int i = 0; i < nTiles; i++)
	{
		boardTiles[i] = {input, i};
	}
}

Board::~Board()
{
	for (Tile i : boardTiles)
	{
		i.~Tile();
	}
}

Tile& Board::GetCurrentTile(int index)
{
	return boardTiles[index];
}

Tile::Type Board::CheckCurrentType(int bPos) const
{
	
	return boardTiles[bPos].GetType();
}

Tile::Owner Board::CheckCurrentOwner(int bPos) const
{
	return boardTiles[bPos].GetOwner();
}

int Board::GetCurrentRent(int bPos) const
{
	return boardTiles[bPos].GetCurrentRent();
}

std::string Board::GetTileName(int bPos) const
{
	return boardTiles[bPos].GetName();
}
