#include "chessheader.h"
#include "Game.h"

Game::Game()
{
    this->whiteturn = true;
    this->gamestate = false;
}

void Game::setGameState(bool dummy)
{
    gamestate = dummy;
}

void Game::flipWhiteTurn()
{
    this->whiteturn = !this->whiteturn;
}

void Game::displayBoard()
{
    //displaying the board using a nested for loop
    cout << "    ---------------------------------" << endl;
    for(int i = 7; i > -1; i--)
    {
        cout << i+1 << "   | ";
        for(int j = 0; j < 8; j++)
        {
            cout << board[i][j].getSymbol() /*<< i << j*/ << " | ";
        }
        cout << endl << "    ---------------------------------" << endl;
    }
    cout << endl << "      ";
    //displaying the coordinates
    for (int i = 0; i < 8; i++)
    {
        cout << this->getAlphaCoordinates(i) << "   ";
    }
    
    cout << endl << endl << endl << endl;
}

void Game::initializeBoardPieces(vector<Piece*>& piece)
{
    for (int i = 2; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            //space signifies empty space
            board[i][j].setSymbol(' ');
        }
    }
    
    for (int i = 0; i < 8; i++)
    {
        board[1][i].setSymbol(this->getWhitePieces(PAWN));
        board[6][i].setSymbol(this->getBlackPieces(PAWN));
    }
    
    board[7][0].setSymbol(this->getBlackPieces(ROOK));
    board[7][7].setSymbol(this->getBlackPieces(ROOK));
    board[7][1].setSymbol(this->getBlackPieces(KNIGHT));
    board[7][6].setSymbol(this->getBlackPieces(KNIGHT));
    board[7][2].setSymbol(this->getBlackPieces(BISHOP));
    board[7][5].setSymbol(this->getBlackPieces(BISHOP));
    board[7][4].setSymbol(this->getBlackPieces(KING));
    board[7][3].setSymbol(this->getBlackPieces(QUEEN));
    
    board[0][7].setSymbol(this->getWhitePieces(ROOK));
    board[0][0].setSymbol(this->getWhitePieces(ROOK));
    board[0][6].setSymbol(this->getWhitePieces(KNIGHT));
    board[0][1].setSymbol(this->getWhitePieces(KNIGHT));
    board[0][5].setSymbol(this->getWhitePieces(BISHOP));
    board[0][2].setSymbol(this->getWhitePieces(BISHOP));
    board[0][4].setSymbol(this->getWhitePieces(KING));
    board[0][3].setSymbol(this->getWhitePieces(QUEEN));
    
    piece.push_back(new Rook(false, 7, 0, ROOK));
    piece.push_back(new Knight(false, 7, 1, KNIGHT));
    piece.push_back(new Bishop(false, 7, 2, BISHOP));
    piece.push_back(new Queen(false, 7, 3, QUEEN));
    piece.push_back(new King(false, 7, 4, KING));
    piece.push_back(new Bishop(false, 7, 5, BISHOP));
    piece.push_back(new Knight(false, 7, 6, KNIGHT));
    piece.push_back(new Rook(false, 7, 7, ROOK));
    
    piece.push_back(new Rook(true, 0, 0, ROOK));
    piece.push_back(new Knight(true, 0, 1, KNIGHT));
    piece.push_back(new Bishop(true, 0, 2, BISHOP));
    piece.push_back(new Queen(true, 0, 3, QUEEN));
    piece.push_back(new King(true, 0, 4, KING));
    piece.push_back(new Bishop(true, 0, 5, BISHOP));
    piece.push_back(new Knight(true, 0, 6, KNIGHT));
    piece.push_back(new Rook(true, 0, 7, ROOK));
    
    //white pawns
    for (int i = 0; i < 8; i++)
    {
        piece.push_back(new Pawn(true, i, PAWN));
        
    }
    
    //black pawns
    for (int i = 0; i < 8; i++)
    {
        piece.push_back(new Pawn(false, i, PAWN));
    }
   
    
}

