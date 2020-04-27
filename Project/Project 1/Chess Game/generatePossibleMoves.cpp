#include "chessheader.h"

void generatePossibleMoves(piecedata piece[], tiles board[8][8], char blackPieces[], char whitePieces[], char alphaCoordinates[], bool whiteturn)
{
    //set counter to zero
    int m = 0;

    //for loop to go thorough every move
    //else if statement to catch captured pieces
    for (int i = 0; i < 32; i++)
    {
        m = 0;
        if (!piece[i].conditions.captured)
        {
            for (int j = 0; j < 8; j++)
            {
                for (int k = 0; k < 8; k++)
                {
                    piece[i].possible_moves[m++] = movePossible(j, k, board, piece, blackPieces, whitePieces, alphaCoordinates, i, whiteturn);
                }
            }
        }
        else if (piece[i].conditions.captured)
        {
            for (int j = 0; j < 64; j++)
            {
                piece[i].possible_moves[j] = -1;
            }
        }
        
    }
}
