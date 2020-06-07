#include "King.h"
#include "tiles.h"
#include <bits/stdc++.h>

King::King(bool white, int a, int b, int pieceval)
{
    this->position[0] = a;
    this->position[1] = b;
    this->captured = false;
    this->white = white;
    this->moves = 0;
    this->incheck = false;
    this->piecevalue = pieceval;
}

bool King::checkMovement(tiles board[8][8], int startmoverow, int startmovecol, int endmoverow, int endmovecol, vector<Piece*>& piece, bool intentcapture)
{
    bool valid = false;
    
//    cout << " " << startmoverow << " " << startmovecol << " " << endmoverow << " " << endmovecol;
    
    if (this->white)
    {
        if (abs(endmoverow - startmoverow) == 1 && abs(endmovecol - startmovecol) == 0)
        {
            valid = true;
        }
        else if (abs(endmoverow - startmoverow) == 0 && abs(endmovecol - startmovecol) == 1)
        {
            valid = true;
        }
        else if (abs(endmoverow - startmoverow) == 1 && abs(endmovecol - startmovecol) == 1)
        {
            valid = true;
        }
        else if (endmoverow - startmoverow == 0 && endmovecol - startmovecol == 2)
        {
            if (this->getMoves() == 0 && !board[startmoverow][startmovecol].getUnderAttackBlack() && !board[startmoverow][startmovecol+1].getUnderAttackBlack() && !board[startmoverow][startmovecol+2].getUnderAttackBlack())
            {
                if (!board[startmoverow][startmovecol+1].getOccupied() && !board[startmoverow][startmovecol+2].getOccupied())
                {
                    if (piece[15]->getMoves() == 0)
                    {
                        valid = true;
                    }
                }
            }
        }
        else if (endmoverow - startmoverow == 0 && endmovecol - startmovecol == -2)
        {
            if (this->getMoves() == 0 && !board[startmoverow][startmovecol].getUnderAttackBlack() && !board[startmoverow][startmovecol-1].getUnderAttackBlack() && !board[startmoverow][startmovecol-2].getUnderAttackBlack())
            {
                if (!board[startmoverow][startmovecol-1].getOccupied() && !board[startmoverow][startmovecol-2].getOccupied() && !board[startmoverow][startmovecol-3].getOccupied())
                {
                    if (piece[8]->getMoves() == 0)
                    {
                        valid = true;
                    }
                }
            }
        }
    }
    
    else if (this->white == false)
    {
        if (abs(endmoverow - startmoverow) == 1 && abs(endmovecol - startmovecol) == 0)
        {
            valid = true;
        }
        else if (abs(endmoverow - startmoverow) == 0 && abs(endmovecol - startmovecol) == 1)
        {
            valid = true;
        }
        else if (abs(endmoverow - startmoverow) == 1 && abs(endmovecol - startmovecol) == 1)
        {
            valid = true;
        }
        //castling
        else if (endmoverow - startmoverow == 0 && endmovecol - startmovecol == 2)
        {
            if (this->getMoves() == 0 && !board[startmoverow][startmovecol].getUnderAttackWhite() && !board[startmoverow][startmovecol+1].getUnderAttackWhite() && !board[startmoverow][startmovecol+2].getUnderAttackWhite())
            {
                if (!board[startmoverow][startmovecol+1].getOccupied() && !board[startmoverow][startmovecol+2].getOccupied())
                {
                    if (piece[7]->getMoves() == 0)
                    {
                        valid = true;
                    }
                }
            }
        }
        else if (endmoverow - startmoverow == 0 && endmovecol - startmovecol == -2)
        {
            if (this->getMoves() == 0 && !board[startmoverow][startmovecol].getUnderAttackWhite() && !board[startmoverow][startmovecol-1].getUnderAttackWhite() && !board[startmoverow][startmovecol-2].getUnderAttackWhite())
            {
                if (!board[startmoverow][startmovecol-1].getOccupied() && !board[startmoverow][startmovecol-2].getOccupied() && !board[startmoverow][startmovecol-3].getOccupied())
                {
                    if (piece[0]->getMoves() == 0)
                    {
                        valid = true;
                    }
                }
            }
        }
    }
    
    if (endmoverow - startmoverow == 0 && endmovecol - startmovecol == 0)
    {
        valid = false;
    }
    
//    valid?cout<<"               valid":cout<<"";
//    cout << endl;
    
    return valid;
}