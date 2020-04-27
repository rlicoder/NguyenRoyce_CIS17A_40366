#include "chessheader.h"

int pieceSearchArrayPosition(int row, int col, piecedata piece[])
{
    //set flag
    int position = -1;
    
    for (int i = 0; i < 32; i++)
    {
        if(piece[i].position[0] == row && piece[i].position[1] == col)
        {
            position = i;
        }
    }
    
    //returning position if found
    return position;
    
}