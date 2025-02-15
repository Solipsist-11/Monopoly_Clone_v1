#include "Effect.h"

Effect::Effect(std::ifstream& input)
{
	int typ;
	input >> typ;
	type = static_cast<Effect::Type>(typ);
	std::string line;
	switch (type)
	{
	case Effect::Type::MoveTo:
		input >> movetoby;
		std::getline(input, line);
		description = line;
		break;
	case Effect::Type::MoveBy:
		input >> movetoby;
		std::getline(input, line);
		description = line;
		break;
	case Effect::Type::SetMoneyChange:
		input >> cash_change;
		std::getline(input, line);
		description = line;
		break;
	case Effect::Type::Renovation:
		input >> renovationFee[0] >> renovationFee[1];
		std::getline(input, line);
		description = line;
		break;
	case Effect::Type::PlayerPayOut:
		input >> cash_change;
		std::getline(input, line);
		description = line;
		break;
	case Effect::Type::JailFree:
		std::getline(input, line);
		std::getline(input, line);
		description = line;
		break;
	case Effect::Type::RelativeMove:
		std::getline(input, line);
		std::getline(input, line);
		description = line;
	}
}

Effect::Type Effect::GetType() const
{
	return type;
}
