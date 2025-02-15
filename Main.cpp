
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Board.h"
#include "Player.h"
#include "Chance.h"
#include "Community.h"


int main()
{
    std::ifstream inputEffects("InitEffects.txt");
    Chance chanceStack(inputEffects);
    Community communityStack(inputEffects);
    std::ifstream input("InitBoard.txt");
    Board brd{ input, chanceStack, communityStack };
    std::vector<Player> participants;
    int nParticipants = 0;
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
                std::cout << "You are currently at Position " << participants[0].GetBPos() << ", Tilename: " << participants[0].GetTileName(brd);
                std::cout << "(m)ove, (b)uy, show (p)ossessions, e(x)it, (q)uicksave";
                switch (std::cin.get())
                {
                case 'm':
                    participants[0].Move(brd, participants);
                    break;
                case 'b':
                    participants[0].BuyCurrentTile(brd);
                    break;
                case 'p':
                    participants[0].ShowPossesions();
                    break;
                case 'x':
                    break;
                case 'q':
                    break;
                }



            }
        case 'l':
            break;
        case 'q':
            break;
            break;
        }
    }
}

