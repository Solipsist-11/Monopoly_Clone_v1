#include "Tile.h"

Tile::Tile(std::ifstream& input, int in_index)
	:
	index(in_index)
{
	std::string searchindex = "[";
	searchindex += std::to_string(index);
	searchindex.append("*]");
	input.seekg(input.beg);
	for (std::string line; std::getline(input, line); )
	{
		if (line == searchindex)
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
			case Type::Unique:
				break;
			}
			break;
		}
	}
}

Tile::~Tile()
{
	switch (type)
	{
	case Type::Street:
		delete street;
		street = nullptr;
		break;
	case Type::Station:
		delete station;
		station = nullptr;
		break;
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
		return station->GetRentCost(0);
	}
}

std::string Tile::GetName() const
{
	return name;
}

Tile::Type Tile::GetType() const
{
	return type;
}

Tile::Owner Tile::GetOwner() const
{
	return owner;
}
