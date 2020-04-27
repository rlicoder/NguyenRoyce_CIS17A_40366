#include "chessheader.h"

bool VPMCheckPiece(string playermove, tiles board[8][8], char blackPieces[], char whitePieces[])
{
    //declare flags as well as choice tile
    bool piecefound = false;
    int movecol = playermove[0] - '0';
    int moverow = playermove[1] - '0'; 

    //check if a piece is found there, no matter the color
    for (int i = 0; i < 6 && !piecefound; i++)
    {
        if (board[moverow][movecol].symbol == blackPieces[i])
        {
            piecefound = true;
        }
        else if (board[moverow][movecol].symbol == whitePieces[i])
        {
            piecefound = true;
        }
    }
    
    //return the flag
    return piecefound;
}