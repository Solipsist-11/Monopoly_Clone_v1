#pragma once
#include <random>

class Dice
{
public:
	Dice();
	int DiceThrow();

private:
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> d_dist;
};

