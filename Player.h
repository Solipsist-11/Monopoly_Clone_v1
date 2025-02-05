#pragma once
#include "Dice.h"
#include <string>
#include <vector>

class Player
{
public:
	Player();
	void Move();
	void BuyCurrentTile();
	void ShowPossesions();
private:
	std::string pName;
	int BoardPos = 0;
	int cash = 400;
	Dice dice;

	static constexpr int maxBPos = 39;
};

