#include "chessheader.h"

void updateMoveList(string moveList[], int &moves, string playermove[])
{
    //static for consisitent counter between function calls
    static int i = 0;
    //assignment of moves
    moveList[i++] = playermove[0];
    moveList[i++] = playermove[2];
    
    //removing garbage data since it may have not gotten overided
    if (playermove[0] == "Resign" || playermove[0] == "OfferDraw")
    {
        moveList[i-1] = " ";
    }
    //incrementing moves
    moves++;
}