#include "chessheader.h"

void readInPieceDataNames(char blackPieces[], char whitePieces[], ifstream &pieces, ifstream &names, string playernames[])
{
    //file open
    pieces.open("pieceData.txt");
    
    //declaring a set
    set<char> s;
    
    //reading in data
    for (int i = 0; i < 6; i++)
    {
        pieces >> blackPieces[i];
        s.insert(blackPieces[i]);
    }
    //reading in data for white
    for (int i = 0; i < 6; i++)
    {
        pieces >> whitePieces[i];
        s.insert(whitePieces[i]);
    }
    //closing file
    pieces.close();
    //opening file
    names.open("names.txt");
    //raeding data
    names >> playernames[0];
    names >> playernames[1];
    //closing file
    names.close();
    //checking for unique pieces
    if (s.size() != 12)
    {
        cout << "You did not have 12 unique piece characters" << endl;
        cout << "Therefore, the default pieces are going to be:" << endl;
        
        whitePieces[PAWN] = 'P';
        whitePieces[KNIGHT] = 'N';
        whitePieces[BISHOP] = 'B';
        whitePieces[KING] = 'K';
        whitePieces[QUEEN] = 'Q';
        whitePieces[ROOK] = 'R';
        blackPieces[PAWN] = '1';
        blackPieces[KNIGHT] = '2';
        blackPieces[BISHOP] = '3';
        blackPieces[KING] = '4';
        blackPieces[QUEEN] = '5';
        blackPieces[ROOK] = '6';
        
        cout << "WHITE PAWN: " << whitePieces[PAWN] << endl;
        cout << "WHITE KNIGHT: " << whitePieces[KNIGHT] << endl;
        cout << "WHITE BISHOP: " << whitePieces[BISHOP] << endl;
        cout << "WHITE KING: " << whitePieces[KING] << endl;
        cout << "WHITE QUEEN: " << whitePieces[QUEEN] << endl;
        cout << "WHITE ROOK: " << whitePieces[ROOK] << endl;
        
        cout << "BLACK PAWN: " << blackPieces[PAWN] << endl;
        cout << "BLACK KNIGHT: " << blackPieces[KNIGHT] << endl;
        cout << "BLACK BISHOP: " << blackPieces[BISHOP] << endl;
        cout << "BLACK KING: " << blackPieces[KING] << endl;
        cout << "BLACK QUEEN: " << blackPieces[QUEEN] << endl;
        cout << "BLACK ROOK: " << blackPieces[ROOK] << endl;
    }
}