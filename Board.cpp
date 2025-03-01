#include "Board.h"
#include <iostream>

Board::Board(std::ifstream& input, Chance& chance, Community& community)
{
	for (int i = 0; i < nTiles; i++)
	{
		boardTiles[i] = Tile{ input, i, chance, community };
		Tile::Type currType = boardTiles[i].GetType();
		if (currType == Tile::Type::Station)
		{
			statList.emplace_back(i);
		}
		else if (currType == Tile::Type::Utility)
		{
			utilList.emplace_back(i);
		}
	}
}

Board::~Board()
{
	for (int i = 0; i < nTiles; i++)
	{
		boardTiles[i].~Tile();
	}
	//std::cout << "Board::Destructor was called";
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

int Board::GetCurrentRent(int bPos, int moves, int nTiles) const
{
	return boardTiles[bPos].GetCurrentRent(moves, nTiles);
}

std::string Board::GetTileName(int bPos) const
{
	return boardTiles[bPos].GetName();
}

std::vector<int> Board::GetUtilL() const
{
	return utilList;
}

std::vector<int> Board::GetStatL() const
{
	return statList;
}
