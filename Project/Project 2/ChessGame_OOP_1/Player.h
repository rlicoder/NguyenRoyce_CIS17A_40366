#ifndef PLAYER_H
#define PLAYER_H

#include "chessheader.h"

class Player
{
private:
    bool white;
    string name;
    string playermove[4];
    
public:
    Player(bool white, string dummyname);
    
    string getName()
    { return this->name; }
    void setName(string dummy);
    
    string getPlayerMove(int val)
    { return this->playermove[val]; }
    void setPlayerMove(int val, string dummy);
    
    bool checkAlpha();
    
    bool checkNum();

    
};

#endif /* PLAYER_H */

