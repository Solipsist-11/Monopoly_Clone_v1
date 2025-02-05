#include "Player.h"

void Player::Move()
{
	int move = dice.DiceThrow();
	BoardPos += move;
	
	if (BoardPos > maxBPos)
	{
		BoardPos -= maxBPos;
		cash += 200;
	}
}
