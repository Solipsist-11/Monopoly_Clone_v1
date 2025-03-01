#define _CRTDBG_MAP_ALLOC  
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
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDERR);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);

    {
        std::ifstream inputEffects("InitEffects.txt");
        Chance chanceStack(inputEffects);
        Community communityStack(inputEffects);
        std::ifstream input("InitBoard.txt");
        Board brd{ input, chanceStack, communityStack };
        std::vector<Player> participants;
        int nParticipants = 0;
        std::cout << "Write the number of Players: ";
        std::cin >> nParticipants;
        for (int i = 0; i < nParticipants; i++)
        {
            participants.push_back(Player(i));
        }
        while (true)
        {
            std::cout << "\nPress 'b' to begin, 'l' to load a game and 'q' to close the game \n";
            char b;
            std::cin >> b;
            switch (b)
            {
            case 'b':
                while (true)
                {
                    std::cout << "You are currently at Position " << participants[0].GetBPos() << ", Tilename: " << participants[0].GetTileName(brd) << "\n";
                    std::cout << "(m)ove, (b)uy, show (p)ossessions, e(x)it, (q)uicksave \n";
                    char n;
                    std::cin >> n;
                    switch (n)
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
                    if (n == 'm' || n == 'b' || n == 'p')
                    {
                        for (int i = 1; i < nParticipants; i++)
                        {
                            participants[i].ControlFlow(brd, participants);
                            std::cout << "Player " << (i + 1) << " is currently at Position " << participants[i].GetBPos() << ", Tilename: " << participants[i].GetTileName(brd) << "\n";
                        }
                    }
                }
            case 'l':
                break;
            case 'q':
                return false;
                break;
            }
        }
    }
    _CrtDumpMemoryLeaks();
}

