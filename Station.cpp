#include "Station.h"

Station::Station(std::ifstream& input, int in_index)
	:
	index(in_index)
{
	std::string searchindex = "[";
	searchindex += std::to_string(index);
	searchindex.append("]");

	input.seekg(0, input.beg);

	for (std::string line; std::getline(input, line); )
	{
		if (line == searchindex)
		{
			input >> name;
			for (int i = 0; i < 4; i++)
			{
				input >> rentcosttable[i];
			}
			break;
		}

	}
}

Station::Station(const Station& stat)
	:
	index(stat.index),
	name(stat.name),
	rentcosttable(),
	purchased(stat.purchased)
{
	for (auto i : rentcosttable)
	{
		i = stat.rentcosttable[i];
	}
}

Station::~Station()
{
}

Station& Station::operator=(const Station& stat)
{
	index = stat.index;
	name = stat.name;
	purchased = stat.purchased;
	for (auto i : rentcosttable)
	{
		i = stat.rentcosttable[i];
	}
	return *this;
}

int Station::GetRentCost(int enemyowned) const
{
	return rentcosttable[enemyowned];
}

int Station::GetPrice() const
{
	return price;
}

std::string Station::GetName() const
{
	return name;
}
