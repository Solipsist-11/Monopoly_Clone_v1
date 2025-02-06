#pragma once
#include "Dice.h"
#include "Board.h"
#include "Tile.h"

#include <string>
#include <vector>

class Player
{
public:
	Player();
	void Move();
	void BuyCurrentTile(Board& brd);
	void ShowPossesions();
	int GetPIndex() const;
	int GetBPos() const;
private:
	std::string pName;
	const int pIndex;
	int boardPos = 0;
	int cash = 400;
	Dice dice;
	std::vector<Tile>possesions;

	static constexpr int maxBPos = 39;
};

