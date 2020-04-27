#include <bits/stdc++.h>

using namespace std;

struct bools
{
    bool ispawn;
    bool captured;
    bool incheck;
    bool white;
    bool doubleadvance;
    bool issupported;
};

struct piecedata
{
    int moves;
    int position[2];
    int new_i;
    int possible_moves[64];
    int counter;
    bools conditions; 
};

struct tiles
{
    bool occupied;
    bool white;
    bool black;
    bool underattackWhite;
    bool underattackBlack;
    char symbol;
};

struct record
{
    int totalmoveswhite;
    int totalmovesblack;
};

enum piecevalue {PAWN = 0, KNIGHT = 1, BISHOP = 2, KING = 3, QUEEN = 4, ROOK = 5};


//convenience functions
string convertAtlasCoordinatesToNumeric(string playermove, char alphaCoordinates[]);
void outputName(bool whiteturn, string playername[]);
int pieceSearchArrayPosition(int row, int col, piecedata piece[]);
bool isWhite(tiles board[8][8], int row, int col, char whitePieces[]);
string convertNumericToAtlasCoordinates(int row, int col, char alphaCoordinates[]);

//basic initialization
void outputInstructions();
void displayBoard(tiles board[8][8], char alphaCoordinates[]);
void initializeBoardPieces(tiles board[8][8], char blackPieces[], char whitePieces[], piecedata piece[]);
void readInPieceDataNames(char blackPieces[], char whitePieces[], ifstream &input, ifstream &names, string playernames[]);

//choosing a piece
void getPlayerMoveStart(string playermove[4], bool whiteturn);
void verifyPlayerMoveStart(string playermove[4], bool whiteturn, tiles board[8][8], char blackPieces[], char whitePieces[], char alphaCoordinates[], piecedata piece[]);
bool VPMCheckPiece(string playermove, tiles board[8][8], char blackPieces[], char whitePieces[]);
bool VPMCheckAlpha(string playermove, char alphaCoordinates[]);
bool VPMCheckNum(string playermove);
bool VPMCheckColor(string playermove, bool whiteturn, tiles board[8][8], char blackPieces[], char whitePieces[]);

//sending a piece
void getPlayerMoveEnd(string playermove[]);
void verifyPlayerMoveEnd(tiles board[8][8], char blackPieces[], char whitePieces[], string playermove[], piecedata piece[], bool whiteturn, char alphaCoorindates[]);
bool VPMCheckMovement(tiles board[8][8], int startmoverow, int startmovecol, int endmoverow, int endmovecol, piecedata piece[], bool capture);
bool VPMisBlocked(int i, int startmoverow, int startmovecol, int endmoverow, int endmovecol, tiles board[8][8], piecedata piece[]);
bool VPMCheckCapture(bool whiteturn, string playermove[], tiles board[8][8], bool simulation, piecedata piece[], bool realtimewhiteturn);
bool VPMKingMoveSafe(tiles board[8][8], piecedata piece[], int endmoverow, int endmovecol, bool whiteturn);
bool verifyPlayerMove(tiles board[8][8], char blackPieces[8], char whitePieces[8], string playermove[], piecedata piece[], bool whiteturn, char alphaCoordinates[], bool hypo, bool simulation, bool realtimewhiteturn);
bool VPMkingNotinCheck(tiles board[8][8], piecedata piece[], string playermove[], char alphaCoordinates[], char blackPieces[], char whitePieces[], bool whiteturn, bool hypo, bool simulation);

//end condition checkers
bool gameEnd(bool resignation, bool whiteturn, bool offerdraw, piecedata piece[], tiles board[8][8], char whitePieces[], char blackPieces[], char alphaCoordinates[], string playernames[], int moves);
bool isCheckmate(tiles board[8][8], piecedata piece[], char blackPieces[], char whitePieces[], char alphaCoordinates[], bool whiteturn);
bool isStalemate(piecedata piece[], bool whiteturn);
bool is50Moves(int moves);
bool isInsufficient(piecedata piece[]);

//checkmate conditions
bool isCheck(tiles board[8][8], piecedata piece[], int endmoverow, int endmovecol, bool white, bool hypo);
bool cannotMove(piecedata piece[], int K);

//output file stream functions
void updateMoveList(string moveList[], int &moves, string playermove[]);
void printMoveList(string* listptr, int moves, string moveList[], bool whiteturn, char whitePieces[], char blackPieces[]);
string* createMoveList(int moves);
void outputData(char whitePieces[], char blackPieces[], piecedata piece[]);

//model???
void updateTiles(tiles board[8][8], char blackPieces[], char whitePieces[], string playermove[], piecedata piece[], char alphaCoordinates[], bool whiteturn, bool simulation);
void pawnUpdate(piecedata piece[], char blackPieces[], char whitePieces[], tiles board[8][8], bool simulation);
void pawnPromotion(piecedata piece[], char blackPieces[], char whitePieces[], tiles board[8][8], bool isWhite, int i);

//simulation
int movePossible(int i, int k, tiles board[8][8], piecedata piece[], char blackPieces[], char whitePieces[], char alphaCoordinates[], int c, bool whiteturn);
void generatePossibleMoves(piecedata piece[], tiles board[8][8], char blackPieces[], char whitePieces[], char alphaCoordinates[], bool whiteturn);
void findSupports(piecedata piece[], tiles board[8][8]);
tiles copyTiles(tiles board[8][8], int i, int j);