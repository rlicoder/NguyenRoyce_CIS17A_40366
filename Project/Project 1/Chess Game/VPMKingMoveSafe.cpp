#include "chessheader.h"

bool VPMKingMoveSafe(tiles board[8][8], piecedata piece[], int endmoverow, int endmovecol, bool whiteturn)
{
    //declare flag
    bool safemove = true;
    
    //check if the destination tile is under check based on color
    if (whiteturn && board[endmoverow][endmovecol].underattackBlack)
    {
        safemove = false;
    }
    else if (!whiteturn && board[endmoverow][endmovecol].underattackWhite)
    {
        safemove = false;
    }

    //return flag
    return safemove;
}
