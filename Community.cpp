#include "Community.h"

Community::Community(std::ifstream& input)
{
	std::string line;
	std::getline(input, line);
	if (line == "[Community]")
	{
		for (int i = 0; i < nCommunityCards; i++)
		{
			communityCards.push_back(input);
		}
	}
}
