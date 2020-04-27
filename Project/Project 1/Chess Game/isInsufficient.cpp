#include "chessheader.h"

bool isInsufficient(piecedata piece[])
{
    //set counters for minor pieces
    int whiteknights = 0;
    int whitebishops = 0;
    int blackknights = 0;
    int blackbishops = 0;
    
    int whiteminor;
    int blackminor;
    
    //checking if any pawn is alive, if so, not insufficient
    for (int i = 16; i < 32; i++)
    {
        if (!piece[i].conditions.captured)
        {
            if (piece[i].conditions.ispawn)
            {
                return false;
            }
            else if (piece[i].new_i != -1)
            {
                if (piece[i].new_i == 1 || piece[i].new_i == 2)
                {
                    if (piece[i].conditions.white)
                    {
                        whiteminor++;
                    }
                    else if (!piece[i].conditions.white)
                    {
                        blackminor++;
                    }
                }
                else if (piece[i].new_i == 4 || piece[i].new_i == 0)
                {
                    return false;
                }
            }
        }
    }
    
    //if any rook exists, then false;
    if (!piece[0].conditions.captured || !piece[7].conditions.captured || !piece[8].conditions.captured || !piece[15].conditions.captured)
    {
        return false;
    }
    //if any queen exists, then false;
    else if (!piece[3].conditions.captured || !piece[11].conditions.captured)
    {
        return false;
    }
    
    //counting all alive minor pieces
    for (int i = 1; i < 15; i++)
    {
        if (!piece[i].conditions.captured)
        {
            if (i == 1 || i == 6)
            {
                blackknights++;
            }
            else if ( i == 2 || i == 5)
            {
                blackbishops++;
            }
            else if (i == 9 || i == 14)
            {
                whiteknights++;
            }
            else if (i == 10 || i == 13)
            {
                whitebishops++;
            }
        }
    }
    
    //totaling pieces
    whiteminor = whiteknights + whitebishops;
    blackminor = blackknights + blackbishops;
    
    //if the function gets to here, then no pawns, rooks, or queens exist
    
    //no minor pieces
    if (whiteminor + blackminor == 0)
    {
        return true;
    }
    //if white has one knight and no other pieces exist
    if ((whiteknights == 1 && blackknights == 0) && (blackbishops == 0 && whitebishops == 0))
    {
        return true;
    }
    //if black has one knight and no other pieces exist
    if ((whiteknights == 0 && blackknights == 1) && (blackbishops == 0 && whitebishops == 0))
    {
        return true;
    }
    //if white has 2 knights and no other pieces exist
    if ((whiteknights == 2 && blackknights == 0) && (blackbishops == 0 && whitebishops == 0))
    {
        return true;
    }
    //if black has 2 knights and no other pieces exist
    if ((whiteknights == 0 && blackknights == 2) && (blackbishops == 0 && whitebishops == 0))
    {
        return true;
    }
    //one minor piece each side, checkmate cannot be forced, but it possible
    if (blackminor == 1 && whiteminor == 1)
    {
        return true;
    }
}