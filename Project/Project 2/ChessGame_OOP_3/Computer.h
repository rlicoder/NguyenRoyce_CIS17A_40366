#include "chessheader.h"

class Computer 
{
private:
    string computermove[4];
public:
    virtual void determineMove() = 0;
    
    virtual void setMove() = 0;
    
    virtual void executeMove() = 0;
};