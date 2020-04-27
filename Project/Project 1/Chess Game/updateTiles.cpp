#include "chessheader.h"

void updateTiles(tiles board[8][8], char blackPieces[], char whitePieces[], string playermove[], piecedata piece[], char alphaCoordinates[], bool whiteturn, bool simulation)
{
    //checking if the player already resigned or if a move hasnt been made yet
    if (!(playermove[0] == "-1" || playermove[0] == "Resign" || playermove[0] == "OfferDraw"))
    {
        //integer values conversion
        int startmoverow = playermove[1][1] - '0';  
        int startmovecol = playermove[1][0] - '0';

        int endmoverow = playermove[3][1] - '0';
        int endmovecol = playermove[3][0] - '0';

        //getting the position of the pieces. if pos1 is -1 then there is no attempt to capture
        int pos1 = pieceSearchArrayPosition(endmoverow, endmovecol, piece);
        int pos2 = pieceSearchArrayPosition(startmoverow, startmovecol, piece);

        //generic captures
        if (pos1 != -1)
        {
            piece[pos1].position[0] = -1;
            piece[pos1].position[1] = -1;
            piece[pos1].conditions.captured = true;
        }
        
        //enpassants
        if (pos1 == -1 && piece[pos2].conditions.ispawn && endmoverow - startmoverow == 1 && endmovecol - startmovecol == 1)
        {
            int pos3 = pieceSearchArrayPosition(startmoverow,startmovecol+1, piece);
            piece[pos3].position[0] = -1;
            piece[pos3].position[1] = -1;
            piece[pos3].conditions.captured = true;
            board[startmoverow][startmovecol+1].symbol = ' ';
        }
        else if (pos1 == -1 && piece[pos2].conditions.ispawn && endmoverow - startmoverow == 1 && endmovecol - startmovecol == -1)
        {
            int pos3 = pieceSearchArrayPosition(startmoverow,startmovecol-1, piece);
            piece[pos3].position[0] = -1;
            piece[pos3].position[1] = -1;
            piece[pos3].conditions.captured = true;
            board[startmoverow][startmovecol-1].symbol = ' ';
        }
        else if (pos1 == -1 && piece[pos2].conditions.ispawn && endmoverow - startmoverow == -1 && endmovecol - startmovecol == 1)
        {
            int pos3 = pieceSearchArrayPosition(startmoverow,startmovecol+1, piece);
            piece[pos3].position[0] = -1;
            piece[pos3].position[1] = -1;
            piece[pos3].conditions.captured = true;
            board[startmoverow][startmovecol+1].symbol = ' ';
        }
        else if (pos1 == -1 && piece[pos2].conditions.ispawn && endmoverow - startmoverow == -1 && endmovecol - startmovecol == -1)
        {
            int pos3 = pieceSearchArrayPosition(startmoverow,startmovecol-1, piece);
            piece[pos3].position[0] = -1;
            piece[pos3].position[1] = -1;
            piece[pos3].conditions.captured = true;
            board[startmoverow][startmovecol-1].symbol = ' ';
        }
        
        //updating data
        piece[pos2].position[0] = endmoverow;
        piece[pos2].position[1] = endmovecol;
        piece[pos2].moves++;
             
        //castling
        if (pos2 == 12 && endmovecol == 6)
        {
            piece[15].position[1] = 5;
            piece[15].moves++;
            board[0][5].symbol = board[0][7].symbol;
            board[0][7].symbol = ' ';
        }
        else if (pos2 == 12 && endmovecol == 2)
        {
            piece[8].position[1] = 3;
            piece[8].moves++;
            board[0][3].symbol = board[0][0].symbol;
            board[0][0].symbol = ' ';
        }
        else if (pos2 == 4 && endmovecol == 2)
        {
            piece[0].position[1] = 3;
            piece[0].moves++;
            board[7][3].symbol = board[7][0].symbol;
            board[7][0].symbol = ' ';
        }
        else if (pos2 == 4 && endmovecol == 6)
        {
            piece[7].position[1] = 5;
            piece[7].moves++;
            board[7][5].symbol = board[7][7].symbol;
            board[7][7].symbol = ' ';
        }
        
        //updating board
        board[endmoverow][endmovecol].symbol = board[startmoverow][startmovecol].symbol;
        board[startmoverow][startmovecol].symbol = ' ';
        
        //updating pawns for double advance and promotion
        pawnUpdate(piece, blackPieces, whitePieces, board, simulation);
    }
    
    //rechecking the board and updating
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j].symbol != ' ')
            {
                board[i][j].occupied = true;
                board[i][j].white = isWhite(board, i, j, whitePieces);
                board[i][j].black = !isWhite(board, i, j, whitePieces);

            }
            else if (board[i][j].symbol == ' ')
            {
                board[i][j].occupied = false;
                board[i][j].white = false;
                board[i][j].black = false;
            }
        }
    }
    
    //rechecking all tiles that may be in check
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j].underattackWhite = isCheck(board, piece, i, j, true , false);
            board[i][j].underattackBlack = isCheck(board, piece, i, j, false, false);
        }
    }
    
    //finding pieces that are supported by their own
    findSupports(piece, board);
}