#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
#include "tiles.h"
#include <bits/stdc++.h>

class Rook : public Piece
{
private:
    bool issupported;
public:
    Rook(bool white, int a, int b, int pieceval);
    
    virtual bool checkMovement(tiles board[8][8], int startmoverow, int startmovecol, int endmoverow, int endmovecol, vector<Piece*>& piece, bool intentcapture);

    bool checkBlock(int startmoverow, int startmovecol, int endmoverow, int endmovecol, tiles board[8][8], vector<Piece*>& piece);
};

#endif /* ROOK_H */

