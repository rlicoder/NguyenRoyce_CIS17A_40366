#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include "tiles.h"

class Pawn : public Piece
{
private:
    bool ispawn;
    
public:
    Pawn();
    Pawn(bool white, int pos, int pieceval);
    Pawn(Pawn* obj);
    
    bool getIsPawn()
    { return this->ispawn; }
    void setIsPawn (bool dummy)
    { this->ispawn = dummy; }
    
//    bool getDoubleAdvance()
//    { return this->doubleadvance; }
//    void setDoubleAdvance (bool dummy)
//    { this->doubleadvance = dummy; }
//    
//    bool getPromotionValue()
//    { return this->promotionvalue; }
//    void setPromotionValue (bool dummy)
//    { this->promotionvalue = dummy; }
    
    virtual bool checkMovement(tiles board[8][8], int startmoverow, int startmovecol, int endmoverow, int endmovecol, vector<Piece*>& piece, bool intentcapture);

    
};

#endif /* PAWN_H */

