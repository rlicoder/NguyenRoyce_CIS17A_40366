#include "chessheader.h"

string convertAtlasCoordinatesToNumeric(string playermove, char alphaCoordinates[])
{
    //checking through alphaCoordinates and assigning respective numeric value
    for (int i = 0; i < 8; i++)
    {
        if (playermove[0] == alphaCoordinates[i])
        {
            playermove[0] = i+48;
        }
    }
    
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