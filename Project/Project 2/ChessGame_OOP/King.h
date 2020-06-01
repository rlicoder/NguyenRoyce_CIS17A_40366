#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece
{
private:
    bool incheck;
public:
    King(bool white, int a, int b, int pieceval);
   
    void testfunc(){};
    
    bool getInCheck()
    { return this->incheck; }
    void setInCheck(bool dummy);
};

#endif /* KING_H */