void Game::updateTiles(tiles copyboard[8][8], vector<Piece*>& copypiece, string playermove[], bool whiteturn, bool simulation)
{
    if (!(playermove[0] == "-1" || playermove[0] == "Resign" || playermove[0] == "OfferDraw"))
    {
        //integer values conversion
        int startmoverow = playermove[1][1] - '0';  
        int startmovecol = playermove[1][0] - '0';

        int endmoverow = playermove[3][1] - '0';
        int endmovecol = playermove[3][0] - '0';

        //getting the position of the pieces. if pos1 is -1 then there is no attempt to capture
        int pos1 = pieceSearchArrayPosition(endmoverow, endmovecol, copypiece);
        int pos2 = pieceSearchArrayPosition(startmoverow, startmovecol, copypiece);

        //generic captures
        if (pos1 != -1)
        {
            copypiece[pos1]->setPosition(0, -1);
            copypiece[pos1]->setPosition(1, -1);
            copypiece[pos1]->setCaptured(true);
        }
        
         //enpassants
        if (pos1 == -1 && copypiece[pos2]->getPieceValue() == 0 && endmoverow - startmoverow == 1 && endmovecol - startmovecol == 1 && copyboard[endmoverow-1][endmovecol].getOccupied())
        {
            int pos3 = pieceSearchArrayPosition(startmoverow,startmovecol+1, copypiece);
            copypiece[pos3]->setPosition(0, -1);
            copypiece[pos3]->setPosition(1, -1);
            copypiece[pos3]->setCaptured(true);
            copyboard[startmoverow][startmovecol+1].symbol = ' ';
        }
        else if (pos1 == -1 && copypiece[pos2]->getPieceValue() == 0 && endmoverow - startmoverow == 1 && endmovecol - startmovecol == -1 && copyboard[endmoverow-1][endmovecol].getOccupied())
        {
            int pos3 = pieceSearchArrayPosition(startmoverow,startmovecol-1, copypiece);
            copypiece[pos3]->setPosition(0, -1);
            copypiece[pos3]->setPosition(1, -1);
            copypiece[pos3]->setCaptured(true);
            copyboard[startmoverow][startmovecol-1].symbol = ' ';
        }
        else if (pos1 == -1 && copypiece[pos2]->getPieceValue() == 0 && endmoverow - startmoverow == -1 && endmovecol - startmovecol == 1 && copyboard[endmoverow+1][endmovecol].getOccupied())
        {
            int pos3 = pieceSearchArrayPosition(startmoverow,startmovecol+1, copypiece);
            copypiece[pos3]->setPosition(0, -1);
            copypiece[pos3]->setPosition(1, -1);
            copypiece[pos3]->setCaptured(true);
            copyboard[startmoverow][startmovecol+1].symbol = ' ';
        }
        else if (pos1 == -1 && copypiece[pos2]->getPieceValue() == 0 && endmoverow - startmoverow == -1 && endmovecol - startmovecol == -1 && copyboard[endmoverow+1][endmovecol].getOccupied())
        {
            int pos3 = pieceSearchArrayPosition(startmoverow,startmovecol-1, copypiece);
            copypiece[pos3]->setPosition(0, -1);
            copypiece[pos3]->setPosition(1, -1);
            copypiece[pos3]->setCaptured(true);
            copyboard[startmoverow][startmovecol-1].symbol = ' ';
        }
        
        
             
        //castling
        if (pos2 == 12 && endmovecol == 6 && copypiece[pos2]->getMoves() == 0)
        {
            copypiece[15]->setPosition(1, 5);
            copypiece[15]->addMoves(1);
            copyboard[0][5].symbol = copyboard[0][7].symbol;
            copyboard[0][7].symbol = ' ';
        }
        else if (pos2 == 12 && endmovecol == 2 && copypiece[pos2]->getMoves() == 0)
        {
            copypiece[8]->setPosition(1, 3);
            copypiece[8]->addMoves(1);
            copyboard[0][3].symbol = copyboard[0][0].symbol;
            copyboard[0][0].symbol = ' ';
        }
        else if (pos2 == 4 && endmovecol == 2 && copypiece[pos2]->getMoves() == 0)
        {
            copypiece[0]->setPosition(1, 3);
            copypiece[0]->addMoves(1);
            copyboard[7][3].symbol = copyboard[7][0].symbol;
            copyboard[7][0].symbol = ' ';
        }
        else if (pos2 == 4 && endmovecol == 6 && copypiece[pos2]->getMoves() == 0)
        {
            copypiece[7]->setPosition(1, 5);
            copypiece[7]->addMoves(1);
            copyboard[7][5].symbol = copyboard[7][7].symbol;
            copyboard[7][7].symbol = ' ';
        }

        
        //updating data
        copypiece[pos2]->setPosition(0, endmoverow);
        copypiece[pos2]->setPosition(1, endmovecol);
        copypiece[pos2]->addMoves(1);

        //updating board

        
        copyboard[endmoverow][endmovecol].symbol = copyboard[startmoverow][startmovecol].symbol;
        copyboard[startmoverow][startmovecol].symbol = ' ';
        
        
        //updating pawns for double advance and promotion
//        pawnUpdate(piece, blackPieces, whitePieces, board, simulation);
    }
    
    
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (copyboard[i][j].getSymbol() != ' ')
            {
                copyboard[i][j].setOccupied(true);
                copyboard[i][j].setOccupiedWhite(this->isWhite(i, j));
                copyboard[i][j].setOccupiedBlack(!this->isWhite(i, j));

            }
            else if (copyboard[i][j].getSymbol() == ' ')
            {
                copyboard[i][j].setOccupied(false);
                copyboard[i][j].setOccupiedWhite(false);
                copyboard[i][j].setOccupiedBlack(false);
            }
        }
    }
    
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            copyboard[i][j].setUnderAttackWhite(this->isCheck(copyboard, copypiece, i, j, true , false));
//            if (board[i][j].getUnderAttackWhite())
//            {
//                cout << i << "  " << j << " is under attack by white\n";
//            }
            
            copyboard[i][j].setUnderAttackBlack(this->isCheck(copyboard, copypiece, i, j, false, false));
