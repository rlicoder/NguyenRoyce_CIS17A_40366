#include "chessheader.h"

tiles copyTiles(tiles board[8][8], int i, int j)
{
    //decalre a dummy structure
    tiles copyboard;
    
    //copying the values over to copy struct
    copyboard.occupied = board[i][j].occupied;
    copyboard.white = board[i][j].white;
    copyboard.black = board[i][j].black;
    copyboard.underattackWhite = board[i][j].underattackWhite;
    copyboard.underattackBlack = board[i][j].underattackBlack;
    copyboard.symbol = board[i][j].symbol;

    //returning single struct
    return copyboard;
}