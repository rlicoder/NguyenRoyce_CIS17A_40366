#include "chessheader.h"

void printMoveList(string* listptr, int moves, string moveList[], bool whiteturn, char whitePieces[], char blackPieces[])
{
    //declaring file streams and int
    fstream file;
    fstream simul;
    string namewhite;
    string nameblack;
    
    //outputting move list
    file.open("output.txt", ios::out);
    
    file << "Total Moves: " << moves << endl;
    file << setw(10) << "White" << setw(10) << "Black" << endl;
    
    //stepping through array using pointer notation
    for (int i = 0; i < moves*2; i++)
    {
        *(listptr + i) = moveList[i];
    }
    for (int i = 0; i < moves*2; i++)
    {
        file << setw(7) << *(listptr + i++) <<  " " << *(listptr + i);
        if ((i+1)%4==0)
        {
            file << endl;
        }
    }
    
    file << endl;
    
    //outputting all the pieces
    file << "White Pieces" << endl;
    for (int i = 0; i < 6; i++)
    {
        file.put(whitePieces[i]) << " ";
    }
    file << endl;
    file << "Black Pieces" << endl;
    for (int i = 0; i < 6; i++)
    {
        file.put(blackPieces[i]) << " ";
    }
    
    file.close();

    //simulatneous read write
    simul.open("names.txt", ios::in | ios::out | ios::app);
    
    simul >> namewhite;
    simul >> nameblack;
    simul << endl;
    if (whiteturn)
    {
        simul << nameblack << " made the last move!";
    }
    else if (!whiteturn)
    {
        simul << namewhite << " made the last move!";
    }
    
    //closing file
    simul.close();
}