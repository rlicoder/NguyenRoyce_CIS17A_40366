#ifndef CHESSHEADER_H
#define CHESSHEADER_H

#include <bits/stdc++.h>

using namespace std;

#include "Piece.h"
#include "tiles.h"
#include "Knight.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Queen.h"
#include "Rook.h"
#include "King.h"
#include "Player.h"
#include "Game.h"

template <class T>
class List
{
    private:
        T *ptr;
        int arraySize;
        int realsize;
        
    public:
        List() { ptr = 0; arraySize = 0; realsize = 0; }
        
        ~List()
        {
            if (arraySize > 0)
            {
                delete [] ptr;
            }
        }
        
        List(int a)
        {
            arraySize = a;
            ptr = new T[a];
        }
        
        int size()
        { return arraySize; }
        
        void insert(T dummy, int val)
        {
            ptr[val] = dummy;
        }
        
        void setSize(int dummy)
        {
            this->realsize = dummy;
        }
        
        T &operator[](const int &dummy) const 
        {
            if (dummy < 0 || dummy >= arraySize)
            {
                cout << "Error!";
            }
            else 
            {
                return ptr[dummy];
            }
        }
        
        friend ostream &operator << (ostream &strm, const List<T>& obj)
        {   
            for (int i = 0; i < obj.realsize; i++)
            {
                strm << obj[i] << " ";
            }
            
            return strm;
        }

};

void updateGameState(bool whiteturn, Game& game, vector<Piece*>& piece);
int pieceSearchArrayPosition(int row, int col, vector<Piece*>& piece);
bool verifyPlayerMove(Game game, Player player, vector <Piece*>& piece, bool whiteturn, bool hypo, bool simulation, bool realtimewhiteturn);

enum piecevalue {PAWN = 0, KNIGHT = 1, BISHOP = 2, KING = 3, QUEEN = 4, ROOK = 5};

#endif /* CHESSHEADER_H */

