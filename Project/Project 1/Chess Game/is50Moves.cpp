#include "chessheader.h"

bool is50Moves(int moves)
{
    //set flag
    bool draw = false;
    
    //if over 50 moves then draw
    if (moves/2 > 50)
    {
        draw = true;
    }
    
    //return flag
    return draw;
}