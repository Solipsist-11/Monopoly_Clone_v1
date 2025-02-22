#pragma once
#include <string>

class Utility
{
public:
	Utility(int ind);
	~Utility();
	int GetRent(int move, int nUtil) const;
	int GetPrice() const;
	std::string GetName() const;
private:
	std::string name;
	const int index;
	static constexpr int price = 150;
};

