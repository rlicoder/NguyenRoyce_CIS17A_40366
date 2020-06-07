#include "chessheader.h"

bool VPMkingNotinCheck(tiles board[8][8], piecedata piece[], string playermove[], char alphaCoordinates[], char blackPieces[], char whitePieces[], bool whiteturn, bool hypo, bool simulation)
{
    //declaring copy array of structs for simulation
    tiles copyboard[8][8];
    piecedata copypiece[32];
    
    //copying over the data from original
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            copyboard[i][j] = copyTiles(board, i, j);
        }
    }
    
    //direct copying piece data array
    for (int i = 0; i < 32; i++)
    {
        copypiece[i].conditions.ispawn = piece[i].conditions.ispawn;
        copypiece[i].conditions.doubleadvance = piece[i].conditions.doubleadvance;
        copypiece[i].conditions.white = piece[i].conditions.white;
        copypiece[i].conditions.incheck = piece[i].conditions.incheck;
        copypiece[i].conditions.captured = piece[i].conditions.captured;
        copypiece[i].position[0] = piece[i].position[0];
        copypiece[i].position[1] = piece[i].position[1];
        copypiece[i].moves = piece[i].moves;
        copypiece[i].new_i = piece[i].new_i;
    
}
    
    //simulation with copied data
    updateTiles(copyboard, blackPieces, whitePieces, playermove, copypiece, alphaCoordinates, whiteturn, true);
    
    //declaring integer values of movements
    int startmoverow = playermove[1][1] - '0';  
    int startmovecol = playermove[1][0] - '0';
    int endmoverow = playermove[3][1] - '0';
    int endmovecol = playermove[3][0] - '0';
    
    //getting position values
    int pos1 = pieceSearchArrayPosition(startmoverow, startmovecol, piece);
    int pos2 = pieceSearchArrayPosition(endmoverow, endmovecol, piece);
    
    //checking if the king is trying to attack a supported piece
    if (pos1 == 4 || pos1 == 12)
    {
        if (board[endmoverow][endmovecol].occupied)
        {
            if (copypiece[pos2].conditions.issupported)
            {
                return false;
            }
        }
    }
    
    
    
    if (whiteturn)
    {
        return !copyboard[copypiece[12].position[0]][copypiece[12].position[1]].underattackBlack;
    }
    
    else if (!whiteturn)
    {
        return !copyboard[piece[4].position[0]][copypiece[4].position[1]].underattackWhite;
    }
    
    
}
