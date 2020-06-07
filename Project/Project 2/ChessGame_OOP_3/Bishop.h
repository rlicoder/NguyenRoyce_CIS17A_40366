#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
#include "tiles.h"
#include <bits/stdc++.h>

using namespace std;

class Bishop : public Piece
{
private:

public:
    Bishop(bool white, int a, int b, int pieceval);
    Bishop(Bishop* obj);
    
    
    virtual bool checkMovement(tiles board[8][8], int startmoverow, int startmovecol, int endmoverow, int endmovecol, vector<Piece*>& piece, bool intentcapture);
    
    bool checkBlock(int startmoverow, int startmovecol, int endmoverow, int endmovecol, tiles board[8][8], vector<Piece*>& piece);
};

#endif /* BISHOP_H */

