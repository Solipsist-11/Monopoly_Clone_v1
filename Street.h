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
	Street() = default;
	//Street(const Street& Street);
	//~Street();
	//Street& operator=(const Street& Street);
	void Build();
	int GetRentCost() const;
	int BuildCost();
	int GetPrice() const;
	bool GetPurchased() const;
	std::string GetName() const;
public:
	static constexpr int maxBuildings = 5;
	static constexpr int rentLevels = 6;

private:
	std::string name = "";
	Color color;
	Owner owner = Owner::None;
	int price = 0;
	bool purchased = false;
	int built_apartments = 0;
	int rentcosttable[rentLevels] = { 0, 0, 0, 0, 0, 0 };
	int buildcosttable[maxBuildings] = { 0, 0, 0, 0, 0};
	int nBuilt = 0;
	int index = 0;
};

