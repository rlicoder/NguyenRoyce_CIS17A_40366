#include "chessheader.h"

Player::Player(bool white, string dummyname)
{
    this->name =  dummyname;
    this->white = white;
}


void Player::setName(string dummy)
{
    this->name = dummy;
}

void Player::setPlayerMove(int val, string dummy)
{
    this->playermove[val] = dummy;
}