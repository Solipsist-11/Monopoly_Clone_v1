#include "Street.h"

Street::Street(std::ifstream& input, int nStreet)
	:
	index(nStreet)
{
	std::string searchindex = "[";
	searchindex += std::to_string(index);
	searchindex.append("]");
	for (std::string line; std::getline(input, line); )
	{
		if (line == searchindex)
		{
			int color_int;
			input >> name >> color_int >> price;
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
	color(Street.color),
	price(Street.price),
	index(Street.index),
	owner(Street.owner)
{
	for (int i = 0; i < rentLevels; i++)
	{
		rentcosttable[i] = Street.rentcosttable[i];
	}
}

//Street& Street::operator=(const Street& Street)
//{
//	name = Street.name;
//	price = Street.price;
//	index = Street.index;
//	for (int i = 0; i < rentLevels; i++)
//	{
//		rentcosttable[i] = Street.rentcosttable[i];
//	}
//	return *this;
//}

void Street::Build()
{
	if (nBuilt >= 0 && nBuilt < maxBuildings && purchased)
	{
		nBuilt++;
	}
	else
	{
		std::cout << "Building is not (yet) possible";
	}
}

int Street::GetRentCost() const
{
	assert(nBuilt >= 0 && nBuilt <= 5);
	return rentcosttable[nBuilt];
}

int Street::BuildCost()
{
	return buildcosttable[nBuilt];
}

int Street::GetPrice() const
{
	return price;
}

bool Street::GetPurchased() const
{
	return purchased;
}

std::string Street::GetName() const
{
	return name;
}
