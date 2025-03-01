#pragma once
#include <string>
#include <fstream>
#include <assert.h>

#include "Street.h"
#include "Station.h"
#include "Utility.h"
#include "Chance.h"
#include "Community.h"

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
	Tile(std::ifstream& input, int in_index, Chance& chance, Community& community);
	Tile(const Tile& tile);
	bool operator==(const Tile& tile);
	bool operator!=(const Tile& tile);
	Tile& operator=(const Tile& tile);
	~Tile();
	void Purchase(int player_index);
	int GetCurrentRent(int moves, int nSame) const;
	int GetPrice() const;
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
	Utility* utility = nullptr;
	Chance* chance = nullptr;
	Community* community = nullptr;
};

