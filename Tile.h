#pragma once
#include <string>
#include <fstream>

#include "Street.h"
#include "Station.h"

class Tile
{
public:
	enum class Type
	{
		Street,
		Station,
		Utility,
		Unique,
		Chance,
		Community
	};
	enum class Owner
	{
		None,
		Player1,
		Player2,
		Player3,
		Player4
	};
public:
	Tile() = default;
	Tile(std::ifstream& input, int in_index);
	~Tile();
	void Purchase(int player_index);
	int GetCurrentRent() const;
	std::string GetName() const;
	Tile::Type GetType() const;
	Tile::Owner GetOwner() const;
private:
	int index;
	Type type;
	Owner owner = Owner::None;
	std::string name;
	Street* street = nullptr;
	Station* station = nullptr;
};

