#ifndef KING_H
#define KING_H

#include "Piece.h"
#include "tiles.h"
#include <bits/stdc++.h>

class King : public Piece
{
private:
    bool incheck;
public:
    King(bool white, int a, int b, int pieceval);
    
    bool getInCheck()
    { return this->incheck; }
    void setInCheck(bool dummy);
    
    virtual bool checkMovement(tiles board[8][8], int startmoverow, int startmovecol, int endmoverow, int endmovecol, vector<Piece*>& piece, bool intentcapture);
};

#endif /* KING_H */

