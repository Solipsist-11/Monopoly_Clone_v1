#include "Dice.h"

Dice::Dice()
	:
	rng( rd() ),
	d_dist(1, 6)
{
}

int Dice::DiceThrow()
{
	int d1 = d_dist(rng);
	int d2 = d_dist(rng);

	return d1 + d2;
}