//            if (board[i][j].getUnderAttackBlack())
//            {
//                cout << i << "  " << j << " is under attack by black\n";
//            }
        }
    }
    
    this->findSupports(copypiece); 
}

bool Game::isCheck(vector<Piece*>& piece, int endmoverow, int endmovecol, bool white, bool hypo)
{
    bool incheck = false;
    
    //checking if any white piece can come to the destination tile for check
    if (white && !hypo)
    {
        for (int i = 8; i < 24 && !incheck; i++)
        {
            if (piece[i]->getCaptured() == false)
            {
//                cout << "piece " << i;
                incheck = piece[i]->checkMovement(board, piece[i]->getPosition(0), piece[i]->getPosition(1), endmoverow, endmovecol, piece, true);
                
//                if (incheck)
//                {
//                    cout << endmoverow << " "  << endmovecol << "is under attack by " << i << endl;
//                }
            }
        }
    }
    
    //same thing but for all black pieces
    else if (!white  && !hypo)
    {
        for (int i = 0; i < 8 && !incheck; i++)
        {
//            cout << "piece " << i;
            if (piece[i]->getCaptured() == false)
            {
                incheck = piece[i]->checkMovement(board, piece[i]->getPosition(0), piece[i]->getPosition(1), endmoverow, endmovecol, piece, true);
            }
        }
        for (int i = 24; i < 32 && !incheck; i++)
        {
//            cout << "piece " << i;
            if (piece[i]->getCaptured() == false && !incheck)
            {
                incheck = piece[i]->checkMovement(board, piece[i]->getPosition(0), piece[i]->getPosition(1), endmoverow, endmovecol, piece, true);
            }
        }
    }

    return incheck;
}

bool Game::isWhite(int row, int col)
{
    bool white = false;
    
    for (int i = 0; i < 6; i++)
    {
        if (board[row][col].getSymbol() == whitePieces[i])
        {
            white = true;
        }
    }
    
    //returning flag
    return white;
}

void Game::verifyPlayerMoveStart(string playermove)
{ 
    if(!this->checkPieceColor(playermove))
    {
        throw string("Invalid selection");
    }
    
    
}

bool Game::checkPieceColor(string playermove)
{
    bool valid = false;
    
    int movecol = playermove[0] - '0';
    int moverow = playermove[1] - '0';
    
    
    if (this->getWhiteTurn())
    {
        for (int i = 0; i < 6; i++)
        {
            if (board[moverow][movecol].getSymbol() == whitePieces[i])
            {
                valid = true;
            }
        }
    }
    else if (!this->getWhiteTurn())
    {
        for (int i = 0; i < 6; i++)
        {
            if (board[moverow][movecol].getSymbol() == blackPieces[i])
            {
                valid = true;
            }
        }
    }
    
    return valid;
}

string Game::convertAtlasCoordinatesToNumeric(string playermove)
{
    playermove[0] -= 49;
    
    //checks for single integer since conversion to int truncates the zero
    if (playermove[0] == '0')
    {
        if (playermove[1] == '1')
        {
            return "00";
        }
        else if (playermove[1] == '2')
        {
            return "01";
        }
        else if (playermove[1] == '3')
        {
            return "02";
        }
        else if (playermove[1] == '4')
        {
            return "03";
        }
        else if (playermove[1] == '5')
        {
            return "04";
        }
        else if (playermove[1] == '6')
        {
            return "05";
        }
        else if (playermove[1] == '7')
        {
            return "06";
        }
        else if (playermove[1] == '8')
        {
            return "07";
        }
        
    }
    
    return to_string(stoi(playermove)-1);
}

