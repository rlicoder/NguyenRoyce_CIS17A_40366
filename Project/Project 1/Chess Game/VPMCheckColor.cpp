#include "chessheader.h"

bool VPMCheckColor(string playermove, bool whiteturn, tiles board[8][8], char blackPieces[], char whitePieces[])
{
    //declare flag and the position of the tile
    bool colorfound = false;
    int movecol = playermove[0] - '0';
    int moverow = playermove[1] - '0'; 
    
    //cout << movecol << moverow;
    
    //search through the respective color array for the same symbol
    if (whiteturn)
    {
        for (int i = 0; i < 6; i++)
        {
            if (board[moverow][movecol].symbol == whitePieces[i])
            {
                colorfound = true;
            }
        }
    }
    else if (!whiteturn)
    {
        for (int i = 0; i < 6; i++)
        {
            if (board[moverow][movecol].symbol == blackPieces[i])
            {
                colorfound = true;
            }
        }
    }
    
    //return flag
    return colorfound;
}