#include "chessheader.h"

void updateTiles(tiles board[8][8], vector<Piece*>& piece)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
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
    
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j].setUnderAttackWhite(isCheck(board, piece, i, j, true , false));
//            if (board[i][j].getUnderAttackWhite())
//            {
//                cout << i << "  " << j << " is under attack by white\n";
//            }
            
            board[i][j].setUnderAttackBlack(isCheck(board, piece, i, j, false, false));
//            if (board[i][j].getUnderAttackBlack())
//            {
//                cout << i << "  " << j << " is under attack by black\n";
//            }
        }
    }
}