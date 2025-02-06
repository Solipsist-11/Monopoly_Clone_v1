#include "Tile.h"

Tile::Tile(std::ifstream& input, int in_index)
	:
	index(in_index)
{
	std::string tile_init = "[" + in_index;
	tile_init.append("*]");
	for (std::string line; std::getline(input, line); )
	{
		if (line == tile_init)
		{
			int t;
			input >> t;
			type = static_cast<Type>(t);
			switch (type)
			{
			case Type::Street:
				street = new Street{ input, index };
				break;
			case Type::Station:
				station = new Station{ input, index };
				break;
			}
		}
	}
}

void Tile::Purchase(int player_index)
{
	owner = static_cast<Tile::Owner>(player_index);
}

int Tile::GetCurrentRent() const
{
	switch (type)
	{
	case Type::Street:
		return street->GetRentCost();
		break;
	case Type::Station:
		return station->GetRentCost();
	}
}