bool Game::checkCapture(bool whiteturn, string playermove[], bool simulation, vector<Piece*>& piece, bool realtimewhiteturn)
{
    //declare flag
    bool capturable = true;
    
//    //initialize the integer representation of moves as well as the piece array position
//    int startmoverow = playermove[1][1] - '0';  
//    int startmovecol = playermove[1][0] - '0';
//    
//    int i = pieceSearchArrayPosition(startmoverow, startmovecol, piece);
    
    int endmoverow = playermove[3][1] - '0';
    int endmovecol = playermove[3][0] - '0';
    
    //check if the destination tile is occupied by same color piece
    if (whiteturn && board[endmoverow][endmovecol].occ_white)
    {
        capturable = false;
    }
    else if (!whiteturn && board[endmoverow][endmovecol].occ_black)
    {
        capturable = false;
    }

    //return flag
    return capturable;
}

bool Game::kingNotincheck(vector<Piece*>& piece, string playermove[], bool whiteturn, bool hypo, bool simulation)
{
    //declaring copy array of structs for simulation
    tiles copyboard[8][8];
    vector<Piece*> copypiece;
    
    //copying over the data from original
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            copyboard[i][j] = board[i][j];
        }
    }

    copypiece.push_back(new Rook(static_cast<Rook*>(piece[0])));
    copypiece.push_back(new Knight(static_cast<Knight*>(piece[1])));
    copypiece.push_back(new Bishop(static_cast<Bishop*>(piece[2])));
    copypiece.push_back(new Queen(static_cast<Queen*>(piece[3])));
    copypiece.push_back(new King(static_cast<King*>(piece[4])));
    copypiece.push_back(new Bishop(static_cast<Bishop*>(piece[5])));
    copypiece.push_back(new Knight(static_cast<Knight*>(piece[6])));
    copypiece.push_back(new Rook(static_cast<Rook*>(piece[7])));

    copypiece.push_back(new Rook(static_cast<Rook*>(piece[8])));
    copypiece.push_back(new Knight(static_cast<Knight*>(piece[9])));
    copypiece.push_back(new Bishop(static_cast<Bishop*>(piece[10])));
    copypiece.push_back(new Queen(static_cast<Queen*>(piece[11])));
    copypiece.push_back(new King(static_cast<King*>(piece[12])));
    copypiece.push_back(new Bishop(static_cast<Bishop*>(piece[13])));
    copypiece.push_back(new Knight(static_cast<Knight*>(piece[14])));
    copypiece.push_back(new Rook(static_cast<Rook*>(piece[15])));
    
    //direct copying piece data array
    for (int i = 16; i < 24; i++)
    {
        copypiece.push_back(new Pawn(static_cast<Pawn*>(piece[i])));
        
    }

    for (int i = 24; i < 32; i++)
    {
        copypiece.push_back(new Pawn(static_cast<Pawn*>(piece[i])));
    }
    
    //simulation with copied data
    updateTiles(copyboard, copypiece, playermove, whiteturn, true);
    
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
        if (board[endmoverow][endmovecol].getOccupied())
        {
            if (copypiece[pos2]->getIsSupported())
            {
                return false;
            }
        }
    }
    
    
    
    if (whiteturn)
    {
        return !copyboard[copypiece[12]->getPosition(0)][copypiece[12]->getPosition(1)].underattackBlack;
    }
    
    else if (!whiteturn)
    {
        return !copyboard[copypiece[4]->getPosition(0)][copypiece[4]->getPosition(1)].underattackWhite;
    }
}

void Game::findSupports(vector<Piece*>& piece)
{
    bool support;
    
    for (int i = 8; i < 24; i++)
    {
        support = false;
        for (int j = 8; j < 24; j++)
        {
            if (!piece[j]->getCaptured() && !piece[i]->getCaptured())
            {
                if (piece[j]->checkMovement(board, piece[j]->getPosition(0), piece[j]->getPosition(1), piece[i]->getPosition(0), piece[i]->getPosition(1), piece, true))
                {
                    support = true;
                    piece[i]->setIsSupported(true);
                }
            }
        }
        if (support == false)
        {
            piece[i]->setIsSupported(false);
        }
    }
    
    //going through first part black pieces
    for (int i = 0; i < 8; i++)
    {
        support = false;
        for (int j = 0; j < 8; j++)
        {
            if (!piece[j]->getCaptured() && !piece[i]->getCaptured())
            {
                if (piece[j]->checkMovement(board, piece[j]->getPosition(0), piece[j]->getPosition(1), piece[i]->getPosition(0), piece[i]->getPosition(1), piece, true))
                {
                    support = true;
                    piece[i]->setIsSupported(true);
                }
            }
        }
        for (int j = 24; j < 32; j++)
        {
            if (!piece[j]->getCaptured() && !piece[i]->getCaptured())
            {
                if (piece[j]->checkMovement(board, piece[j]->getPosition(0), piece[j]->getPosition(1), piece[i]->getPosition(0), piece[i]->getPosition(1), piece, true))
                {
                    support = true;
                    piece[i]->setIsSupported(true);
                }
            }
        }
        if (support == false)
        {
            piece[i]->setIsSupported(false);
        }
    }
    
    //second part of black pieces
    for (int i = 24; i < 32; i++)
    {
        support = false;
        for (int j = 0; j < 8; j++)
        {
            if (!piece[j]->getCaptured() && !piece[i]->getCaptured())
            {
                if (piece[j]->checkMovement(board, piece[j]->getPosition(0), piece[j]->getPosition(1), piece[i]->getPosition(0), piece[i]->getPosition(1), piece, true))
                {
                    support = true;
                    piece[i]->setIsSupported(true);
                }
            }
        }
        for (int j = 24; j < 32; j++)
        {
            if (!piece[j]->getCaptured() && !piece[i]->getCaptured())
            {
                if (piece[j]->checkMovement(board, piece[j]->getPosition(0), piece[j]->getPosition(1), piece[i]->getPosition(0), piece[i]->getPosition(1), piece, true))
                {
                    support = true;
                    piece[i]->setIsSupported(true);
                }
            }
        }
        if (support == false)
        {
            piece[i]->setIsSupported(false);
        }
    }
}

