#include "chessheader.h"

bool gameEnd(bool resignation, bool whiteturn, bool offerdraw, piecedata piece[], tiles board[8][8], char whitePieces[], char blackPieces[], char alphaCoordinates[], string playernames[], int moves)
{
    //set flag and checkpoints
    bool gameEnd = false;
    bool endConditions[6] = {0,0,0,0,0};
    
    //declare and initialize checkpoints
    endConditions[0] = isCheckmate(board, piece, blackPieces, whitePieces, alphaCoordinates, whiteturn);
    endConditions[1] = isStalemate(piece, whiteturn);
    endConditions[2] = is50Moves(moves);
    endConditions[3] = isInsufficient(piece);
    endConditions[4] = resignation;
    endConditions[5] = offerdraw;
    
    
    //check if any is true and output respective message
    if (endConditions[0])
    {
        gameEnd = true;
        cout << "Checkmate!" << endl;
        outputName(!whiteturn, playernames);
        cout << "wins the game!" << endl;
    }
    else if (endConditions[1])
    {
        gameEnd = true;
        cout << "Stalemate!" << endl;
    }
    else if (endConditions[2])
    {
        gameEnd = true;
        cout << "50 move draw declared";
    }
    else if (endConditions[3])
    {
        gameEnd = true;
        cout << "Insufficient material";
    }
    else if (endConditions[4])
    {
        gameEnd = true;
        outputName(!whiteturn, playernames);
        cout << "has resigned the game." << endl;
    }
    else if (endConditions[5])
    {
        if (offerdraw)
        {
            outputName(whiteturn, playernames);
            cout << "has accepted the draw" << endl;
            gameEnd = true;
        }
        else 
        {
            gameEnd = false;
        }
    }

    //return flag
    return gameEnd;
}


