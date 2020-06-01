#include "chessheader.h"

void displayBoard(tiles board[8][8], char alphaCoordinates[])
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
        cout << alphaCoordinates[i] << "   ";
    }
    
    cout << endl << endl << endl << endl;
}