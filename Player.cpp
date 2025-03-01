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

void Player::Move(const Board& brd, std::vector<Player>& players)
{
	assert(boardPos >= 0 && boardPos <= 39);

	if (!jailed)
	{
		int move = dice.DiceThrow();
		lastmove = move;
		boardPos += move;
	}
	else
	{
		jail_cooldown--;
		std::cout << "Player " << pIndex << " will be in Jail for " << jail_cooldown << " more turns \n";
		if (jail_cooldown == 0)
		{
			jailed = false;
			std::cout << "Player " << pIndex << " is out of Jail!\n";
		}
	}
	
	if (boardPos > maxBPos)
	{
		boardPos -= (maxBPos + 1);
		cash += 200;
		std::cout << "Player " << pIndex << " received 200$ for passing Go \n";
	}
	if (brd.CheckCurrentType(boardPos) != Tile::Type::Chance &&
		brd.CheckCurrentType(boardPos) != Tile::Type::Community &&
		brd.CheckCurrentType(boardPos) != Tile::Type::Unique)
	{
		Tile::Owner currOwner = brd.CheckCurrentOwner(boardPos);
		if (currOwner != static_cast<Tile::Owner>(pIndex) && currOwner != Tile::Owner::None)
		{
			int nSameTiles = 0;
			if ( brd.CheckCurrentType(boardPos) == Tile::Type::Station)
			{
				for (auto i : brd.GetStatL())
				{
					if (brd.CheckCurrentOwner(i) == currOwner)
					{
						nSameTiles++;
					}
				}
			}
			else if (brd.CheckCurrentType(boardPos) == Tile::Type::Utility)
			{
				for (auto i : brd.GetUtilL())
				{
					if (brd.CheckCurrentOwner(i) == currOwner)
					{
						nSameTiles++;
					}
				}
			}

			int rent = brd.GetCurrentRent(boardPos, lastmove, nSameTiles);
			cash -= rent;
			players[int(currOwner) - 1].ReceiveRent(rent);
			std::cout << "Player " << pIndex << " payed " << rent << "$" << " to Player " << int(currOwner) << "\n";
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
				std::cout << "Player " << pIndex << " had to pay 200$ in Income Tax \n";
				break;
			case 10:
				break;
			case 20:
				break;
			case 30:
				boardPos = 10;
				jailed = true;
				jail_cooldown = max_jailtime;
				std::cout << "Player " << pIndex << "went to Jail (for 2 turns)! \n";
				break;
			case 38:
				cash -= 100;
				std::cout << "Player " << pIndex << " had to pay 100$ in Luxury Tax \n";
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
	const int tilePrice = brd.GetCurrentTile(boardPos).GetPrice();
	if (brd.CheckCurrentType(boardPos) != Tile::Type::Chance &&
		brd.CheckCurrentType(boardPos) != Tile::Type::Community &&
		brd.CheckCurrentType(boardPos) != Tile::Type::Unique &&
		brd.CheckCurrentOwner(boardPos) == Tile::Owner::None && 
		tilePrice <= cash)
	{
		cash -= tilePrice;
		brd.GetCurrentTile(boardPos).Purchase(pIndex);
		possesions.push_back(Possesion{ brd.GetCurrentTile(boardPos) });
		std::cout << "Player " << pIndex << " bought " << brd.GetTileName(boardPos) << " for " << tilePrice << "$\n";
		std::cout << "Player " << pIndex << "has " << cash << "$ still left. \n";
	}
	else
	{
		std::cout << "Purchase could not be completed \n";
	}
}

void Player::ShowPossesions() const
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

int Player::GetLastMove() const
{
	return lastmove;
}

int Player::GetCurrCash() const
{
	return cash;
}

std::string Player::GetTileName(const Board& brd) const
{
	return brd.GetTileName(boardPos);
}

Player::Possesion::Possesion(Tile& tile)
	:
	ownedTile(&tile)
{
}

Player::Possesion::~Possesion()
{
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

void Player::ControlFlow(Board& brd, std::vector<Player>& everyone)
{
	Move(brd, everyone);
	int currCash = GetCurrCash();
	if (currCash <= 100)
	{
	}
	else
	{
		if (brd.CheckCurrentType(boardPos) != Tile::Type::Chance &&
			brd.CheckCurrentType(boardPos) != Tile::Type::Community &&
			brd.CheckCurrentType(boardPos) != Tile::Type::Unique &&
			brd.CheckCurrentOwner(boardPos) == Tile::Owner::None &&
			brd.GetCurrentTile(boardPos).GetPrice() <= currCash)
		{
			BuyCurrentTile(brd);
		}
	}
}
