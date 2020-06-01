#include "chessheader.h"

bool VPMisBlocked(int i, int startmoverow, int startmovecol, int endmoverow, int endmovecol, tiles board[8][8], vector<Piece*> piece)
{
    //set flag
    bool blocked = false;
    
    //queen is not checked, rather her movement is determined then sent as either bishop or rook i value

    //bishops
    //must split into four diagonals and check every tile leading up to destination tile
    if (i == 2 || i == 5 || i == 10 || i == 13)
    {
        if (endmoverow - startmoverow > 0 && endmovecol - startmovecol > 0)
        {
            while (startmoverow+1 != endmoverow && !blocked)
            {
                if (board[startmoverow+1][startmovecol+1]->getOccupied())
                {
                    blocked = true;
                }
                startmoverow++;
                startmovecol++;
            }
        }
        else if (endmoverow - startmoverow < 0 && endmovecol - startmovecol > 0)
        {
            while (startmoverow-1 != endmoverow && !blocked)
            {
                if (board[startmoverow-1][startmovecol+1]->getOccupied())
                {
                    blocked = true;
                }
                startmoverow--;
                startmovecol++;
            }
        }
        else if (endmoverow - startmoverow > 0 && endmovecol - startmovecol < 0)
        {
            while (startmoverow+1 != endmoverow && !blocked)
            {
                if (board[startmoverow+1][startmovecol-1]->getOccupied())
                {
                    blocked = true;
                }
                startmoverow++;
                startmovecol--;
            }
        }
        else if (endmoverow - startmoverow < 0 && endmovecol - startmovecol < 0)
        {
            while (startmoverow-1 != endmoverow && !blocked)
            {
                if (board[startmoverow-1][startmovecol-1]->getOccupied())
                {
                    blocked = true;
                }
                startmoverow--;
                startmovecol--;
            }
        }
    }
    
    //rooks
    //must split into 4 lines and check every tile leading up to destination tile
    else if (i == 0 || i == 7 || i == 8 || i == 15)
    {
        if (endmoverow - startmoverow == 0 && endmovecol - startmovecol > 0)
        {
            while (startmovecol+1 != endmovecol && !blocked)
            {
                if (board[startmoverow][startmovecol+1]->getOccupied())
                {
                    blocked = true;
                }
                startmovecol++;
            }
        }
        else if (endmoverow - startmoverow == 0 && endmovecol - startmovecol < 0)
        {
            while (startmovecol-1 != endmovecol && !blocked)
            {
                if (board[startmoverow][startmovecol-1]->getOccupied())
                {
                    blocked = true;
                }
                startmovecol--;
            }
        }
        else if (endmoverow - startmoverow > 0 && endmovecol - startmovecol == 0)
        {
            while (startmoverow+1 != endmoverow && !blocked)
            {
                if (board[startmoverow+1][startmovecol]->getOccupied())
                {
                    blocked = true;
                }
                startmoverow++;
            }
        }
        else if (endmoverow - startmoverow < 0 && endmovecol - startmovecol == 0)
        {
            while (startmoverow-1 != endmoverow && !blocked)
            {
                if (board[startmoverow-1][startmovecol]->getOccupied())
                {
                    blocked = true;
                }
                startmoverow--;
            }
        }
    }

    return blocked;
}