void Game::updateTiles(vector <Piece*>& piece)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j].getSymbol() != ' ')
            {
                board[i][j].setOccupied(true);
                board[i][j].setOccupiedWhite(isWhite(i, j));
                board[i][j].setOccupiedBlack(!isWhite(i, j));
//                if (board[i][j].getOccupiedBlack())
//                {
//                    cout << i << j << "is occupied by black\n";
//                }
            }
            else if (board[i][j].getSymbol() == ' ')
            {
                board[i][j].setOccupied(false);
                board[i][j].setOccupiedWhite(false);
                board[i][j].setOccupiedBlack(false);
            }
        }
    }
    
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j].setUnderAttackWhite(this->isCheck(piece, i, j, true , false));
            board[i][j].setUnderAttackBlack(this->isCheck(piece, i, j, false, false));
        }
    }
    
    this->findSupports(piece); 
}

bool Game::KingMoveSafe(vector<Piece*>& piece, int endmoverow, int endmovecol, bool whiteturn)
{
    //declare flag
    bool safemove = true;
    
    //check if the destination tile is under check based on color
    if (whiteturn && board[endmoverow][endmovecol].underattackBlack)
    {
        safemove = false;
    }
    else if (!whiteturn && board[endmoverow][endmovecol].underattackWhite)
    {
        safemove = false;
    }

    //return flag
    return safemove;


}

