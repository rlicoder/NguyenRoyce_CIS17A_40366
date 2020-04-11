/* 
 * File:   
 * Author: 
 * Created on 
 * Purpose:  
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
struct a
{
    float b[10];
    float c[10] = {500.00,150.00,65.00,50.00,250.00,30.00,100.00,150.00,75.00,50.00};
};

void getdata(a &month);
void printreport(a &month);

//Execution Begins Here
int main(int argc, char** argv) 
{

    
    a month;
    
    getdata(month);
    printreport(month);
    
    return 0;
}


void getdata(a &month)
{
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter ";
        if (i == 0)
        {
            cout << "housing "; 
        }
        else if (i==1)
        {
            cout << "utilities ";
        }
        else if (i==2)
        {
            cout << "household expenses ";
        }
        else if (i==3)
        {
            cout << "transportation ";
        }
        else if (i==4)
        {
            cout << "food ";
        }
        else if (i==5)
        {
            cout << "medical ";
        }
        else if (i==6)
        {
            cout << "insurance ";
        }
        else if (i==7)
        {
            cout << "entertainment ";
        }
        else if (i==8)
        {
            cout << "clothing ";
        }
        else if (i==9)
        {
            cout << "miscellaneous ";
        }
        cout << "cost for the month:$";
        cin >> month.b[i];
        //cout << month.b[i] << endl;
        cout << endl;
    }
}


void printreport(a &month)
{
    float total = 0, total2 = 0;
    for (int i = 0; i < 10; i++)
    {
        if (i == 0)
        {
            cout << "Housing "; 
        }
        else if (i==1)
        {
            cout << "Utilities ";
        }
        else if (i==2)
        {
            cout << "Household Expenses ";
        }
        else if (i==3)
        {
            cout << "Transportation ";
        }
        else if (i==4)
        {
            cout << "Food ";
        }
        else if (i==5)
        {
            cout << "Medical ";
        }
        else if (i==6)
        {
            cout << "Insurance ";
        }
        else if (i==7)
        {
            cout << "Entertainment ";
        }
        else if (i==8)
        {
            cout << "Clothing ";
        }
        else if (i==9)
        {
            cout << "Miscellaneous ";
        }
        //cout << month.b[i] << " " << month.c[i]<< endl;
        if (month.b[i] > month.c[i])
        {
            cout << "Over";
        }
        else if (month.b[i] == month.c[i])
        {
            cout << "Even";
        }
        else if (month.b[i] < month.c[i])
        {
            cout << "Under";
        }
        cout << endl;
        total += month.b[i];
        total2 += month.c[i];
    }
    
    //cout << total << " " << total2 << endl;
    cout << "You were $" << setprecision(2) << fixed;
    if (total > total2)
    {
        cout << total - total2 << " over";
    }
    else if (total == total2)
    {
        cout << " even";
    }
    else if (total < total2)
    {
       cout << total2-total << " under";
    }
    cout << " budget";
}












