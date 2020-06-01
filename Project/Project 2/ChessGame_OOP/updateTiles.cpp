#include "chessheader.h"

void updateTiles(tiles board[8][8], vector<Piece*> piece)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            //board[i][j].underattackWhite = isCheck(board, piece, i, j, true , false);
            //board[i][j].underattackBlack = isCheck(board, piece, i, j, false, false);
            
            if (board[i][j].getSymbol() != ' ')
            {
                board[i][j].setOccupied(true);
                board[i][j].setOccupiedWhite(isWhite(board, i, j));
                board[i][j].setOccupiedBlack(!isWhite(board, i, j));

            }
            else if (board[i][j].getSymbol() == ' ')
            {
                board[i][j].setOccupied(false);
                board[i][j].setOccupiedWhite(false);
                board[i][j].setOccupiedBlack(false);
            }
        }
    }
}