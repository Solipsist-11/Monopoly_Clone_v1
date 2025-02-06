#pragma once
#include <string>
#include <fstream>

#include "Street.h"
#include "Station.h"

class Tile
{
public:
	Tile() = default;
	Tile(std::ifstream& input, int in_index);
	void Purchase(int player_index);
	int GetCurrentRent() const;
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
private:
	enum class Owner
	{
		None,
		Player1,
		Player2,
		Player3,
		Player4
	};
private:
	int index;
	Type type;
	Owner owner = Owner::None;

	Street* street = nullptr;
	Station* station = nullptr;
};

