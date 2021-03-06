#include "chessheader.h"

bool isCheck(tiles board[8][8], vector<Piece*> piece, int endmoverow, int endmovecol, bool white, bool hypo)
{
    bool incheck = false;
    
    //checking if any white piece can come to the destination tile for check
    if (white && !hypo)
    {
        for (int i = 8; i < 24 && !incheck; i++)
        {
            if (piece[i]->getCaptured() == false)
            {
                incheck = VPMCheckMovement(board, piece[i]->getPosition[0], piece[i]->getPosition[1], endmoverow, endmovecol, piece, true);
            }
        }
    }
    
    //same thing but for all black pieces
    else if (!white  && !hypo)
    {
        for (int i = 0; i < 8 && !incheck; i++)
        {
            if (piece[i]->getCaptured() == false)
            {
                incheck = VPMCheckMovement(board, piece[i]->getPosition[0], piece[i]->getPosition[1], endmoverow, endmovecol, piece, true);
            }
        }
        for (int i = 24; i < 32 && !incheck; i++)
        {
            if (piece[i]->getCaptured() == false && !incheck)
            {
                incheck = VPMCheckMovement(board, piece[i]->getPosition[0], piece[i]->getPosition[1], endmoverow, endmovecol, piece, true);
            }
        }
    }

    return incheck;
}