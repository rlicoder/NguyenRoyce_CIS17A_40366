#include "chessheader.h"

string convertNumericToAtlasCoordinates(int row, int col, char alphaCoordinates[])
{
    //declare string
    string str;
    
    //assigning string values
    str.push_back(alphaCoordinates[col]);
    str.push_back(row + 1 + '0');
    
    //returning string values
    return str;
}