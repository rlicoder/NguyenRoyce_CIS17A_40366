#include "chessheader.h"

void Piece::setMoves(int dummy)
{
    this->moves = dummy;
}

void Piece::setWhite(bool dummy)
{
    this->white = dummy;
}

void Piece::setCaptured(bool dummy)
{
    this->captured = dummy;
}

void Piece::setPossible_Moves(string dummy, int val)
{
    this->possible_moves[val] = dummy;
}

void Piece::setPosition(int val, int dummy)
{
    this->position[val] = dummy;
}

void Piece::setIsSupported(bool dummy)
{
    this->issupported = dummy;
}

void Piece::setInCheck(bool dummy)
{
    this->incheck = dummy;
}

void Piece::addMoves(int dummy)
{
    this->moves += dummy;
}

void Piece::setPieceValue(int dummy)
{
    this->piecevalue = dummy;
}