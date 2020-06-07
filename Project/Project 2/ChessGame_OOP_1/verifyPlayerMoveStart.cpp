//#include "chessheader.h"
//
//void verifyPlayerMoveStart()
//{
//    //checkpoints - static for recursion
//    static bool checkpoints[3] = {0,0,0};
//    
//    //checkpoints
//    checkpoints[0] = VPMCheckAlpha(playermove[0], alphaCoordinates);
//    checkpoints[1] = VPMCheckNum(playermove[0]);
//    
//    //checking if the coordinate annotation is correct
//    while(!(checkpoints[0] && checkpoints[1]))
//    {
//        if (!checkpoints[0])
//        {
//            cout << "Your alphanumerical character is incorrect";
//        }
//        else if (!checkpoints[1])
//        {
//            cout << "Your numerical value is incorrect";
//        }
//        cout << endl;
//        getPlayerMoveStart(playermove, whiteturn);
//        verifyPlayerMoveStart(playermove, whiteturn, board, blackPieces, whitePieces, alphaCoordinates, piece);
//    }
//    
//    //integer assignment for functions
//    playermove[1] = convertAtlasCoordinatesToNumeric(playermove[0], alphaCoordinates);
//    
//    //checking if a piece is selected and if its the player's piece
//    checkpoints[2] = VPMCheckPiece(playermove[1], board, blackPieces, whitePieces);
//    checkpoints[3] = VPMCheckColor(playermove[1], whiteturn, board, blackPieces, whitePieces);
//    
//    while(!(checkpoints[0] && checkpoints[1] && checkpoints[2] && checkpoints[3]))
//    {
//        if (!checkpoints[0])
//        {
//            cout << "Your alphanumerical character is incorrect";
//        }
//        else if (!checkpoints[1])
//        {
//            cout << "Your numerical value is incorrect";
//        }
//        else if (!checkpoints[2])
//        {
//            cout << "There is no piece in the tile you selected";
//        }
//        else if (!checkpoints[3])
//        {
//            cout << "The piece you selected was not yours!";
//        }
//        // if false then redo.
//        cout << endl;
//        getPlayerMoveStart(playermove, whiteturn);
//        verifyPlayerMoveStart(playermove, whiteturn, board, blackPieces, whitePieces, alphaCoordinates, piece);
//    }
//
//}