#include "Player.h"

void Player::Move()
{
	int move = dice.DiceThrow();
	boardPos += move;
	
	if (boardPos > maxBPos)
	{
		boardPos -= maxBPos;
		cash += 200;
	}
}

void Player::BuyCurrentTile(Board& brd)
{
	brd.GetCurrentTile(boardPos).Purchase(pIndex);
}

int Player::GetPIndex() const
{
	return pIndex;
}

int Player::GetBPos() const
{
	return boardPos;
}
