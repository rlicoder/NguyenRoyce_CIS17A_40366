#include "chessheader.h"

void initializeBoardPieces(tiles board[8][8], vector<Piece*>& piece)
{
    for (int i = 2; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            //space signifies empty space
            board[i][j].setSymbol(' ');
        }
    }
    
    for (int i = 0; i < 8; i++)
    {
        board[1][i].setSymbol(board[0][0].getWhitePieces(PAWN));
        board[6][i].setSymbol(board[0][0].getBlackPieces(PAWN));
    }
    
    board[7][0].setSymbol(board[0][0].getBlackPieces(ROOK));
    board[7][7].setSymbol(board[0][0].getBlackPieces(ROOK));
    board[7][1].setSymbol(board[0][0].getBlackPieces(KNIGHT));
    board[7][6].setSymbol(board[0][0].getBlackPieces(KNIGHT));
    board[7][2].setSymbol(board[0][0].getBlackPieces(BISHOP));
    board[7][5].setSymbol(board[0][0].getBlackPieces(BISHOP));
    board[7][4].setSymbol(board[0][0].getBlackPieces(KING));
    board[7][3].setSymbol(board[0][0].getBlackPieces(QUEEN));
    
    board[0][7].setSymbol(board[0][0].getWhitePieces(ROOK));
    board[0][0].setSymbol(board[0][0].getWhitePieces(ROOK));
    board[0][6].setSymbol(board[0][0].getWhitePieces(KNIGHT));
    board[0][1].setSymbol(board[0][0].getWhitePieces(KNIGHT));
    board[0][5].setSymbol(board[0][0].getWhitePieces(BISHOP));
    board[0][2].setSymbol(board[0][0].getWhitePieces(BISHOP));
    board[0][4].setSymbol(board[0][0].getWhitePieces(KING));
    board[0][3].setSymbol(board[0][0].getWhitePieces(QUEEN));
    
    piece.push_back(new Rook(false, 7, 0, ROOK));
    piece.push_back(new Knight(false, 7, 1, KNIGHT));
    piece.push_back(new Bishop(false, 7, 2, BISHOP));
    piece.push_back(new Queen(false, 7, 3, QUEEN));
    piece.push_back(new King(false, 7, 4, KING));
    piece.push_back(new Bishop(false, 7, 5, BISHOP));
    piece.push_back(new Knight(false, 7, 6, KNIGHT));
    piece.push_back(new Rook(false, 7, 7, ROOK));
    
    piece.push_back(new Rook(true, 0, 0, ROOK));
    piece.push_back(new Knight(true, 0, 1, KNIGHT));
    piece.push_back(new Bishop(true, 0, 2, BISHOP));
    piece.push_back(new Queen(true, 0, 3, QUEEN));
    piece.push_back(new King(true, 0, 4, KING));
    piece.push_back(new Bishop(true, 0, 5, BISHOP));
    piece.push_back(new Knight(true, 0, 6, KNIGHT));
    piece.push_back(new Rook(true, 0, 7, ROOK));
    
    //white pawns
    for (int i = 0; i < 8; i++)
    {
        piece.push_back(new Pawn(true, i, PAWN));
        
    }
    
    //black pawns
    for (int i = 0; i < 8; i++)
    {
        piece.push_back(new Pawn(false, i, PAWN));
    }
   

}