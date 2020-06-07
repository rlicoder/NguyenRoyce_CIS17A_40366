#include "chessheader.h"


main()
{
    Game game;
    char alphaCoordinates[8] = {'a','b','c','d','e','f','g','h'};
    vector<Piece*> piece;
    vector<Player> players;

    tiles board[8][8];
    
    initializeBoardPieces(board, piece);
    displayBoard(board, alphaCoordinates);
    updateTiles(board, piece);
    
    getPlayerInfo(players);
    
    getPlayerMoveStart(players, game);
    //verifyPlayerMoveStart();
    
    
    
    
    
    for (int i = 0; i < piece.size(); i++)
    {
        delete (piece[i]);
    }
    piece.clear();
    
    
}





