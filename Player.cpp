#include "Player.h"

Player::Player(int n)
	:
	pIndex(n + 1)
{
}

Player::Player(const Player& player)
	:
	pIndex(player.pIndex)
{
}

Player::~Player()
{
	for (Possesion i : possesions)
	{
		i.~Possesion();
	}
}

void Player::Move(const Board& brd, Player& enemy)
{
	assert(boardPos >= 0);

	if (!jailed)
	{
		int move = dice.DiceThrow();
		boardPos += move;
	}
	else
	{
		jail_cooldown--;
		if (jail_cooldown == 0)
		{
			jailed = false;
		}
	}
	
	if (boardPos > maxBPos)
	{
		boardPos -= (maxBPos + 1);
		cash += 200;
	}
	if (brd.CheckCurrentType(boardPos) != Tile::Type::Chance &&
		brd.CheckCurrentType(boardPos) != Tile::Type::Community &&
		brd.CheckCurrentType(boardPos) != Tile::Type::Unique)
	{
		if (brd.CheckCurrentOwner(boardPos) != static_cast<Tile::Owner>(pIndex))
		{
			int rent = brd.GetCurrentRent(boardPos);
			cash -= rent;
			enemy.ReceiveRent(rent);
		}
	}
	else
	{
		switch (brd.CheckCurrentType(boardPos))
		{
		case Tile::Type::Unique:
			switch (boardPos) 
			{
			case 4:
				cash -= 200;
				break;
			case 10:
				break;
			case 20:
				break;
			case 30:
				boardPos = 10;
				jailed = true;
				jail_cooldown = 2;
				break;
			case 38:
				cash -= 100;
				break;
			}
			break;
		case Tile::Type::Chance:
			break;
		case Tile::Type::Community:
			break;
		}
	}
}

void Player::BuyCurrentTile(Board& brd)
{
	brd.GetCurrentTile(boardPos).Purchase(pIndex);
	possesions.push_back(Possesion{ brd.GetCurrentTile(boardPos) });
}

void Player::ShowPossesions()
{
	std::cout << "You currently posses the following properties:\n";
	for (Possesion i : possesions)
	{
		i.PrintName();
		std::cout << "\n";
	}
}

void Player::ReceiveRent(int rent)
{
	cash += rent;
}

int Player::GetPIndex() const
{
	return pIndex;
}

int Player::GetBPos() const
{
	return boardPos;
}

Player::Possesion::Possesion(Tile& tile)
	:
	ownedTile(&tile)
{
}

Player::Possesion::~Possesion()
{
	delete ownedTile;
	ownedTile = nullptr;
}

Player::Possesion::Possesion(const Possesion& pos)
	:
	ownedTile(pos.ownedTile)
{
}

Player::Possesion& Player::Possesion::operator=(const Possesion& pos)
{
	if (this != &pos)
	{
		delete ownedTile;
		ownedTile = nullptr;
		ownedTile = pos.ownedTile;
	}
	return *this;
}

void Player::Possesion::PrintName() const
{
	std::cout << ownedTile->GetName();
}
