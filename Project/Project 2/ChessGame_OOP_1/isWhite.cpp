#include "chessheader.h"

bool isWhite(tiles board[8][8], int row, int col)
{
    //checking if the piece is white by going throuhg the white pieces array
    
    bool white = false;
    
    for (int i = 0; i < 6; i++)
    {
        if (board[row][col].getSymbol() == board[0][0].getWhitePieces(i))
        {
            white = true;
        }
    }
    
    //returning flag
    return white;
}