#include "Chance.h"

Chance::Chance(std::ifstream& input)
{
	std::string line;
	std::getline(input, line);
	if (line == "[Chance]")
	{
		for (int i = 0; i < nChanceCards; i++)
		{
			chanceCards.push_back(input);
		}
	}
}