void Game::updateTiles(vector<Piece*>& piece, Player player, bool whiteturn, bool simulation)
{
    string playermove[4];
    
    playermove[0] = player.getPlayerMove(0);
    playermove[1] = player.getPlayerMove(1);
    playermove[2] = player.getPlayerMove(2);
    playermove[3] = player.getPlayerMove(3);
    
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
            piece[pos1]->setPosition(0, -1);
            piece[pos1]->setPosition(1, -1);
            piece[pos1]->setCaptured(true);
        }
        
        //enpassants
        if (pos1 == -1 && piece[pos2]->getPieceValue() == 0 && endmoverow - startmoverow == 1 && endmovecol - startmovecol == 1 && board[endmoverow-1][endmovecol].getOccupied())
        {
            int pos3 = pieceSearchArrayPosition(startmoverow,startmovecol+1, piece);
            piece[pos3]->setPosition(0, -1);
            piece[pos3]->setPosition(1, -1);
            piece[pos3]->setCaptured(true);
            board[startmoverow][startmovecol+1].symbol = ' ';
        }
        else if (pos1 == -1 && piece[pos2]->getPieceValue() == 0 && endmoverow - startmoverow == 1 && endmovecol - startmovecol == -1 && board[endmoverow-1][endmovecol].getOccupied())
        {
            int pos3 = pieceSearchArrayPosition(startmoverow,startmovecol-1, piece);
            piece[pos3]->setPosition(0, -1);
            piece[pos3]->setPosition(1, -1);
            piece[pos3]->setCaptured(true);
            board[startmoverow][startmovecol-1].symbol = ' ';
        }
        else if (pos1 == -1 && piece[pos2]->getPieceValue() == 0 && endmoverow - startmoverow == -1 && endmovecol - startmovecol == 1 && board[endmoverow+1][endmovecol].getOccupied())
        {
            int pos3 = pieceSearchArrayPosition(startmoverow,startmovecol+1, piece);
            piece[pos3]->setPosition(0, -1);
            piece[pos3]->setPosition(1, -1);
            piece[pos3]->setCaptured(true);
            board[startmoverow][startmovecol+1].symbol = ' ';
        }
        else if (pos1 == -1 && piece[pos2]->getPieceValue() == 0 && endmoverow - startmoverow == -1 && endmovecol - startmovecol == -1 && board[endmoverow+1][endmovecol].getOccupied())
        {
            int pos3 = pieceSearchArrayPosition(startmoverow,startmovecol-1, piece);
            piece[pos3]->setPosition(0, -1);
            piece[pos3]->setPosition(1, -1);
            piece[pos3]->setCaptured(true);
            board[startmoverow][startmovecol-1].symbol = ' ';
        }
        
        
             
        //castling
        if (pos2 == 12 && endmovecol == 6 && piece[pos2]->getMoves() == 0)
        {
            piece[15]->setPosition(1, 5);
            piece[15]->addMoves(1);
            board[0][5].symbol = board[0][7].symbol;
            board[0][7].symbol = ' ';
        }
        else if (pos2 == 12 && endmovecol == 2 && piece[pos2]->getMoves() == 0)
        {
            piece[8]->setPosition(1, 3);
            piece[8]->addMoves(1);
            board[0][3].symbol = board[0][0].symbol;
            board[0][0].symbol = ' ';
        }
        else if (pos2 == 4 && endmovecol == 2 && piece[pos2]->getMoves() == 0)
        {
            piece[0]->setPosition(1, 3);
            piece[0]->addMoves(1);
            board[7][3].symbol = board[7][0].symbol;
            board[7][0].symbol = ' ';
        }
        else if (pos2 == 4 && endmovecol == 6 && piece[pos2]->getMoves() == 0)
        {
            piece[7]->setPosition(1, 5);
            piece[7]->addMoves(1);
            board[7][5].symbol = board[7][7].symbol;
            board[7][7].symbol = ' ';
        }
        
        //updating data
        piece[pos2]->setPosition(0, endmoverow);
        piece[pos2]->setPosition(1, endmovecol);
        piece[pos2]->addMoves(1);
        
        //updating board
        
        board[endmoverow][endmovecol].symbol = board[startmoverow][startmovecol].symbol;
        board[startmoverow][startmovecol].symbol = ' ';
        
        //updating pawns for double advance and promotion
//        pawnUpdate(piece, blackPieces, whitePieces, board, simulation);
    }
    
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (board[i][j].getSymbol() != ' ')
                {
                    board[i][j].setOccupied(true);
                    board[i][j].setOccupiedWhite(this->isWhite(i, j));
                    board[i][j].setOccupiedBlack(!this->isWhite(i, j));

                }
                else if (board[i][j].getSymbol() == ' ')
                {
                    board[i][j].setOccupied(false);
                    board[i][j].setOccupiedWhite(false);
                    board[i][j].setOccupiedBlack(false);
                }
            }
        }
    
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j].setUnderAttackWhite(this->isCheck(piece, i, j, true , false));
//            if (board[i][j].getUnderAttackWhite())
//            {
//                cout << i << "  " << j << " is under attack by white\n";
//            }
            
            board[i][j].setUnderAttackBlack(this->isCheck(piece, i, j, false, false));
//            if (board[i][j].getUnderAttackBlack())
//            {
//                cout << i << "  " << j << " is under attack by black\n";
//            }
        }
    }
    
    this->findSupports(piece); 
    
//    for (int i = 0; i < piece.size(); i++)
//    {
//        piece[i]->getIsSupported()?cout<<i<<"is supported":cout<<i<<" is not supported";
//        cout << endl;
//    }
}

bool Game::isCheck(tiles copyboard[8][8], vector<Piece*>& copypiece, int endmoverow, int endmovecol, bool white, bool hypo)
{
    bool incheck = false;
    
    //checking if any white piece can come to the destination tile for check
    if (white && !hypo)
    {
        for (int i = 8; i < 24 && !incheck; i++)
        {
            if (copypiece[i]->getCaptured() == false)
            {
//                cout << "piece " << i;
                incheck = copypiece[i]->checkMovement(copyboard, copypiece[i]->getPosition(0), copypiece[i]->getPosition(1), endmoverow, endmovecol, copypiece, true);
                
//                if (incheck)
//                {
//                    cout << endmoverow << " "  << endmovecol << "is under attack by " << i << endl;
//                }
            }
        }
    }
    
    //same thing but for all black pieces
    else if (!white  && !hypo)
    {
        for (int i = 0; i < 8 && !incheck; i++)
        {
//            cout << "piece " << i;
            if (copypiece[i]->getCaptured() == false)
            {
                incheck = copypiece[i]->checkMovement(copyboard, copypiece[i]->getPosition(0), copypiece[i]->getPosition(1), endmoverow, endmovecol, copypiece, true);
            }
        }
        for (int i = 24; i < 32 && !incheck; i++)
        {
//            cout << "piece " << i;
            if (copypiece[i]->getCaptured() == false && !incheck)
            {
                incheck = copypiece[i]->checkMovement(copyboard, copypiece[i]->getPosition(0), copypiece[i]->getPosition(1), endmoverow, endmovecol, copypiece, true);
            }
        }
    }

    return incheck;
}

