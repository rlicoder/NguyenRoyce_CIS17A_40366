#include "chessheader.h"

bool VPMCheckCapture(bool whiteturn, string playermove[], tiles board[8][8], bool simulation, piecedata piece[], bool realtimewhiteturn)
{
    //declare flag
    bool capturable = true;
    
    //initialize the integer representation of moves as well as the piece array position
    int startmoverow = playermove[1][1] - '0';  
    int startmovecol = playermove[1][0] - '0';
    
    int i = pieceSearchArrayPosition(startmoverow, startmovecol, piece);
    
    int endmoverow = playermove[3][1] - '0';
    int endmovecol = playermove[3][0] - '0';
    
    //check if the destination tile is occupied by same color piece
    if (whiteturn && board[endmoverow][endmovecol].white)
    {
        capturable = false;
    }
    else if (!whiteturn && board[endmoverow][endmovecol].black)
    {
        capturable = false;
    }

    //return flag
    return capturable;
}