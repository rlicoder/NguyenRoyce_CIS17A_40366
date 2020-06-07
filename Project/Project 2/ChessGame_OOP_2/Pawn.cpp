

#include <bits/stdc++.h>
#include "Pawn.h"
#include "tiles.h"

using namespace std;
int pieceSearchArrayPosition(int row, int col, vector<Piece*>& piece);
Pawn::Pawn(bool white, int pos, int pieceval)
{
    this->ispawn = true;
    this->captured = false;
    this->white = white;
    this->moves = 0;
    this->issupported = false;
    this->piecevalue = pieceval;
    this->incheck = false;
    if (white)
    {
        this->position[0] = 1;
        this->position[1] = pos;
    }
    else if (!white)
    {
        this->position[0] = 6;
        this->position[1] = pos;
    }
}

bool Pawn::checkMovement(tiles board[8][8], int startmoverow, int startmovecol, int endmoverow, int endmovecol, vector<Piece*>& piece, bool intentcapture)
{
    bool valid = false;
    
    if (this->white)
    {
        if (endmoverow - startmoverow == 2 && endmovecol - startmovecol == 0 && !intentcapture)
        {
            if (this->getMoves() == 0 && !board[endmoverow][endmovecol].getOccupied() && !board[endmoverow-1][endmovecol].getOccupied())
            {
                //cout << "double move" <<endl;
                valid = true;
            }
        }
        //single advance
        else if (endmoverow - startmoverow == 1 && endmovecol - startmovecol == 0 && !board[endmoverow][endmovecol].getOccupied() && !intentcapture)
        {
            valid = true;
        }
        //capture
        else if (endmoverow - startmoverow == 1 && endmovecol - startmovecol == 1)
        {
            if (board[endmoverow][endmovecol].getOccupiedBlack() == true || intentcapture)
            {
                valid = true;
            }
            //enpassant
            else if (board[endmoverow-1][endmovecol].getOccupiedBlack() && piece[pieceSearchArrayPosition(endmoverow-1, endmovecol, piece)]->getMoves() == 1 && piece[pieceSearchArrayPosition(endmoverow-1, endmovecol, piece)]->getPosition(0) == 4)
            {
                valid = true;
            }

        }
        //diagonal capture
        else if (endmoverow - startmoverow == 1 && endmovecol - startmovecol == -1)
        {
            if (board[endmoverow][endmovecol].getOccupiedBlack() == true || intentcapture)
            {
                valid = true;
            }
            //enpassant
            else if (board[endmoverow-1][endmovecol].getOccupiedBlack() && piece[pieceSearchArrayPosition(endmoverow-1, endmovecol, piece)]->getMoves() == 1 && piece[pieceSearchArrayPosition(endmoverow-1, endmovecol, piece)]->getPosition(0) == 4)
            {
                valid = true;
            }
        }
    }
    
    else if (this->white == false)
    {
        if (endmoverow - startmoverow == -2 && endmovecol - startmovecol == 0 && !intentcapture)
        {
            if (this->getMoves() == 0 && !board[endmoverow][endmovecol].getOccupied() && !board[endmoverow+1][endmovecol].getOccupied())
            {
                valid = true;
            }
        }
        else if (endmoverow - startmoverow == -1 && endmovecol - startmovecol == 0 && !board[endmoverow][endmovecol].getOccupied() && !intentcapture)
        {
            valid = true;
        }
        else if (endmoverow - startmoverow == -1 && endmovecol - startmovecol == -1)
        {
            if (board[endmoverow][endmovecol].getOccupiedWhite() == true || intentcapture)
            {
                valid = true;
            }
            else if (board[endmoverow+1][endmovecol].getOccupiedWhite() && piece[pieceSearchArrayPosition(endmoverow+1, endmovecol, piece)]->getMoves() == 1 && piece[pieceSearchArrayPosition(endmoverow-1, endmovecol, piece)]->getPosition(0) == 3)
            {
                valid = true;
            }
        }
        else if (endmoverow - startmoverow == -1 && endmovecol - startmovecol == 1)
        {
            if (board[endmoverow][endmovecol].getOccupiedWhite() == true || intentcapture)
            {
                valid = true;
            }
            else if (board[endmoverow+1][endmovecol].getOccupiedWhite() && piece[pieceSearchArrayPosition(endmoverow+1, endmovecol, piece)]->getMoves() == 1 && piece[pieceSearchArrayPosition(endmoverow-1, endmovecol, piece)]->getPosition(0) == 3)
            {
                valid = true;
            }
        }
    }
    
    if (endmoverow - startmoverow == 0 && endmovecol - startmovecol == 0)
    {
        valid = false;
    }
    
    return valid;
}

Pawn::Pawn(Pawn* obj)
{
    white = obj->white;
    moves = obj->moves;
    captured = obj->captured;
    for (int i = 0; i < 64; i++)
    {
        possible_moves[i] = obj->possible_moves[i];
    }
    position[0] = obj->position[0];
    position[1] = obj->position[1];
    piecevalue = obj->piecevalue;
    issupported = obj->issupported;
    incheck = obj->incheck;
}