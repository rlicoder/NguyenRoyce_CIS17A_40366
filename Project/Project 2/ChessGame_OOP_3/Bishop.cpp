#include "Bishop.h"

Bishop::Bishop(bool white, int a, int b, int pieceval)
{
    this->position[0] = a;
    this->position[1] = b;
    this->captured = false;
    this->white = white;
    this->moves = 0;
    this->issupported = false;
    this->piecevalue = pieceval;
    this->incheck = false;
}

bool Bishop::checkMovement(tiles board[8][8], int startmoverow, int startmovecol, int endmoverow, int endmovecol, vector<Piece*>& piece, bool intentcapture)
{
    bool valid = false;
    
//    cout << " " << startmoverow << " " << startmovecol << " " << endmoverow << " " << endmovecol;
    
    if (abs(endmoverow - startmoverow) == abs(endmovecol - startmovecol) && !this->checkBlock(startmoverow, startmovecol, endmoverow, endmovecol, board, piece))
    {
        valid = true;
    }
    
    if (endmoverow - startmoverow == 0 && endmovecol - startmovecol == 0)
    {
        valid = false;
    }
    
//    valid?cout<<"               valid":cout<<"";
//    cout << endl;
    
    return valid;
}

bool Bishop::checkBlock(int startmoverow, int startmovecol, int endmoverow, int endmovecol, tiles board[8][8], vector<Piece*>& piece)
{
    bool blocked = false;
    
    if (endmoverow - startmoverow > 0 && endmovecol - startmovecol > 0)
        {
            while (startmoverow+1 != endmoverow && !blocked)
            {
                if (board[startmoverow+1][startmovecol+1].getOccupied())
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
                if (board[startmoverow-1][startmovecol+1].getOccupied())
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
                if (board[startmoverow+1][startmovecol-1].getOccupied())
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
                if (board[startmoverow-1][startmovecol-1].getOccupied())
                {
                    blocked = true;
                }
                startmoverow--;
                startmovecol--;
            }
        }
    
    return blocked;
}

Bishop::Bishop(Bishop* obj)
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
