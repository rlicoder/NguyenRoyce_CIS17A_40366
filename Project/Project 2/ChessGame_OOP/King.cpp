#include "King.h"

King::King(bool white, int a, int b, int pieceval)
{
    this->position[0] = a;
    this->position[1] = b;
    this->captured = false;
    this->white = white;
    this->moves = 0;
    this->incheck = false;
    this->piecevalue = pieceval;
}