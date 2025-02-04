#include "Tile.h"

Tile::Tile(std::ifstream& input, int nTile)
	:
	index(nTile)
{
	std::string search_ind = "[" + index;
	search_ind.append("]");
	for (std::string line; std::getline(input, line); )
	{
		if (line == search_ind )
		{
			input >> name >> price;
			int type_int;
			input >> type_int;
			type = static_cast<Type>(type_int);
			for (int i = 0; i < rentLevels; i++)
			{
				input >> rentcosttable[i];
			}
			break;
		}
	}
}

Tile::~Tile()
{
}

Tile::Tile(const Tile& tile)
	:
	name(tile.name),
	price(tile.price),
	index(tile.index)
{
	for (int i = 0; i < rentLevels; i++)
	{
		rentcosttable[i] = tile.rentcosttable[i];
	}
}

Tile& Tile::operator=(const Tile& tile)
{
	this->name = tile.name;
	this->price = tile.price;
	this->index = tile.index;
	for (int i = 0; i < rentLevels; i++)
	{
		this->rentcosttable[i] = tile.rentcosttable[i];
	}
	return *this;
}

int Tile::RentCost()
{
	assert(nBuilt >= 0 && nBuilt <= 5);

	switch (nBuilt)
	{
	case 0:
		return rentcosttable[0];
		break;
	case 1:
		return rentcosttable[1];
		break;
	case 2:
		return rentcosttable[2];
		break;
	case 3:
		return rentcosttable[3];
		break;
	case 4:
		return rentcosttable[4];
		break;
	case 5:
		return rentcosttable[5];
		break;
	}
}
