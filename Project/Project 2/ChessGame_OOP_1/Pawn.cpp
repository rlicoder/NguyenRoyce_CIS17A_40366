

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
    this->doubleadvance = false;
    this->moves = 0;
    this->issupported = false;
    this->promotionvalue = -1;
    this->piecevalue = pieceval;
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
    
//    cout << " " << startmoverow << " " << startmovecol << " " << endmoverow << " " << endmovecol;
    
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
            else if (board[endmoverow-1][endmovecol].getOccupiedBlack() && piece[pieceSearchArrayPosition(endmoverow-1, endmovecol, piece)]->getMoves() == 1 && piece[pieceSearchArrayPosition(endmoverow-1, endmovecol, piece)]->getPosition(1) == 4)
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
            else if (board[endmoverow-1][endmovecol].getOccupiedBlack() && piece[pieceSearchArrayPosition(endmoverow-1, endmovecol, piece)]->getMoves() == 1 && piece[pieceSearchArrayPosition(endmoverow-1, endmovecol, piece)]->getPosition(1) == 4)
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
            else if (board[endmoverow+1][endmovecol].getOccupiedWhite() && piece[pieceSearchArrayPosition(endmoverow-1, endmovecol, piece)]->getMoves() == 1 && piece[pieceSearchArrayPosition(endmoverow-1, endmovecol, piece)]->getPosition(1) == 3)
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
            else if (board[endmoverow+1][endmovecol].getOccupiedWhite() && piece[pieceSearchArrayPosition(endmoverow-1, endmovecol, piece)]->getMoves() == 1 && piece[pieceSearchArrayPosition(endmoverow-1, endmovecol, piece)]->getPosition(1) == 3)
            {
                valid = true;
            }
        }
    }
    
    if (endmoverow - startmoverow == 0 && endmovecol - startmovecol == 0)
    {
        valid = false;
    }
    
//    valid?cout<<"                 valid":cout<<"";
//    cout << endl;
    
    return valid;
}