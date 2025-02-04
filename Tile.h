#pragma once
#include <string>
#include <fstream>
#include <assert.h>

class Tile
{
private:
	enum class Type
	{
		Unique,
		Street,
		Railroad,
		Utility,
		Chance,
		CommunityChest
	};
public:
	Tile(std::ifstream& input, int nTile);
	~Tile();
	Tile(const Tile& tile);
	Tile& operator=(const Tile& tile);
	int RentCost();
	int BuildCost();

public:
	static constexpr int maxBuildings = 5;
	static constexpr int rentLevels = 6;

private:
	std::string name;
	Type type;
	int price;
	bool purchased = false;
	int built_apartments = 0;
	int rentcosttable[rentLevels];
	int buildcosttable[maxBuildings];
	int nBuilt = 0;
	int index;
};

