#include "chessheader.h"

bool isCheckmate(tiles board[8][8], piecedata piece[], char blackPieces[], char whitePieces[], char alphaCoordinates[], bool whiteturn)
{
    //flag and checkpoints
    bool checkmate = false;
    bool checkmateConditions[3] = {0,0,0};
    
    //assignment
    int i = -1;
    
    //in check flag
    if (board[piece[12].position[0]][piece[12].position[1]].underattackBlack)
    {
        checkmateConditions[0] = true;
        i=12;
    }
    else if (board[piece[4].position[0]][piece[4].position[1]].underattackWhite)
    {
        checkmateConditions[0] = true;
        i=4;
    }
    
    //return if first conditions fail as to prevent unneccessary simulation 
    if (i == -1)
    {
        return checkmate;
    }
    
    //simulation
    generatePossibleMoves(piece, board, blackPieces, whitePieces, alphaCoordinates, whiteturn);
    
    //checking if there are no moves for black to get out of check
    checkmateConditions[1] = cannotMove(piece, i);
    
    
    if (checkmateConditions[1])
    {
        checkmate = true;
    }
    
    //return flag
    return checkmate;
}