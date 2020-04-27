#include "chessheader.h"

void pawnUpdate(piecedata piece[], char blackPieces[], char whitePieces[], tiles board[8][8], bool simulation)
{
    //all white pawns
    for (int i = 16; i < 32; i++)
    {
        if (piece[i].conditions.doubleadvance)
        {
            if (piece[i].counter++ == 1)
            {
                piece[i].conditions.doubleadvance = false;
            }
        }
    }

    //preventing pawn promotion during simulation
    if (!simulation)
    {
        for (int i = 16; i < 32; i++)
        {
            if(piece[i].conditions.white && piece[i].conditions.ispawn)
            {
                if (piece[i].position[0] == 7)
                {
                    pawnPromotion(piece, blackPieces, whitePieces, board, true, i);
                }
            }
            else if (!piece[i].conditions.white && piece[i].conditions.ispawn)
            {
                if (piece[i].position[0] == 0)
                {
                    pawnPromotion(piece, blackPieces, whitePieces, board, false, i);
                }
            }
        }
    }
}