void Game::generatePossibleMoves(vector <Piece*>& piece, bool whiteturn)
{
    //set counter to zero
    int m = 0;

    //for loop to go thorough every move
    //else if statement to catch captured pieces
    for (int i = 0; i < 32; i++)
    {
        m = 0;
        if (!piece[i]->getCaptured())
        {
            for (int j = 0; j < 8; j++)
            {
                for (int k = 0; k < 8; k++)
                {
                    piece[i]->setPossible_Moves(movePossible(j, k, piece, i, whiteturn), m++);
                }
            }
        }
        else if (piece[i]->getCaptured())
        {
            for (int j = 0; j < 64; j++)
            {
                piece[i]->setPossible_Moves("-1", j);
            }
        }
        
    }
}

string Game::movePossible(int a, int b, vector <Piece*>& piece, int c, bool whiteturn)
{
    //assigning integer values of the movements
    string playermove[4];
    
    playermove[0] = convertNumericToAtlasCoordinates(piece[c]->getPosition(0), piece[c]->getPosition(1));
    playermove[1] = convertAtlasCoordinatesToNumeric(playermove[0]);
    playermove[2] = convertNumericToAtlasCoordinates(a, b);
    playermove[3] = convertAtlasCoordinatesToNumeric(playermove[2]);

    //boolean if the move is possible
    bool result = verifyPlayerMove(*this, playermove, piece, piece[c]->getWhite(), true, true, whiteturn);
    
    //returning the result to the array element
    if (!result)
    {
        return "-1";
    }
    if (result)
    {
        return playermove[3];
    }
}

string Game::convertNumericToAtlasCoordinates(int row, int col)
{
    //declare string
    string str;
    
    //assigning string values
    str.push_back(getAlphaCoordinates(col));
    str.push_back(row + 1 + '0');
    
    //returning string values
    return str;
}

bool Game::verifyPlayerMove(Game game, string playermove[], vector <Piece*>& piece, bool whiteturn, bool hypo, bool simulation, bool realtimewhiteturn)
{
    //checkpoints
    bool checkpoints[4] = {1,0,0,1};
    
    
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

bool Game::isCheckmate(vector<Piece*>& piece, bool whiteturn)
{
    //flag and checkpoints
    bool checkmate = false;
    bool checkmateConditions[3] = {0,0,0};
    
    //assignment
    int i = -1;
    
    //in check flag
    if (board[piece[12]->getPosition(0)][piece[12]->getPosition(1)].underattackBlack)
    {
        checkmateConditions[0] = true;
        i=12;
    }
    else if (board[piece[4]->getPosition(0)][piece[4]->getPosition(1)].underattackWhite)
    {
        checkmateConditions[0] = true;
        i=4;
    }
    
    //return if first conditions fail as to prevent unneccessary simulation 
    if (i == -1)
    {
        return checkmate;
    }
    
    //simulation
    
    
    //checking if there are no moves for black to get out of check
    checkmateConditions[1] = cannotMove(piece, i);
    
    
    if (checkmateConditions[1])
    {
        checkmate = true;
    }
    
    //return flag
    return checkmate;
}
    
bool Game::isStalemate(vector <Piece*>& piece, bool whiteturn)
{
    //set flags
    bool stalemate = false;
    bool flag = false;
    
    //checking through all possible moves to see if any are valid
    if (!whiteturn)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int m = 0; m < 64 && !flag; m++)
            {
                if (piece[i]->getPossible_Moves(m) != "-1")
                {
                    flag = true;
                }
            }
        }
        for (int i = 24; i < 32; i++)
        {
            for (int m = 0; m < 64 && !flag; m++)
            {
                if (piece[i]->getPossible_Moves(m) != "-1")
                {
                    flag = true;
                }
            }
        }
        if (!flag && !piece[4]->getInCheck())
        {
            stalemate = true;
        }
    }
    //same thing but for white
    else if (whiteturn)
    {
        for (int i = 8; i < 24; i++)
        {
            for (int m = 0; m < 64 && !flag; m++)
            {
                if (piece[i]->getPossible_Moves(m) != "-1")
                {
                    flag = true;
                }
            }
        }
        if (!flag && !piece[12]->getInCheck())
        {
            stalemate = true;
        }
    }
    
    //return flag
    return stalemate;
}
    
