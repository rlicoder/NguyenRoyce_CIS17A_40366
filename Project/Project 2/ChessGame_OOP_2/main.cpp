#include "chessheader.h"


main()
{
    Game game;
    vector<Piece*> piece;
    Player player;
    List<string> stringmoves(500);
    List<int> intmoves(500);
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
        
        stringmoves.insert(player.getPlayerMove(0), scount++);
        stringmoves.insert(player.getPlayerMove(2), scount++);

        intmoves.insert(stoi(player.getPlayerMove(1)), icount++);
        intmoves.insert(stoi(player.getPlayerMove(3)), icount++);
    }
    
    intmoves.setSize(icount);
    stringmoves.setSize(scount);
            
    cout << "Move Lists : ";
    cout << stringmoves;
    cout << endl << endl;
    cout << intmoves << endl;
    cout << endl;
    
    
    for (int i = 0; i < piece.size(); i++)
    {
        delete (piece[i]);
    }
    piece.clear();
    
    
}





