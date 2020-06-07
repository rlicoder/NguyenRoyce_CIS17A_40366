#ifndef TILES_H
#define TILES_H

class tiles
{
    friend class Game;
private:
    bool occupied;
    bool occ_white;
    bool occ_black;
    bool underattackWhite;
    bool underattackBlack;
    char symbol; 

public:
    tiles();
    tiles(char sym);
    tiles(tiles &obj);
    
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
    

    
    
};

#endif /* TILES_H */

