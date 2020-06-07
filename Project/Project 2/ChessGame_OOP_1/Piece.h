#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <iostream>
#include "tiles.h"
#include <bits/stdc++.h>
using namespace std;

class Piece
{
friend class tiles;

protected:
    int moves;
    bool white;
    bool captured;
    string possible_moves[64];
    int position[2];
    int piecevalue;
public:
    int getPieceValue()
    { return this->piecevalue; }
    
    int getMoves()
    { return this->moves; }
    void setMoves(int dummy);
    
    bool getWhite()
    { return this->white; }
    void setWhite(bool dummy);
    
    bool getCaptured()
    { return this->captured; }
    void setCaptured(bool dummy);
    
    string getPossible_Moves(int val)
    { return possible_moves[val]; }
    void setPossible_Moves(string dummy, int val);
    
    int getPosition(int val)
    { return this->position[val]; }
    void setPosition(int val, int dummy);
    
    virtual bool checkMovement(tiles board[8][8], int startmoverow, int startmovecol, int endmoverow, int endmovecol, vector<Piece*>& piece, bool intentcapture)
    { 
        static int count = 0;
        cout << ++count; }
    
    virtual bool checkBlock(int startmoverow, int startmovecol, int endmoverow, int endmovecol, tiles board[8][8], vector<Piece*>& piece)
    { cout << "checkblock"; }
};

#endif /* PIECE_H */

