#include "chessheader.h"

bool isStalemate(piecedata piece[], bool whiteturn)
{
    //set flags
    bool stalemate = false;
    bool flag = false;
    
    //checking through all possible moves to see if any are valid
    if (!whiteturn)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int m = 0; m < 64 && !flag; m++)
            {
                if (piece[i].possible_moves[m] != -1)
                {
                    flag = true;
                }
            }
        }
        for (int i = 24; i < 32; i++)
        {
            for (int m = 0; m < 64 && !flag; m++)
            {
                if (piece[i].possible_moves[m] != -1)
                {
                    flag = true;
                }
            }
        }
        if (!flag && !piece[4].conditions.incheck)
        {
            stalemate = true;
        }
    }
    //same thing but for white
    else if (whiteturn)
    {
        for (int i = 8; i < 24; i++)
        {
            for (int m = 0; m < 64 && !flag; m++)
            {
                if (piece[i].possible_moves[m] != -1)
                {
                    flag = true;
                }
            }
        }
        if (!flag && !piece[12].conditions.incheck)
        {
            stalemate = true;
        }
    }
    
    //return flag
    return stalemate;
}