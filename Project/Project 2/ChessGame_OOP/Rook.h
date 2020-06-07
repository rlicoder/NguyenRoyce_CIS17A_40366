#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece
{
private:
    bool issupported;
public:
    Rook(bool white, int a, int b, int pieceval);

};

#endif /* ROOK_H */

