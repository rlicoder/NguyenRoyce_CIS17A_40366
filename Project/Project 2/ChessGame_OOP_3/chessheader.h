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
#include "Player.h"
#include "Game.h"


void updateGameState(bool whiteturn, Game& game, vector<Piece*>& piece);
int pieceSearchArrayPosition(int row, int col, vector<Piece*>& piece);
bool verifyPlayerMove(Game game, Player player, vector <Piece*>& piece, bool whiteturn, bool hypo, bool simulation, bool realtimewhiteturn);

enum piecevalue {PAWN = 0, KNIGHT = 1, BISHOP = 2, KING = 3, QUEEN = 4, ROOK = 5};

#endif /* CHESSHEADER_H */

