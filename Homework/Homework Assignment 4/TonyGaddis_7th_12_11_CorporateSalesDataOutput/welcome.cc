#include <bits/stdc++.h>

using namespace std;

int main() 
{
    struct division
    {
        float q[4],avg,total;
    };
    
    division N,W,E,S;
    
    
    float temp;
    ofstream output;
    output.open("output.txt");
    
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {
            cout << "North" << endl;
            output <<  "North" << endl;
            for (int j = 0; j < 4; j++)
            {
                
                cout << "Enter ";
                if (j == 0)
                {
                    cout << "first";
                    output << "First";
                }
                else if (j == 1)
                {
                    cout << "second";
                    output << "Second";
                }
                else if (j == 2)
                {
                    cout << "third";
                    output << "Third";
                }
                else if (j == 3)
                {
                    cout << "fourth";
                    output << "Fourth";
                }
                cout << "-quarter sales:" << endl;
                output << "-quarter sales:";
                cin >> temp;
                N.q[j] = temp;
                output << N.q[j] << endl;
            }
        }
        else if (i == 1)
        {
            cout << "West" << endl;
            output <<  "West" << endl;
            for (int j = 0; j < 4; j++)
            {
                
                cout << "Enter ";
                if (j == 0)
                {
                    cout << "first";
                    output << "First";
                }
                else if (j == 1)
                {
                    cout << "second";
                    output << "Second";
                }
                else if (j == 2)
                {
                    cout << "third";
                    output << "Third";
                }
                else if (j == 3)
                {
                    cout << "fourth";
                    output << "Fourth";
                }
                cout << "-quarter sales:" << endl;
                output << "-quarter sales:";
                cin >> temp;
                W.q[j] = temp;
                output << W.q[j] << endl;
            }
        }
        else if (i == 2)
        {
            cout << "East" << endl;
            output <<  "East" << endl;
            for (int j = 0; j < 4; j++)
            {
                
                cout << "Enter ";
                if (j == 0)
                {
                    cout << "first";
                    output << "First";
                }
                else if (j == 1)
                {
                    cout << "second";
                    output << "Second";
                }
                else if (j == 2)
                {
                    cout << "third";
                    output << "Third";
                }
                else if (j == 3)
                {
                    cout << "fourth";
                    output << "Fourth";
                }
                cout << "-quarter sales:" << endl;
                output << "-quarter sales:";
                cin >> temp;
                E.q[j] = temp;
                output << E.q[j] << endl;
            }
        }
        else if (i == 3)
        {
            cout << "South" << endl;
            output <<  "South" << endl;
            for (int j = 0; j < 4; j++)
            {
                
                cout << "Enter ";
                if (j == 0)
                {
                    cout << "first";
                    output << "First";
                }
                else if (j == 1)
                {
                    cout << "second";
                    output << "Second";
                }
                else if (j == 2)
                {
                    cout << "third";
                    output << "Third";
                }
                else if (j == 3)
                {
                    cout << "fourth";
                    output << "Fourth";
                }
                cout << "-quarter sales:" << endl;
                output << "-quarter sales:";
                cin >> temp;
                S.q[j] = temp;
                output << S.q[j] << endl;
            }
        }
    }
    
    
    return 0;
}




