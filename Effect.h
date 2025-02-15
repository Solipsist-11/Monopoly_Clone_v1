#pragma once
#include <string>
#include <fstream>


class Effect
{
public:
	enum class Type
	{
		MoveTo,
		MoveBy,
		SetMoneyChange,
		Renovation,
		PlayerPayOut,
		JailFree,
		RelativeMove
	};
public:
	Effect(std::ifstream& input);
	Effect::Type GetType() const;
private:
	std::string description;
	int cash_change = 0;
	int movetoby = 0;
	int renovationFee[2] = { 0, 0 };
	Type type;
};

