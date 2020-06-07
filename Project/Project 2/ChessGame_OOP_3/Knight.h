#ifndef KNIGHT_H
#define KNIGHT_H

#include <bits/stdc++.h>
#include "Piece.h"
#include "tiles.h"

class Knight : public Piece
{
private:

public:
    Knight(bool white, int a, int b, int pieceval);
    Knight(Knight* obj);
    
    virtual bool checkMovement(tiles board[8][8], int startmoverow, int startmovecol, int endmoverow, int endmovecol, vector<Piece*>& piece, bool intentcapture);
};

#endif /* KNIGHT_H */

