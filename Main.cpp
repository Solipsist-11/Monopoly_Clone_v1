
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Board.h"
#include "Player.h"


int main()
{
    std::ifstream input("init.txt", std::ios_base::binary);
    Board brd{ input };
    Player player1;
    Player enemy1;


    while (true)
    {
        switch (std::cin.get())
        {
        case 'b':
            while (true)
            {
                std::cout << "You are currently at Position " << player1.GetBPos();
                switch (std::cin.get())
                {
                case 'm':
                    player1.Move();
                    break;
                case 'b':
                    player1.BuyCurrentTile(brd);
                    break;
                case 'p':
                    player1.ShowPossesions();
                    break;
                case 'x':
                    break;
                }

            }
        case 's':
            break;
        case 'q':
            break;
        }
    }
}

