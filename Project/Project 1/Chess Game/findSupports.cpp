#include "chessheader.h"

void findSupports(piecedata piece[], tiles board[8][8])
{
    //going through every white piece
    for (int i = 8; i < 24; i++)
    {
        for (int j = 8; j < 24; j++)
        {
            if (!piece[j].conditions.captured && !piece[i].conditions.captured)
            {
                if (VPMCheckMovement(board, piece[i].position[0], piece[i].position[1], piece[j].position[0], piece[j].position[1], piece, true))
                {
                    piece[j].conditions.issupported = true;
                }
            }
        }
    }
    
    //going through first part black pieces
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (!piece[j].conditions.captured && !piece[i].conditions.captured)
            {
                if (VPMCheckMovement(board, piece[i].position[0], piece[i].position[1], piece[j].position[0], piece[j].position[1], piece, true))
                {
                    piece[j].conditions.issupported = true;
                }
            }
        }
        for (int j = 24; j < 32; j++)
        {
            if (!piece[j].conditions.captured && !piece[i].conditions.captured)
            {
                if (VPMCheckMovement(board, piece[i].position[0], piece[i].position[1], piece[j].position[0], piece[j].position[1], piece, true))
                {
                    piece[j].conditions.issupported = true;
                }
            }
        }
    }
    
    //second part of black pieces
    for (int i = 24; i < 32; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (!piece[j].conditions.captured && !piece[i].conditions.captured)
            {
                if (VPMCheckMovement(board, piece[i].position[0], piece[i].position[1], piece[j].position[0], piece[j].position[1], piece, true))
                {
                    piece[j].conditions.issupported = true;
                }
            }
        }
        for (int j = 24; j < 32; j++)
        {
            if (!piece[j].conditions.captured && !piece[i].conditions.captured)
            {
                if (VPMCheckMovement(board, piece[i].position[0], piece[i].position[1], piece[j].position[0], piece[j].position[1], piece, true))
                {
                    piece[j].conditions.issupported = true;
                }
            }
        }
    }
}