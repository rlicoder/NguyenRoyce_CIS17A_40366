#include "chessheader.h"

void outputData(char whitePieces[], char blackPieces[], piecedata piece[])
{
    //outputting data in binary
    fstream binary;
    
    record* movedata;
    
    //using pointer in record structure
    movedata->totalmoveswhite = 0;
    movedata->totalmovesblack = 0;
    
    //incrementing total moves
    for (int i = 8; i < 24; i++)
    {
        movedata->totalmoveswhite += piece[i].moves;
    }
    for (int i = 0; i < 8; i++)
    {
        movedata->totalmovesblack += piece[i].moves;
    }
    for (int i = 24; i < 32; i++)
    {
        movedata->totalmovesblack += piece[i].moves;
    }
    
    //outputting total moves
    binary.open("totalmoves.txt", ios::binary | ios::out);
    
    binary.seekp(20L, ios::beg);
    binary.write(reinterpret_cast<char *>(movedata), sizeof(movedata));
    
    binary.close();
}