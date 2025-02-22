#pragma once
#include <string>
#include <fstream>
#include <assert.h>

class Station
{
public:
	Station(std::ifstream& input, int in_index);
	Station(const Station& stat);
	~Station();
	Station& operator=(const Station& stat);
	int GetRentCost(int enemy_owned) const;
	int GetPrice() const;
	std::string GetName() const;

private:
	std::string name;
	static constexpr int price = 200;
	int index = 0;
	int rentcosttable[4];
	bool purchased = false;
};

