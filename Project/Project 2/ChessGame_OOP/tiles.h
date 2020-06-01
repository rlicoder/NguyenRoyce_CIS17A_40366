#ifndef TILES_H
#define TILES_H

class tiles
{
private:
    bool occupied;
    bool occ_white;
    bool occ_black;
    bool underattackWhite;
    bool underattackBlack;
    char symbol; 
    char whitePieces[6] = {'P','N','B','K','Q','R'};
    char blackPieces[6] = {'1','2','3','4','5','6'};
public:
    tiles();
    tiles(char sym);
    
    char getSymbol()
    { return this->symbol; }
    void setSymbol(char sym);
    
    
    bool getOccupied()
    { return this->occupied; }
    void setOccupied(bool dummy);
    
    
    bool getOccupiedWhite()
    { return this->occ_white; }
    void setOccupiedWhite(bool dummy);
    
    bool getOccupiedBlack()
    { return this->occ_black; }
    void setOccupiedBlack(bool dummy);
    
    bool getUnderAttackWhite()
    { return underattackWhite; }
    void setUnderAttackWhite(bool dummy);
    
    bool getUnderAttackBlack()
    { return underattackBlack; }
    void setUnderAttackBlack(bool dummy);
    
    char getWhitePieces(int val)
    { return whitePieces[val]; }
    
    char getBlackPieces(int val)
    { return blackPieces[val]; }
    
    
};

#endif /* TILES_H */

