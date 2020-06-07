#include "chessheader.h"

Player::Player()
{
    playermove[0] = "-1";
    playermove[1] = "-1";
    playermove[2] = "-1";
    playermove[3] = "-1";
}



void Player::setPlayerMove(int val, string dummy)
{
    playermove[val] = dummy;
    if (val == 0)
    {
        this->verifyPlayerMoveStart();
    }
    else if (val == 2)
    {
        this->verifyPlayerMoveEnd();
    }
}

bool Player::checkAlpha(string playermove)
{
    //declare flag
    bool alphafound = false;

    if (playermove[0] > 96 && playermove[0] < 105)
    {
        alphafound = true;
    }
    
    //return flag
    return alphafound;
}

bool Player::checkNum(string playermove)
{
    //declare flag
    bool numfound = false;

    // search if the number is within 0-9 range
    if(playermove[1] > 48 && playermove[1] < 57)
    {
        numfound = true;
    }
    
    //return flag
    return numfound;
}

void Player::getPlayerMoveStart()
{
    string dummy;

    cout << "Enter the start coordinates. ex: 'e2'";
    cin >> dummy;
    this->setPlayerMove(0, dummy);
}

void Player::verifyPlayerMoveStart()
{
    static bool checkpoints[2] = {0,0};
    
    //checkpoints
    checkpoints[0] = this->checkAlpha(playermove[0]);
    checkpoints[1] = this->checkNum(playermove[0]);
    
    //checking if the coordinate annotation is correct
    while(!(checkpoints[0] && checkpoints[1]))
    {
        if (!checkpoints[0])
        {
            cout << "Your alphanumerical character is incorrect";
        }
        else if (!checkpoints[1])
        {
            cout << "Your numerical value is incorrect";
        }
        cout << endl;
        this->getPlayerMoveStart();
        this->verifyPlayerMoveStart();
    }

    playermove[1] = this->convertAtlasCoordinatesToNumeric(playermove[0]);
}

string Player::convertAtlasCoordinatesToNumeric(string playermove)
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

void Player::getPlayerMoveEnd()
{
    string dummy;

    cout << "Enter the end coordinates. ex: 'e4'";
    cin >> dummy;
    this->setPlayerMove(2, dummy);
}

void Player::verifyPlayerMoveEnd()
{
    static bool checkpoints[2] = {0,0};
    
    //checkpoints
    checkpoints[0] = this->checkAlpha(playermove[2]);
    checkpoints[1] = this->checkNum(playermove[2]);
    
    //checking if the coordinate annotation is correct
    while(!(checkpoints[0] && checkpoints[1]))
    {
        if (!checkpoints[0])
        {
            cout << "Your alphanumerical character is incorrect";
        }
        else if (!checkpoints[1])
        {
            cout << "Your numerical value is incorrect";
        }
        cout << endl;
        this->getPlayerMoveEnd();
        this->verifyPlayerMoveEnd();
    }

    playermove[3] = this->convertAtlasCoordinatesToNumeric(playermove[2]);
}
