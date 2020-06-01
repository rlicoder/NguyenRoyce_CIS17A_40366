#include "Knight.h"

Knight::Knight(bool white, int a, int b, int pieceval)
{
    this->captured = false;
    this->white = white;
    this->moves = 0;
    this->issupported = false;
    this->position[0] = a;
    this->position[1] = b;
    this->piecevalue = pieceval;
}