bool Game::isInsufficient(vector<Piece*>& piece)
{
    //set counters for minor pieces
    int whiteknights = 0;
    int whitebishops = 0;
    int blackknights = 0;
    int blackbishops = 0;
    
    int whiteminor;
    int blackminor;
    
    //checking if any pawn is alive, if so, not insufficient
    for (int i = 16; i < 32; i++)
    {
        if (!piece[i]->getCaptured())
        {
            if (piece[i]->getPieceValue() == 0)
            {
                return false;
            }
            else if (piece[i]->getPieceValue() != -1)
            {
                if (piece[i]->getPieceValue() == 1 || piece[i]->getPieceValue() == 2)
                {
                    if (piece[i]->getWhite())
                    {
                        whiteminor++;
                    }
                    else if (!piece[i]->getWhite())
                    {
                        blackminor++;
                    }
                }
                else if (piece[i]->getPieceValue() == 4 || piece[i]->getPieceValue() == 0)
                {
                    return false;
                }
            }
        }
    }
    
    //if any rook exists, then false;
    if (!piece[0]->getCaptured() || !piece[7]->getCaptured() || !piece[8]->getCaptured() || !piece[15]->getCaptured())
    {
        return false;
    }
    //if any queen exists, then false;
    else if (!piece[3]->getCaptured() || !piece[11]->getCaptured())
    {
        return false;
    }
    
    //counting all alive minor pieces
    for (int i = 1; i < 15; i++)
    {
        if (!piece[i]->getCaptured())
        {
            if (i == 1 || i == 6)
            {
                blackknights++;
            }
            else if ( i == 2 || i == 5)
            {
                blackbishops++;
            }
            else if (i == 9 || i == 14)
            {
                whiteknights++;
            }
            else if (i == 10 || i == 13)
            {
                whitebishops++;
            }
        }
    }
    
    //totaling pieces
    whiteminor = whiteknights + whitebishops;
    blackminor = blackknights + blackbishops;
    
    //if the function gets to here, then no pawns, rooks, or queens exist
    
    //no minor pieces
    if (whiteminor + blackminor == 0)
    {
        return true;
    }
    //if white has one knight and no other pieces exist
    if ((whiteknights == 1 && blackknights == 0) && (blackbishops == 0 && whitebishops == 0))
    {
        return true;
    }
    //if black has one knight and no other pieces exist
    if ((whiteknights == 0 && blackknights == 1) && (blackbishops == 0 && whitebishops == 0))
    {
        return true;
    }
    //if white has 2 knights and no other pieces exist
    if ((whiteknights == 2 && blackknights == 0) && (blackbishops == 0 && whitebishops == 0))
    {
        return true;
    }
    //if black has 2 knights and no other pieces exist
    if ((whiteknights == 0 && blackknights == 2) && (blackbishops == 0 && whitebishops == 0))
    {
        return true;
    }
    //one minor piece each side, checkmate cannot be forced, but it possible
    if (blackminor == 1 && whiteminor == 1)
    {
        return true;
    }
}

bool Game::cannotMove(vector<Piece*>& piece, int K)
{
    //declaring flag
    bool cannotMove = true;

    //checking black king possible moves
    if (K == 4)
    {
        for (int m = 0; m < 64; m++)
        {
            if (piece[K]->getPossible_Moves(m) != "-1")
            {
                cannotMove = false;
            }
        }
    }
    //checking white king possible moves
    else if (K == 12)
    {
        for (int m = 0; m < 64; m++)
        {
            if (piece[K]->getPossible_Moves(m) != "-1")
            {
                cannotMove = false;
            }
        }
    }
    
    //checking all black pieces
    if (K == 4)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int m = 0; m < 64; m++)
            {
                if (piece[i]->getPossible_Moves(m) != "-1")
                {
                    cannotMove = false;
                }
            }
        }
        for (int i = 24; i < 32; i++)
        {
            for (int m = 0; m < 64; m++)
            {
                if (piece[i]->getPossible_Moves(m) != "-1")
                {
                    cannotMove = false;
                }
            }
        }
    }
    
    //checking all white pieces.
    else if (K == 12)
    {
        for (int i = 8; i < 24; i++)
        {
            for (int m = 0; m < 64; m++)
            {
                if (piece[i]->getPossible_Moves(m) != "-1")
                {
                    cannotMove = false;
                }
            }
        }
    }
    
    return cannotMove;
}