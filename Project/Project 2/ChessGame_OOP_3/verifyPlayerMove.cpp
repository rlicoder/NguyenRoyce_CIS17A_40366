#include "chessheader.h"

bool verifyPlayerMove(Game game, Player player, vector <Piece*>& piece, bool whiteturn, bool hypo, bool simulation, bool realtimewhiteturn)
{
    //checkpoints
    bool checkpoints[4] = {1,0,0,1};
    
    string playermove[4];
    
    playermove[0] = player.getPlayerMove(0);
    playermove[1] = player.getPlayerMove(1);
    playermove[2] = player.getPlayerMove(2);
    playermove[3] = player.getPlayerMove(3);
    
    
    //if not simulation then the player 3 move must be assigned since its not preset
    if (!hypo)
    {
        playermove[3] = game.convertAtlasCoordinatesToNumeric(playermove[2]);
    }
    
    //integer conversions
    int startmoverow = playermove[1][1] - '0';  
    int startmovecol = playermove[1][0] - '0';
    int endmoverow = playermove[3][1] - '0';
    int endmovecol = playermove[3][0] - '0';
   
    int pos = pieceSearchArrayPosition(startmoverow, startmovecol, piece);
    
    //check capture only if destination tile is occupied
    if(game.getBoardOccupied(endmoverow, endmovecol))
    {
        checkpoints[0] = game.checkCapture(whiteturn, playermove, simulation, piece, realtimewhiteturn);
    }


    //checking movement
    checkpoints[1] = game.checkMovement(pos, startmoverow, startmovecol, endmoverow, endmovecol, piece, false);
    
    //making sure the king is not in check with a simulatio
    checkpoints[2] = game.kingNotincheck(piece, playermove, whiteturn, hypo, true);
    
    
    
    //making sure that the king doesnt move into a checked square if the king is selected
    if (pieceSearchArrayPosition(startmoverow, startmovecol, piece) == 4 && !whiteturn)
    {
        checkpoints[3] = game.KingMoveSafe(piece, endmoverow, endmovecol, whiteturn);
    }
    else if (pieceSearchArrayPosition(startmoverow, startmovecol, piece) == 12 && whiteturn)
    {
        checkpoints[3] = game.KingMoveSafe(piece, endmoverow, endmovecol, whiteturn);
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
                cout << "Your king cannot move there or is still in check!" << endl;
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