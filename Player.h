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
	Player(const Player& player);
	~Player();
	void Move(const Board& brd, std::vector<Player>& players);
	void BuyCurrentTile(Board& brd);
	void ShowPossesions() const;
	void ReceiveRent(int rent);
	int GetPIndex() const;
	int GetBPos() const;
	int GetLastMove() const;
	int GetCurrCash() const;
	std::string GetTileName(const Board& brd) const;
	void ControlFlow(Board& brd, std::vector<Player>& everyone);
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
	bool jailed = false;
	int jail_cooldown = 0;
	int lastmove = 0;
	Dice dice;
	std::vector<Possesion>possesions;

	static constexpr int maxBPos = 39;
	static constexpr int max_jailtime = 2;
};

