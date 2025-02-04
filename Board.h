#pragma once
#include <string>

class Board
{
private:
	class Tile
	{
	private:
		enum class Type
		{
			Non_purchasable,
			Purchasable
		};
		std::string name;
		int price;
		bool purchased = false;
		int built_apartments = 0;
	public:
		int RentCost();

	};

public:
private:
	Tile tile_arr[40];
};

