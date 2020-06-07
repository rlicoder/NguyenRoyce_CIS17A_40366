
#ifndef GAME_H
#define GAME_H


class Game
{
private:
    int gamestate;
    bool whiteturn;
    
public:
    Game();
    
    int getGameState()
    { return this->gamestate; }
    void setGameState(int dummy);
    
    bool getWhiteTurn()
    { return this->whiteturn; }
    void flipWhiteTurn();
    
    
};




#endif /* GAME_H */

