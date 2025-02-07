
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
    std::vector<Player> participants;
    int nParticipants;
    nParticipants << std::cin.get();
    for (int i = 0; i < nParticipants; i++)
    {
        participants.push_back( Player(i) );
    }

    while (true)
    {
        switch (std::cin.get())
        {
        case 'b':
            while (true)
            {
                std::cout << "You are currently at Position " << participants[1].GetBPos();
                switch (std::cin.get())
                {
                case 'm':
                    participants[1].Move(brd, participants[2]);
                    break;
                case 'b':
                    participants[1].BuyCurrentTile(brd);
                    break;
                case 'p':
                    participants[1].ShowPossesions(brd);
                    break;
                case 'x':
                    break;
                case 'q':
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

