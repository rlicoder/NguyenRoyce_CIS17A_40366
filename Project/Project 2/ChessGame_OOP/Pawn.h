#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece
{
private:
    bool ispawn;
    bool doubleadvance;
    bool promotionvalue;
    bool issupported;
public:
    Pawn();
    Pawn(bool white, int pos, int pieceval);
    
    bool getIsPawn()
    { return this->ispawn; }
    void setIsPawn (bool dummy)
    { this->ispawn = dummy; }
    
    bool getDoubleAdvance()
    { return this->doubleadvance; }
    void setDoubleAdvance (bool dummy)
    { this->doubleadvance = dummy; }
    
    bool getPromotionValue()
    { return this->promotionvalue; }
    void setPromotionValue (bool dummy)
    { this->promotionvalue = dummy; }
    
    void testfunc(){};
    
};

#endif /* PAWN_H */

