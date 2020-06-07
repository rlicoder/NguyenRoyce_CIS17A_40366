#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece
{
private:
    bool issupported;
public:
    Queen(bool white, int a, int b, int pieceval);

};

#endif /* QUEEN_H */

