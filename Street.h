#pragma once
#include <string>
#include <fstream>
#include <assert.h>

class Street
{
private:
	enum class Color
	{
		Brown,
		Blue,
		Pink,
		Orange,
		Red,
		Green,
		Violet
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
	Street(std::ifstream& input, int nStreet);
	~Street();
	Street(const Street& Street);
	Street& operator=(const Street& Street);
	void Build();
	int GetRentCost() const;
	int BuildCost();
	bool GetPurchased() const;
public:
	static constexpr int maxBuildings = 5;
	static constexpr int rentLevels = 6;

private:
	std::string name;
	Color color;
	Owner owner = Owner::None;
	int price;
	bool purchased = false;
	int built_apartments = 0;
	int rentcosttable[rentLevels];
	int buildcosttable[maxBuildings];
	int nBuilt = 0;
	int index;
};

