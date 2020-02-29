/* 
 * File:   welcome.cc
 * Author: Royce Nguyen
 * Created on February 21, 2020
 * Purpose:  Property Tax
 */
#include <iostream>
#include <iomanip>

using namespace std;

//global constants for rates
const double PROPERTY_TAX_RATE = .64/100;
const double ASSESSMENT_RATE = .6;

int main()
{
    //declaration of variables
    double propertyValue = 0;
    double assessmentValue = 0;
    double propertyTax = 0;
   
    //obtaining information from the user
    cout << "Hello, this program will calculate your assessment value and property tax" << endl;
    cout << "Please enter your property value: ";
    cin >> propertyValue;
    cout << endl;
    
    //calculation of assessment value and property tax
    assessmentValue = ASSESSMENT_RATE * propertyValue;
    propertyTax = PROPERTY_TAX_RATE * assessmentValue;
    
    //outputting the values from previous calculation
    cout << setprecision(2) << fixed;
    cout << "Your assessment value is: $ " << assessmentValue << endl;
    cout << "Your property tax is : $ " << propertyTax << endl;
    
    return 0;
}