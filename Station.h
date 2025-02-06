#pragma once
#include <string>
#include <fstream>
#include <assert.h>

class Station
{
public:
	Station(std::ifstream& input, int in_index);
	Station(std::ifstream& input);
	int GetRentCost(int enemy_owned) const;
private:
	std::string name;
	static constexpr int purchaseprice = 200;
	int index;
	int rentcosttable[4];
	bool purchased = false;
};

