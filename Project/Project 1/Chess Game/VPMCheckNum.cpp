#include "chessheader.h"

bool VPMCheckNum(string playermove)
{
    //declare flag
    bool numfound = false;

    // search if the number is within 0-9 range
    if(playermove[1] > 48 && playermove[1] < 57)
    {
        numfound = true;
}
    
    //return flag
    return numfound;
}
