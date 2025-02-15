#pragma once
#include "Effect.h"
#include <vector>
#include <string>
#include <fstream>

class Community
{
public:
	Community(std::ifstream& input);
private:
	static constexpr int nCommunityCards = 16;
	std::vector<Effect> communityCards;
};

