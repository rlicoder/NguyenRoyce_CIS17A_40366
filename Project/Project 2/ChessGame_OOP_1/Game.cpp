#include "chessheader.h"
#include "Game.h"

Game::Game()
{
    this->whiteturn = true;
    this->gamestate = 0;
}

void Game::setGameState(int dummy)
{
    this->gamestate =  dummy;
}

void Game::flipWhiteTurn()
{
    this->whiteturn = !this->whiteturn;
}
