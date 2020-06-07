#include "chessheader.h"

void getPlayerInfo(vector<Player>& players)
{
    string dummyname;
    cout << "Enter the white player name: ";
    getline(cin,dummyname);
    players.push_back(Player(true, dummyname));
    
    cout << "Enter the black player name: ";
    getline(cin, dummyname);
    players.push_back(Player(false, dummyname));
}