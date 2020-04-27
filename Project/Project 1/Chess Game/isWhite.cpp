#include "chessheader.h"

bool isWhite(tiles board[8][8], int row, int col, char whitePieces[])
{
    //checking if the piece is white by going throuhg the white pieces array
    
    bool white = false;
    
    for (int i = 0; i < 6; i++)
    {
        if (board[row][col].symbol == whitePieces[i])
        {
            white = true;
        }
    }
    
    //returning flag
    return white;
}