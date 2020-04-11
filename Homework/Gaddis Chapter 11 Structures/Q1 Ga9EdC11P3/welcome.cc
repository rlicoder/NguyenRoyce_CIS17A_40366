//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    struct division
    {
        float q[4],avg,total;
    };
    division N,W,E,S;
    
    float temp;
    float total = 0;
    float average;
    
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {
            cout <<  "North" << endl;
            for (int j = 0; j < 4; j++)
            {
                cin >> temp;
                cout << "Enter ";
                if (j == 0)
                {
                    cout << "first";
                }
                else if (j == 1)
                {
                    cout << "second";
                }
                else if (j == 2)
                {
                    cout << "third";
                }
                else if (j == 3)
                {
                    cout << "fourth";
                }
                cout << "-quarter sales:" << endl;
                N.q[j] = temp;
                total += N.q[j];
            }
            cout << setprecision(2) << fixed << "Total Annual sales:$" << total << endl;
            cout << "Average Quarterly Sales:$" << total/4 << endl;;
            total = 0;
        }
        else if (i == 1)
        {
            cout << "West" << endl;
            for (int j = 0; j < 4; j++)
            {
                cin >> temp;
                cout << "Enter ";
                if (j == 0)
                {
                    cout << "first";
                }
                else if (j == 1)
                {
                    cout << "second";
                }
                else if (j == 2)
                {
                    cout << "third";
                }
                else if (j == 3)
                {
                    cout << "fourth";
                }
                cout << "-quarter sales:" << endl;
                W.q[j] = temp;
                total += W.q[j];
            }
            cout << setprecision(2) << fixed << "Total Annual sales:$" << total << endl;
            cout << "Average Quarterly Sales:$" << total/4 << endl;
            total = 0;
        }
        else if (i == 2)
        {
            cout << "East" << endl;
            for (int j = 0; j < 4; j++)
            {
                cin >> temp;
                cout << "Enter ";
                if (j == 0)
                {
                    cout << "first";
                }
                else if (j == 1)
                {
                    cout << "second";
                }
                else if (j == 2)
                {
                    cout << "third";
                }
                else if (j == 3)
                {
                    cout << "fourth";
                }
                cout << "-quarter sales:" << endl;
                E.q[j] = temp;
                total += E.q[j];
            }
            cout << setprecision(2) << fixed << "Total Annual sales:$" << total << endl;
            cout << "Average Quarterly Sales:$" << total/4 << endl;
            total = 0;
        }
        else if (i == 3)
        {
            cout << "South" << endl;
            for (int j = 0; j < 4; j++)
            {
                cin >> temp;
                cout << "Enter ";
                if (j == 0)
                {
                    cout << "first";
                }
                else if (j == 1)
                {
                    cout << "second";
                }
                else if (j == 2)
                {
                    cout << "third";
                }
                else if (j == 3)
                {
                    cout << "fourth";
                }
                cout << "-quarter sales:" << endl;
                S.q[j] = temp;
                total += S.q[j];
            }
            cout << setprecision(2) << fixed << "Total Annual sales:$" << total << endl;
            cout << "Average Quarterly Sales:$" << total/4;
            total = 0;
        }
    }
    
    
    return 0;
}




