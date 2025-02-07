#pragma once
#include "Dice.h"
#include "Board.h"
#include "Tile.h"
#include <string>
#include <vector>
#include <iostream>

class Player
{
public:
	Player(int n);
	~Player();
	void Move(const Board& brd, Player& enemy);
	void BuyCurrentTile(Board& brd);
	void ShowPossesions();
	void ReceiveRent(int rent);
	int GetPIndex() const;
	int GetBPos() const;
private:
	class Possesion
	{
	public:
		Possesion(Tile& tile);
		~Possesion();
		Possesion(const Possesion& pos);
		Possesion& operator=(const Possesion& pos);
		void PrintName() const;
	private:
		Tile* ownedTile = nullptr;
	};
private:
	std::string pName;
	const int pIndex;
	int boardPos = 0;
	int cash = 400;
	Dice dice;
	std::vector<Possesion>possesions;

	static constexpr int maxBPos = 39;
};

