#include "chessheader.h"

int main()
{
    
    //declaration of all variables
    ifstream pieces;
    ifstream names;
    ofstream output;
    char whitePieces[6];
    char blackPieces[6];
    piecedata piece[32];
    tiles board[8][8];
    string playernames[2];
    string moveList[250];
    bool offerdraw = false;
    char alphaCoordinates[8] = {'a','b','c','d','e','f','g','h'};
    int moves = 0;
    bool whiteturn = true;
    bool resignation = false;
    char drawresponse;
    
    //0 - alphanum start
    //1 - numnum start
    //2 - alphanum end
    //3 - numnum end
    string playermove[4] = {"-1","-1","-1","-1"};
    
    
    //initialization
    readInPieceDataNames(blackPieces, whitePieces, pieces, names, playernames);
    initializeBoardPieces(board, blackPieces, whitePieces, piece);
    updateTiles(board, blackPieces, whitePieces, playermove, piece, alphaCoordinates, whiteturn, false);
    
    
    //view?
    displayBoard(board, alphaCoordinates);
    outputInstructions();
    
    
    //end conditions checker
    while(!gameEnd(resignation, whiteturn, offerdraw, piece, board, whitePieces, blackPieces, alphaCoordinates, playernames, moves))
    {
        do
        {
            //controller?
            getPlayerMoveStart(playermove, whiteturn);
            if (playermove[0] == "Resign")
            {
                resignation = true;
                continue;
            }
            else if (playermove[0] == "OfferDraw")
            {
                outputName(whiteturn, playernames);
                cout << "has offered a draw. Do you accept?(y/n) ";
                cin >> drawresponse;
                if (drawresponse == 'Y' || drawresponse == 'y')
                {
                    offerdraw = true;
                    continue;
                }
            }
            verifyPlayerMoveStart(playermove, whiteturn, board, blackPieces, whitePieces, alphaCoordinates, piece);

            getPlayerMoveEnd(playermove);
            verifyPlayerMoveEnd(board, blackPieces, whitePieces, playermove, piece, whiteturn, alphaCoordinates);
        }
        while (!resignation && !offerdraw && !verifyPlayerMove(board, blackPieces, whitePieces, playermove, piece, whiteturn, alphaCoordinates, false, false, whiteturn));
        
        //model??
        updateMoveList(moveList, moves, playermove);
        updateTiles(board, blackPieces, whitePieces, playermove, piece, alphaCoordinates, whiteturn, false);
        
        //view?
        displayBoard(board, alphaCoordinates);
        
        //switch turn
        whiteturn = !whiteturn;
    }
    //output data
    string* listptr = createMoveList(moves);
    printMoveList(listptr, moves, moveList, whiteturn, whitePieces, blackPieces);
    outputData(whitePieces, blackPieces, piece);
    delete[] listptr;
    //exit stage clockwise
    return 0;
}
