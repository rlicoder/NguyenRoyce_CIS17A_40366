
#ifndef GAME_H
#define GAME_H

#include "tiles.h"



class Game
{
friend class tiles;
friend class Piece;
friend class Player;

private:
    bool gamestate;
    bool whiteturn;
    tiles board[8][8];
    char whitePieces[6] = {'P','N','B','K','Q','R'};
    char blackPieces[6] = {'1','2','3','4','5','6'};
    char alphaCoordinates[8] = {'a','b','c','d','e','f','g','h'};
    
    
public:
    Game();
    
    bool getGameState()
    { return this->gamestate; }
    void setGameState(bool dummy);
    
    bool getWhiteTurn()
    { return this->whiteturn; }
    void flipWhiteTurn();
    
    void displayBoard();
    
    tiles getBoard(int i, int j)
    { return board[i][j]; }
    
    char getWhitePieces(int val)
    { return whitePieces[val]; }
    
    char getBlackPieces(int val)
    { return blackPieces[val]; }
    
    char getAlphaCoordinates(int val)
    { return alphaCoordinates[val]; }
    
    void initializeBoardPieces(vector<Piece*>& piece);
    
    void updateTiles(tiles board[8][8], vector<Piece*>& piece, string playermove[], bool whiteturn, bool simulation);
    
    void updateTiles(vector<Piece*>& piece, Player player, bool whiteturn, bool simulation);
    
    void updateTiles(vector <Piece*>& piece);
    
    bool isCheck(vector<Piece*>& piece, int endmoverow, int endmovecol, bool white, bool hypo);
    
    bool isWhite(int row, int col);
    
    void verifyPlayerMoveStart(string playermove);
    
    bool checkPieceColor(string playermove);
    
    void verifyPlayerMoveEnd(string playermove);
    
    bool verifyPlayerMove(Game game, string playermove[], vector <Piece*>& piece, bool whiteturn, bool hypo, bool simulation, bool realtimewhiteturn);
    
    string convertAtlasCoordinatesToNumeric(string playermove);
    
    bool checkCapture(bool whiteturn, string playermove[], bool simulation, vector<Piece*>& piece, bool realtimewhiteturn);
    
    bool getBoardOccupied(int i, int j)
    { return board[i][j].occupied; }
    
    bool checkMovement(int pos, int startmoverow, int startmovecol, int endmoverow, int endmovecol, vector<Piece*>& piece, bool intentcapture)
    { return piece[pos]->checkMovement(board, startmoverow, startmovecol, endmoverow, endmovecol, piece, false); }
    
    bool kingNotincheck(vector<Piece*>& piece, string playermove[], bool whiteturn, bool hypo, bool simulation);
    
    void findSupports(vector<Piece*>& piece);
    
    bool KingMoveSafe(vector<Piece*>& piece, int endmoverow, int endmovecol, bool whiteturn);
    
    bool isCheck(tiles copyboard[8][8], vector<Piece*>& piece, int endmoverow, int endmovecol, bool white, bool hypo);
    
    void updateGameState();
    
    void generatePossibleMoves(vector <Piece*>& piece, bool whiteturn);
    
    string movePossible(int a, int b, vector <Piece*>& piece, int c, bool whiteturn);
    
    string convertNumericToAtlasCoordinates(int row, int col);
    
    bool isCheckmate(vector<Piece*>& piece, bool whiteturn);
    
    bool isStalemate(vector <Piece*>& piece, bool whiteturn);
    
    //bool is50Moves(moves);
    
    bool isInsufficient(vector<Piece*>& piece);
    
    bool cannotMove(vector<Piece*>& piece, int K);
    
};




#endif /* GAME_H */

