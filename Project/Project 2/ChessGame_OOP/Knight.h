#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece
{
private:
    bool issupported;
public:
    Knight(bool white, int a, int b, int pieceval);

};

#endif /* KNIGHT_H */

