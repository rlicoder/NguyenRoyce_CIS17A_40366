#include "chessheader.h"

void getPlayerMoveStart(vector<Player> players, Game game)
{
    string dummy;
    
    if (game.getWhiteTurn())
    {
        cout << players[0].getName() << ": it is your move: enter the start coordinates. ex: 'e2'";
        cin >> dummy;
        players[0].setPlayerMove(0, dummy);
    }
    else if (!game.getWhiteTurn())
    {
        cout << players[1].getName() << ": it is your move: enter the start coordinates. ex: 'e2'";
        cin >> dummy;
        players[0].setPlayerMove(0, dummy);
    }

}