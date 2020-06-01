#ifndef PIECE_H
#define PIECE_H

#include <string>
using namespace std;

class Piece
{
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
    
    
    
    virtual void testfunc() = 0;
};

#endif /* PIECE_H */

