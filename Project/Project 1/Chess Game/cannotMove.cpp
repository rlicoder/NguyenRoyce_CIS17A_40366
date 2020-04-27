#include "chessheader.h"

bool cannotMove(piecedata piece[], int K)
{
    //declaring flag
    bool cannotMove = true;

    //checking black king possible moves
    if (K == 4)
    {
        for (int m = 0; m < 64; m++)
        {
            if (piece[K].possible_moves[m] != -1)
            {
                cannotMove = false;
            }
        }
    }
    //checking white king possible moves
    else if (K == 12)
    {
        for (int m = 0; m < 64; m++)
        {
            if (piece[K].possible_moves[m] != -1)
            {
                cannotMove = false;
            }
        }
    }
    
    //checking all black pieces
    if (K == 4)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int m = 0; m < 64; m++)
            {
                if (piece[i].possible_moves[m] != -1)
                {
                    cannotMove = false;
                }
            }
        }
        for (int i = 24; i < 32; i++)
        {
            for (int m = 0; m < 64; m++)
            {
                if (piece[i].possible_moves[m] != -1)
                {
                    cannotMove = false;
                }
            }
        }
    }
    
    //checking all white pieces.
    else if (K == 12)
    {
        for (int i = 8; i < 24; i++)
        {
            for (int m = 0; m < 64; m++)
            {
                if (piece[i].possible_moves[m] != -1)
                {
                    cannotMove = false;
                }
            }
        }
    }
    
    return cannotMove;
}