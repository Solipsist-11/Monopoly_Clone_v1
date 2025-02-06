#include "Board.h"

Board::Board(std::ifstream& input)
{
	for (int i = 0; i < nTiles; i++)
	{
		boardTiles[i] = {input, i};
	}
}

Tile& Board::GetCurrentTile(int index)
{
	return boardTiles[index];
}
