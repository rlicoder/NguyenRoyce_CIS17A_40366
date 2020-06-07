#include "chessheader.h"

void updateGameState(bool whiteturn, Game& game, vector<Piece*>& piece)
{
    //set flag and checkpoints
    bool gameEnd = false;
    bool endConditions[3] = {0,0,0};
    game.generatePossibleMoves(piece, whiteturn);
    
    endConditions[0] = game.isCheckmate(piece, whiteturn);
    endConditions[1] = game.isStalemate(piece, whiteturn);
    endConditions[2] = game.isInsufficient(piece);

    
    
    //check if any is true and output respective message
    if (endConditions[0])
    {
        gameEnd = true;
        cout << "Checkmate!" << endl;
        !whiteturn?cout<<"White":cout<<"Black";
        cout << " wins the game! << endl" << endl;
    }
    else if (endConditions[1])
    {
        gameEnd = true;
        cout << "Stalemate! << endl" << endl;
    }
    else if (endConditions[2])
    {
        gameEnd = true;
        cout << "Insufficient material" << endl;
    }

    //return flag
    game.setGameState(gameEnd);
}