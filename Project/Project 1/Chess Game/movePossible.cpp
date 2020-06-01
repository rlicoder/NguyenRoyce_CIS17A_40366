#include "chessheader.h"

string movePossible(int a, int b, tiles board[8][8], piecedata piece[], char blackPieces[], char whitePieces[], char alphaCoordinates[], int c, bool whiteturn)
{
    //assigning integer values of the movements
    string playermove[4];
    playermove[0] = convertNumericToAtlasCoordinates(piece[c].position[0], piece[c].position[1], alphaCoordinates);
    playermove[1] = convertAtlasCoordinatesToNumeric(playermove[0], alphaCoordinates);
    playermove[2] = convertNumericToAtlasCoordinates(a, b, alphaCoordinates);
    playermove[3] = convertAtlasCoordinatesToNumeric(playermove[2], alphaCoordinates);

    //boolean if the move is possible
    bool result = verifyPlayerMove(board, blackPieces, whitePieces, playermove, piece, piece[c].conditions.white, alphaCoordinates, true, true, whiteturn);
    
    
    //returning the result to the array element
    if (!result)
    {
        return "-1";
    }
    if (result)
    {
        return playermove[3];
    }
}