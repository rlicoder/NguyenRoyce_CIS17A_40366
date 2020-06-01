#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{
private:
    bool issupported;
public:
    Bishop(bool white, int a, int b, int pieceval);
    void testfunc(){};
};

#endif /* BISHOP_H */

