#include "tiles.h"

void tiles::setSymbol(char sym)
{
    this->symbol = sym;
}

tiles::tiles(char sym)
{
    this->symbol = sym;
}

tiles::tiles()
{
    this->occupied = false;
    this->occ_white = false;
    this->occ_black = false;
    this->underattackWhite = false;
    this->underattackBlack = false;
    this->symbol = false;
}

void tiles::setOccupiedWhite(bool dummy)
{
    this->occ_white = dummy;
}

void tiles::setOccupiedBlack(bool dummy)
{
    this->occ_black = dummy;
}

void tiles::setOccupied(bool dummy)
{
    this->occupied = dummy;
}

void tiles::setUnderAttackBlack(bool dummy)
{
    this->underattackBlack = dummy;
}

void tiles::setUnderAttackWhite(bool dummy)
{
    this->underattackWhite = dummy;
}

