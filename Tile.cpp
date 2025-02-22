#include "Tile.h"
#include <iostream>

Tile::Tile(std::ifstream& input, int in_index, Chance& chance, Community& community)
	:
	index(in_index)
{
	std::string searchindex = "[";
	searchindex += std::to_string(index);
	searchindex.append("*]");
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
				name = street->GetName();
				break;
			case Type::Station:
				station = new Station{ input, index };
				name = station->GetName();
				break;
			case Type::Unique:
				input >> name;
				break;
			case Type::Chance:
				this->chance = &chance;
				name = "Chance";
				break;
			case Type::Community:
				this->community = &community;
				name = "Community";
				break;
			case Type::Utility:
				utility = new Utility{ index };
				name = utility->GetName();
				break;
			}
			break;
		}
	}

}

//Tile::Tile(const Tile& tile)
//	:
//	index(tile.index),
//	owner(tile.owner),
//	type(tile.type),
//	name(tile.name),
//	street(tile.street),
//	station(tile.station),
//	utility(tile.utility),
//	chance(tile.chance),
//	community(tile.community)
//{
//}

//bool Tile::operator!=(const Tile& tile)
//{
//	return index == tile.index &&
//		owner == tile.owner &&
//		type == tile.type &&
//		name == tile.name &&
//		street == tile.street &&
//		station == tile.station &&
//		utility == tile.utility &&
//		chance == tile.chance &&
//		community == tile.community;
//}
//
//Tile& Tile::operator=(const Tile& tile)
//{
//	if (*this != tile)
//	{
//		name = tile.name;
//		owner = tile.owner;
//		type = tile.type;
//		index = tile.index;
//		switch (type)
//		{
//		case Type::Street:
//			street = new Street{*tile.street}; <--I would have assumed that the newly created objects could be initialized with the *, but without the compiler complains...
//			break;
//		case Type::Station:
//			station = new Station{*tile.station};  <--I would have assumed that the newly created objects could be initialized with the *, but without the compiler complains...
//			break;
//
//		}
//	}
//	return *this;
//}
//
//Tile::~Tile()
//{
//	delete street;
//	street = nullptr;
//	delete station;
//	station = nullptr;
//	delete utility;
// 	utility = nullptr;
//	std::cout << "Tile::Destructor was called \n";
//}

void Tile::Purchase(int player_index)
{
	owner = static_cast<Tile::Owner>(player_index);
	if (type == Type::Unique)
	{
		assert(owner == Tile::Owner::None);
	}
}

int Tile::GetCurrentRent(int moves, int nSame) const
{
	switch (type)
	{
	case Type::Street:
		return street->GetRentCost();
		break;
	case Type::Station:
		return station->GetRentCost(nSame);
		break;
	case Type::Utility:
		return utility->GetRent(moves, nSame);
		break;
	}
}

int Tile::GetPrice() const
{
	switch (type)
	{
	case Type::Street:
		return street->GetPrice();
		break;
	case Type::Station:
		return station->GetPrice();
		break;
	case Type::Utility:
		return utility->GetPrice();
		break;
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
