/* 
 * File:   welcome.cc
 * Author: Royce Nguyen
 * Created on February 21, 2020
 * Purpose:  Celsius Temperature Table
 */
#include <iostream>
#include <iomanip>

using namespace std;

//function declaration for temperature coversion
double celsius(double fahrenheit);

int main ()
{
    //declaration of variables
    double converted = 0;
    
    //formatting for the table
    cout << left;
    cout << setw(14) << "Fahrenheit" << setw(14) << "Celsius" << endl;
    
    //for loop to convert 1-20 degrees of Fahrenheit to Celsius
    for (double count = 0; count < 21; count++)
    {
        //assignment of celius conversion
        converted = celsius(count);
        
        //formatting for table
        cout << setprecision(2) << fixed;
        cout << setw(14) << count << setw(14) << converted;
        cout << endl;
    }
    return 0;
}

//function call for F -> C conversion
double celsius(double fahrenheit)
{
    //declaration of variable
    double celsius = 0;

    //mathematical conversion of fahrenheit to celsius
    celsius = ((fahrenheit - 32) * 5) / 9;

    return celsius;
}