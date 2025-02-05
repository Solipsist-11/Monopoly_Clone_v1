#include "Street.h"

Street::Street(std::ifstream& input, int nStreet)
	:
	index(nStreet)
{
	std::string search_ind = "[" + index;
	search_ind.append("]");
	for (std::string line; std::getline(input, line); )
	{
		if (line == search_ind )
		{
			input >> name >> price;
			int color_int;
			input >> color_int;
			color = static_cast<Color>(color_int);
			for (int i = 0; i < rentLevels; i++)
			{
				input >> rentcosttable[i];
			}
			break;
		}
	}
}

Street::~Street()
{
}

Street::Street(const Street& Street)
	:
	name(Street.name),
	price(Street.price),
	index(Street.index)
{
	for (int i = 0; i < rentLevels; i++)
	{
		rentcosttable[i] = Street.rentcosttable[i];
	}
}

Street& Street::operator=(const Street& Street)
{
	this->name = Street.name;
	this->price = Street.price;
	this->index = Street.index;
	for (int i = 0; i < rentLevels; i++)
	{
		this->rentcosttable[i] = Street.rentcosttable[i];
	}
	return *this;
}

int Street::RentCost()
{
	assert(nBuilt >= 0 && nBuilt <= 5);
	return rentcosttable[nBuilt];
}

int Street::BuildCost()
{
	return buildcosttable[nBuilt];
}
