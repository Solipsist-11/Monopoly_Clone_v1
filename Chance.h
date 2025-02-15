#pragma once
#include "Effect.h"
#include <string>
#include <vector>
#include <fstream>

class Chance
{
public:
	Chance(std::ifstream& input);
private:
	std::vector<Effect> chanceCards;
	static constexpr int nChanceCards = 16;
};

