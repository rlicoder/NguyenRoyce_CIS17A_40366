#include "Knight.h"
#include "tiles.h"

Knight::Knight(bool white, int a, int b, int pieceval)
{
    this->captured = false;
    this->white = white;
    this->moves = 0;
    this->issupported = false;
    this->position[0] = a;
    this->position[1] = b;
    this->piecevalue = pieceval;
}

bool Knight::checkMovement(tiles board[8][8], int startmoverow, int startmovecol, int endmoverow, int endmovecol, vector<Piece*>& piece, bool intentcapture)
{
    bool valid = false;
    
//    cout << " " << startmoverow << " " << startmovecol << " " << endmoverow << " " << endmovecol;

    if (abs(endmoverow - startmoverow) == 2 && abs(endmovecol - startmovecol) == 1)
    {
        valid = true;
    }
    else if (abs(endmoverow -startmoverow) == 1 && abs(endmovecol - startmovecol) == 2)
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
