#include "Pawn.h"

Pawn::Pawn(bool white, int pos, int pieceval)
{
    this->ispawn = true;
    this->captured = false;
    this->white = white;
    this->doubleadvance = false;
    this->moves = 0;
    this->issupported = false;
    this->promotionvalue = -1;
    this->piecevalue = pieceval;
    if (white)
    {
        this->position[0] = 1;
        this->position[1] = pos;
    }
    else if (!white)
    {
        this->position[0] = 6;
        this->position[1] = pos;
    }
}