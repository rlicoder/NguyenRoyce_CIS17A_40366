#include "chessheader.h"


main()
{
    Game game;
    vector<Piece*> piece;
    Player player;
    bool tryagain = true;
    int scount = 0;
    int icount = 0;
    
    game.initializeBoardPieces(piece);
    
    game.displayBoard();
    
    game.updateTiles(piece);
    
    
    while(!game.getGameState())
    {
        do
        {
            player.getPlayerMoveStart();

            tryagain = true;
            
            while (tryagain)
            {
                try
                {
                    game.verifyPlayerMoveStart(player.getPlayerMove(1));
                    tryagain = false;
                }
                catch(string exception)
                {
                    cout << exception << endl;
                    player.getPlayerMoveStart();
                }
            }

            player.getPlayerMoveEnd();
        }
        while (!verifyPlayerMove(game, player, piece, game.getWhiteTurn(), false, false, game.getWhiteTurn()));

        game.updateTiles(piece, player, game.getWhiteTurn(), false);

        game.displayBoard();

        game.flipWhiteTurn();

        updateGameState(game.getWhiteTurn(), game, piece);
    }
    
    for (int i = 0; i < piece.size(); i++)
    {
        delete (piece[i]);
    }
    piece.clear();
    
    
}





