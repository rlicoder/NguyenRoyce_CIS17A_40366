#include "Bishop.h"

Bishop::Bishop(bool white, int a, int b, int pieceval)
{
    this->position[0] = a;
    this->position[1] = b;
    this->captured = false;
    this->white = white;
    this->moves = 0;
    this->issupported = false;
    this->piecevalue = pieceval;
}

