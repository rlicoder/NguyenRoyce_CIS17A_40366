#include "chessheader.h"

void outputName(bool whiteturn, string playernames[])
{
    //outputting the name of player based on color
    if (whiteturn)
    {
        cout << playernames[0] << " ";
    }
    else if (!whiteturn)
    {
        cout << playernames[1] << " ";
    }
}