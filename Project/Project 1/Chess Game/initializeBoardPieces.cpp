#include "chessheader.h"

void initializeBoardPieces(tiles board[8][8], char blackPieces[], char whitePieces[], piecedata piece[])
{
    //setting empty space in the middle four rows
    for (int i = 2; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            //space signifies empty space
            board[i][j].symbol = ' ';
        }
    }
    
    //setting pawns
    for (int i = 0; i < 8; i++)
    {
        board[1][i].symbol = whitePieces[0];;
        board[6][i].symbol = blackPieces[0];;
    }
    
    //special pieces
    board[7][0].symbol = blackPieces[ROOK];
    board[7][7].symbol = blackPieces[ROOK];
    board[7][1].symbol = blackPieces[KNIGHT];
    board[7][6].symbol = blackPieces[KNIGHT];
    board[7][2].symbol = blackPieces[BISHOP];
    board[7][5].symbol = blackPieces[BISHOP];
    board[7][4].symbol = blackPieces[KING];
    board[7][3].symbol = blackPieces[4];
    
    board[0][7].symbol = whitePieces[ROOK];
    board[0][0].symbol = whitePieces[ROOK];
    board[0][6].symbol = whitePieces[KNIGHT];
    board[0][1].symbol = whitePieces[KNIGHT];
    board[0][5].symbol = whitePieces[BISHOP];
    board[0][2].symbol = whitePieces[BISHOP];
    board[0][4].symbol = whitePieces[KING];
    board[0][3].symbol = whitePieces[QUEEN];
    
    
    //white pawns
    for (int i = 16; i < 24; i++)
    {
        piece[i].conditions.ispawn = true;
        piece[i].conditions.captured = false;
        piece[i].conditions.incheck = false;
        piece[i].conditions.white = true;
        piece[i].position[0] = 1;
        piece[i].position[1] = i-16;
        piece[i].conditions.doubleadvance = false;
        piece[i].moves = 0;
        piece[i].new_i = -1;
        piece[i].conditions.issupported = false;
        piece[i].counter = 0;
    }
    //cout << piece[20].conditions.position[0] << piece[20].conditions.position[1] << endl;
    
    //black pawns
    for (int i = 24; i < 32; i++)
    {
        piece[i].conditions.ispawn = true;
        piece[i].conditions.captured = false;
        piece[i].conditions.incheck = false;
        piece[i].conditions.white = false;
        piece[i].position[0] = 6;
        piece[i].position[1] = i-24;
        piece[i].conditions.doubleadvance = false;
        piece[i].moves = 0;
        piece[i].new_i = -1;
        piece[i].conditions.issupported = false;
        piece[i].counter = 0;
    }
    
    //black specials
    for (int i = 0; i < 8; i++)
    {
        piece[i].conditions.ispawn = false;
        piece[i].conditions.captured = false;
        piece[i].conditions.incheck = false;
        piece[i].conditions.white = false;
        piece[i].position[0] = 7;
        piece[i].position[1] = i;
        piece[i].conditions.doubleadvance = false;
        piece[i].moves = 0;
        piece[i].new_i = -1;
        piece[i].conditions.issupported = false;
        piece[i].counter = 0;
    }
    
    //white specials
    for (int i = 8; i < 16; i++)
    {
        piece[i].conditions.ispawn = false;
        piece[i].conditions.captured = false;
        piece[i].conditions.incheck = false;
        piece[i].conditions.white = true;
        piece[i].position[0] = 0;
        piece[i].position[1] = i-8;
        piece[i].conditions.doubleadvance = false;
        piece[i].moves = 0;
        piece[i].new_i = -1;
        piece[i].conditions.issupported = false;
        piece[i].counter = 0;
    }

}