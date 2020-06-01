#include "chessheader.h"


main()
{
    char alphaCoordinates[8] = {'a','b','c','d','e','f','g','h'};
    vector<Piece*> piece;
    bool whiteturn = true;

    tiles board[8][8];
    
    initializeBoardPieces(board, piece);
    displayBoard(board, alphaCoordinates);
    updateTiles(board, piece);
    
    //getPlayerMoveStart();
    
    
}





