#include "chessheader.h"

bool verifyPlayerMove(tiles board[8][8], char blackPieces[8], char whitePieces[8], string playermove[], piecedata piece[], bool whiteturn, char alphaCoordinates[], bool hypo, bool simulation, bool realtimewhiteturn)
{
    //checkpoints
    bool checkpoints[4] = {1,0,0,1};
    
    //if not simulation then the player 3 move must be assigned since its not preset
    if (!hypo)
    {
        playermove[3] = convertAtlasCoordinatesToNumeric(playermove[2], alphaCoordinates);
    }
    
    //integer conversions
    int startmoverow = playermove[1][1] - '0';  
    int startmovecol = playermove[1][0] - '0';
    int endmoverow = playermove[3][1] - '0';
    int endmovecol = playermove[3][0] - '0';
   
    int pos = pieceSearchArrayPosition(startmoverow, startmovecol, piece);
    
    //check capture only if destination tile is occupied
    if(board[endmoverow][endmovecol].occupied)
    {
        checkpoints[0] = VPMCheckCapture(whiteturn, playermove, board, simulation, piece, realtimewhiteturn);
    }

    //checking movement
    checkpoints[1] = VPMCheckMovement(board, startmoverow, startmovecol, endmoverow, endmovecol, piece, false);
    
    //making sure the king is not in check with a simulation
    checkpoints[2] = VPMkingNotinCheck(board, piece,  playermove,  alphaCoordinates,  blackPieces,  whitePieces, whiteturn, hypo, true);
    
    
    
    //making sure that the king doesnt move into a checked square if the king is selected
    if (pieceSearchArrayPosition(startmoverow, startmovecol, piece) == 4 && !whiteturn)
    {
        checkpoints[3] = VPMKingMoveSafe(board, piece, endmoverow, endmovecol, whiteturn);
    }
    else if (pieceSearchArrayPosition(startmoverow, startmovecol, piece) == 12 && whiteturn)
    {
        checkpoints[3] = VPMKingMoveSafe(board, piece, endmoverow, endmovecol, whiteturn);
    }
    
    //validation
    if (!(checkpoints[0] && checkpoints[1] && checkpoints[2] && checkpoints[3]))
    {
        //prevent spamming the console during simulations
        if (!simulation)
        {
            //outputting whats wrong
            if (!checkpoints[0])
            {
                cout << "you cannot capture your own piece" << endl;
            }
            if (!checkpoints[1])
            {
                cout << "your movement is invalid" << endl;
            }
            if (!checkpoints[2])
            {
                cout << "Your king is under attack!" << endl;
            }
            if (!checkpoints[3])
            {
                cout << "Your king is under attack!" << endl;
            }
            cout << endl << endl;
            
            return false;
        }
        
    }
    
    else if(checkpoints[0] && checkpoints[1] && checkpoints[2])
    {
        return true;
    }
}