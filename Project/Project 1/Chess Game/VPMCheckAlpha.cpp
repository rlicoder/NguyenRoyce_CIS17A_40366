#include "chessheader.h"

bool VPMCheckAlpha(string playermove, char alphaCoordinates[])
{
    //declare flag
    bool alphafound = false;
    
    //search array
    for(int i = 0; i < 8 && !alphafound; i++)
    {
        if (playermove[0] == alphaCoordinates[i])
        {
            alphafound = true;
        }
    }
    
    //return flag
    return alphafound;
}