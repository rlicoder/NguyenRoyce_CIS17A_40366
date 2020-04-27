#include "chessheader.h"

void pawnPromotion(piecedata piece[], char blackPieces[], char whitePieces[], tiles board[8][8], bool isWhite, int i)
{
    int pvalue;
    
    //choosing promotion piece
    cout << "1. Knight " << endl << "2. Bishop " << endl;
    cout << "4. Queen " << endl << "5. Rook" << endl;
    
    cout << "Enter the promotion value: ";
    cin >> pvalue;
    
    while (pvalue != 1 && pvalue != 2 && pvalue != 4 && pvalue != 5)
    {
        cout << "Invalid value: try again ";
        cin >> pvalue;
    }
    
    //assignment of new_i for movement and new symbol
    if(isWhite)
    {
        if (pvalue == 1)
        {
            piece[i].conditions.ispawn = false;
            board[piece[i].position[0]][piece[i].position[1]].symbol = whitePieces[KNIGHT];
            piece[i].new_i = 9;
        }
        else if (pvalue == 2)
        {
            piece[i].conditions.ispawn = false;
            board[piece[i].position[0]][piece[i].position[1]].symbol = whitePieces[BISHOP];
            piece[i].new_i = 10;
        }
        else if (pvalue == 4)
        {
            piece[i].conditions.ispawn = false;
            board[piece[i].position[0]][piece[i].position[1]].symbol = whitePieces[QUEEN];
            piece[i].new_i = 11;
        }
        else if (pvalue == 5)
        {
            piece[i].conditions.ispawn = false;
            board[piece[i].position[0]][piece[i].position[1]].symbol = whitePieces[ROOK];
            piece[i].new_i = 8;
        }
    }
    else if(!isWhite)
    {
        if (pvalue == 1)
        {
            piece[i].conditions.ispawn = false;
            board[piece[i].position[0]][piece[i].position[1]].symbol = blackPieces[KNIGHT];
            piece[i].new_i = 1;
        }
        else if (pvalue == 2)
        {
            piece[i].conditions.ispawn = false;
            board[piece[i].position[0]][piece[i].position[1]].symbol = blackPieces[BISHOP];
            piece[i].new_i = 2;
        }
        else if (pvalue == 4)
        {
            piece[i].conditions.ispawn = false;
            board[piece[i].position[0]][piece[i].position[1]].symbol = blackPieces[QUEEN];
            piece[i].new_i = 3;
        }
        else if (pvalue == 5)
        {
            piece[i].conditions.ispawn = false;
            board[piece[i].position[0]][piece[i].position[1]].symbol = blackPieces[ROOK];
            piece[i].new_i = 0;
        }
    }
}