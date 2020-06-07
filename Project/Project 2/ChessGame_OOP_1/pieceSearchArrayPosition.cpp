#include "chessheader.h"

int pieceSearchArrayPosition(int row, int col, vector<Piece*>& piece)
{
    //set flag
    int position = -1;
    
    for (int i = 0; i < 32; i++)
    {
        if(piece[i]->getPosition(0) == row && piece[i]->getPosition(1) == col)
        {
            position = i;
        }
    }
    
    //returning position if found
    return position;
    
}