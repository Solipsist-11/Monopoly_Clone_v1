#include "Utility.h"

Utility::Utility(int ind)
    :
    index(ind)
{
}

int Utility::GetRent(int move, int nUtil) const
{
    int rent = 0;
    switch (nUtil)
    {
    case 1:
        rent = move * 4;
        break;
    case 2:
        rent = move * 10;
        break;
    }
    return rent;
}
