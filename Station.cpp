#include "Station.h"

Station::Station(std::ifstream& input, int in_index)
{
	std::string searchindex = "[" + index;
	searchindex.append("]");

	input.seekg(0, input.beg);

	for (std::string line; std::getline(input, line); )
	{
		if (line == searchindex)
		{
			input >> name;
			for (int i : rentcosttable)
			{
				input >> i;
			}
		}
	}
}

int Station::GetRentCost(int enemyowned) const
{
	return rentcosttable[enemyowned];
}
