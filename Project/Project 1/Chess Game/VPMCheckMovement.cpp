#include "chessheader.h"

bool VPMCheckMovement(tiles board[8][8], int startmoverow, int startmovecol, int endmoverow, int endmovecol, piecedata piece[], bool intentcapture)
{
    //declare flag and piecearray position
    bool valid = false;

    
    int i = pieceSearchArrayPosition(startmoverow, startmovecol, piece);

    //check for promoted pawn
    if (piece[i].new_i != -1)
    {
        i = piece[i].new_i;
    }
    //first if will be determined by position
    //white pawn
    if (i >= 16 && i <= 23)
    {
        //double advance
        if (endmoverow - startmoverow == 2 && endmovecol - startmovecol == 0 && !intentcapture)
        {
            if (piece[i].moves == 0 && !board[endmoverow][endmovecol].occupied && !board[endmoverow-1][endmovecol].occupied)
            {
                //cout << "double move" <<endl;
                valid = true;
                piece[i].conditions.doubleadvance = true;
            }
        }
        //single advance
        else if (endmoverow - startmoverow == 1 && endmovecol - startmovecol == 0 && !board[endmoverow][endmovecol].occupied && !intentcapture)
        {
            valid = true;
        }
        //capture
        else if (endmoverow - startmoverow == 1 && endmovecol - startmovecol == 1)
        {
            if (board[endmoverow][endmovecol].black == true || intentcapture)
            {
                valid = true;
            }
            //enpassant
            else if (board[endmoverow-1][endmovecol].black && piece[pieceSearchArrayPosition(endmoverow-1, endmovecol, piece)].conditions.doubleadvance)
            {
                valid = true;
            }
            
        }
        //diagonal capture
        else if (endmoverow - startmoverow == 1 && endmovecol - startmovecol == -1)
        {
            if (board[endmoverow][endmovecol].black == true || intentcapture)
            {
                valid = true;
            }
            //enpassant
            else if (board[endmoverow-1][endmovecol].black && piece[pieceSearchArrayPosition(endmoverow-1, endmovecol, piece)].conditions.doubleadvance)
            {
                valid = true;
            }
        }
    }
    
    //same format as the white pawn, except "forward" movement is negative
    //black pawn
    else if (i >=24)
    {
        if (endmoverow - startmoverow == -2 && endmovecol - startmovecol == 0 && !intentcapture)
        {
            if (piece[i].moves == 0 && !board[endmoverow][endmovecol].occupied && !board[endmoverow+1][endmovecol].occupied)
            {
                valid = true;
                piece[i].conditions.doubleadvance = true;
            }
        }
        else if (endmoverow - startmoverow == -1 && endmovecol - startmovecol == 0 && !board[endmoverow][endmovecol].occupied && !intentcapture)
        {
            valid = true;
        }
        else if (endmoverow - startmoverow == -1 && endmovecol - startmovecol == -1)
        {
            if (board[endmoverow][endmovecol].white == true || intentcapture)
            {
                valid = true;
            }
            else if (board[endmoverow+1][endmovecol].white && piece[pieceSearchArrayPosition(endmoverow+1, endmovecol, piece)].conditions.doubleadvance)
            {
                valid = true;
            }
        }
        else if (endmoverow - startmoverow == -1 && endmovecol - startmovecol == 1)
        {
            if (board[endmoverow][endmovecol].white == true || intentcapture)
            {
                valid = true;
            }
            else if (board[endmoverow+1][endmovecol].white && piece[pieceSearchArrayPosition(endmoverow+1, endmovecol, piece)].conditions.doubleadvance)
            {
                valid = true;
            }
        }
    }
    
    //knight movement, no need for block checks
    //all knights
    else if (i == 1 || i == 6 || i == 9 || i == 14)
    {
        if (abs(endmoverow - startmoverow) == 2 && abs(endmovecol - startmovecol) == 1)
        {
            valid = true;
        }
        else if (abs(endmoverow -startmoverow) == 1 && abs(endmovecol - startmovecol) == 2)
        {
            valid = true;
        }
    }
    
    //bishop movement is defined by same horizontal and vertical movement and not blocked
    //all bishops
    else if (i == 2 || i == 5 || i == 10 || i == 13)
    {
        if (abs(endmoverow - startmoverow) == abs(endmovecol - startmovecol) && !VPMisBlocked(i, startmoverow, startmovecol, endmoverow, endmovecol, board, piece))
        {
            valid = true;
        }
    }
    
    //rooks are defined as either the horizontal or vertical movement being zero. block is checked as well
    //all rooks
    else if (i == 0 || i == 7 || i == 8 || i == 15)
    {
        if (endmoverow - startmoverow == 0 || endmovecol - startmovecol == 0)
        {
            if (!VPMisBlocked(i, startmoverow, startmovecol, endmoverow, endmovecol, board, piece))
            {
                valid = true;
            }
        }
    }
    
    //king movement is just single tile at a time
    //black king
    else if (i == 4)
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
            if (piece[i].moves == 0 && !board[startmoverow][startmovecol].underattackWhite && !board[startmoverow][startmovecol+1].underattackWhite && !board[startmoverow][startmovecol+2].underattackWhite)
            {
                if (!board[startmoverow][startmovecol+1].occupied && !board[startmoverow][startmovecol+2].occupied)
                {
                    if (piece[pieceSearchArrayPosition(7,7,piece)].moves == 0)
                    {
                        valid = true;
                    }
                }
            }
        }
        else if (endmoverow - startmoverow == 0 && endmovecol - startmovecol == -2)
        {
            if (piece[i].moves == 0 && !board[startmoverow][startmovecol].underattackWhite && !board[startmoverow][startmovecol-1].underattackWhite && !board[startmoverow][startmovecol-2].underattackWhite)
            {
                if (!board[startmoverow][startmovecol-1].occupied && !board[startmoverow][startmovecol-2].occupied && !board[startmoverow][startmovecol-3].occupied)
                {
                    if (piece[pieceSearchArrayPosition(7,0,piece)].moves == 0)
                    {
                        valid = true;
                    }
                }
            }
        }
    }
    
    //same as black king
    //white king
    else if (i == 12)
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
            if (piece[i].moves == 0 && !board[startmoverow][startmovecol].underattackBlack && !board[startmoverow][startmovecol+1].underattackBlack && !board[startmoverow][startmovecol+2].underattackBlack)
            {
                if (!board[startmoverow][startmovecol+1].occupied && !board[startmoverow][startmovecol+2].occupied)
                {
                    if (piece[pieceSearchArrayPosition(0,7,piece)].moves == 0)
                    {
                        valid = true;
                    }
                }
            }
        }
        else if (endmoverow - startmoverow == 0 && endmovecol - startmovecol == -2)
        {
            if (piece[i].moves == 0 && !board[startmoverow][startmovecol].underattackBlack && !board[startmoverow][startmovecol-1].underattackBlack && !board[startmoverow][startmovecol-2].underattackBlack)
            {
                if (!board[startmoverow][startmovecol-1].occupied && !board[startmoverow][startmovecol-2].occupied && !board[startmoverow][startmovecol-3].occupied)
                {
                    if (piece[pieceSearchArrayPosition(0,0,piece)].moves == 0)
                    {
                        valid = true;
                    }
                }
            }
        }
    }
    
    //uses the same logic as the bishop and rook
    //both queens
    else if (i == 3 || i == 11)
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
        else if (endmoverow - startmoverow == 0 || endmovecol - startmovecol == 0)
        {
            if (!VPMisBlocked(0, startmoverow, startmovecol, endmoverow, endmovecol, board, piece))
            {
                valid = true;
            }
        }
        else if (abs(endmoverow - startmoverow) == abs(endmovecol - startmovecol))
        {
            if (!VPMisBlocked(2, startmoverow, startmovecol, endmoverow, endmovecol, board, piece))
            {
                valid = true;
            }
        }
    }
    if (endmoverow - startmoverow == 0 && endmovecol - startmovecol == 0)
    {
        valid = false;
    }

    //return flag
    return valid;
}