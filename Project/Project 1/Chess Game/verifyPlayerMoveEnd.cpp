#include "chessheader.h"

void verifyPlayerMoveEnd(tiles board[8][8], char blackPieces[], char whitePieces[], string playermove[], piecedata piece[], bool whiteturn, char alphaCoordinates[])
{
    //static for recursion
    static bool checkpoints[2] = {0,0};
    
    //check the coordinate notation
    checkpoints[0] = VPMCheckAlpha(playermove[2], alphaCoordinates);
    checkpoints[1] = VPMCheckNum(playermove[2]);
    
    while(!(checkpoints[0] && checkpoints[1]))
    {
        if (!checkpoints[0])
        {
            cout << "Your alphanumerical character is incorrect";
        }
        else if (!checkpoints[1])
        {
            cout << "Your numerical value is incorrect";
        }
        //recursion verification
        cout << endl;
        getPlayerMoveEnd(playermove);
        verifyPlayerMoveEnd(board, blackPieces, whitePieces, playermove, piece, whiteturn, alphaCoordinates);
    }
}