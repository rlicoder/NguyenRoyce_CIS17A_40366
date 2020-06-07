#ifndef PLAYER_H
#define PLAYER_H

#include "chessheader.h"

class Player
{
    friend class Game;
private:
    string playermove[4];
    
public:
    Player();
    
    string getPlayerMove(int val)
    { return this->playermove[val]; }
    void setPlayerMove(int val, string dummy);
    
    bool checkAlpha(string playermove);
    
    bool checkNum(string playermove);
    
    void getPlayerMoveStart();
    
    void verifyPlayerMoveStart();
    
    string convertAtlasCoordinatesToNumeric(string playermove);
    
    void getPlayerMoveEnd();
    
    void verifyPlayerMoveEnd();
    
    friend istream &operator >> (istream &strm, Player &obj)
    {
        cout << "Alphanumeric representation of the start move: ";
        strm >> obj.playermove[0];
        
        cout << "Integer representation of the start move: ";
        strm >> obj.playermove[1];
        
        cout << "Alphanumeric representation of the end move: ";
        strm >> obj.playermove[2];
        
        cout << "Integer representation of the end move: ";
        strm >> obj.playermove[3];
    }

};

#endif /* PLAYER_H */

