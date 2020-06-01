#ifndef CHESSHEADER_H
#define CHESSHEADER_H

#include <bits/stdc++.h>

using namespace std;

#include "Piece.h"
#include "tiles.h"
#include "Knight.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Queen.h"
#include "Rook.h"
#include "King.h"

enum piecevalue {PAWN = 0, KNIGHT = 1, BISHOP = 2, KING = 3, QUEEN = 4, ROOK = 5};

void initializeBoardPieces(tiles board[8][8], vector<Piece*> piece);
void displayBoard(tiles board[8][8], char alphaCoordinates[]);
bool isWhite(tiles board[8][8], int row, int col);
void updateTiles(tiles board[8][8], vector<Piece*> piece);
bool isCheck(tiles board[8][8], vector<Piece*> piece, int endmoverow, int endmovecol, bool white, bool hypo);
int pieceSearchArrayPosition(int row, int col, vector<Piece*> piece);
bool VPMisBlocked(int i, int startmoverow, int startmovecol, int endmoverow, int endmovecol, tiles board[8][8], vector<Piece*> piece);

#endif /* CHESSHEADER_H */

