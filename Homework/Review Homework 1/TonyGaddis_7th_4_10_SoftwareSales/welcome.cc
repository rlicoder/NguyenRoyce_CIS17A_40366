/* 
 * File:   welcome.cc
 * Author: Royce Nguyen
 * Created on February 21, 2020
 * Purpose:  Software Sales
 */
#include <iostream>
#include <iomanip>

using namespace std;

//global constant for cost of the product as given by the problem
const double COST_OF_PRODUCT = 99;

int main()
{
    //declaration of variables
    int numProducts = 0;
    double discount = 1;
    double total = 0;
    double discountedTotal = 0;
    double discountAmount = 0;
    
    //obtaining number of products from the user
    cout << "How many products will you be purchasing?: ";
    cin >> numProducts;
    
    //input validation to ensure the user does not enter a negative value
    while (numProducts < 0)
    {
        cout << "It seems you entered a negative value. Try again: ";
        cin >> numProducts;
    }
    
    //if else if branches for the discounts
    if (numProducts >= 10 && numProducts <= 19)
        discount = .2;
    else if (numProducts >= 20 && numProducts <= 49)
        discount = .3;
    else if (numProducts >= 50 && numProducts <= 99)
        discount = .4;
    else if (numProducts >= 100)
        discount = .5;
    
    //calculation of discounts
    total = numProducts * COST_OF_PRODUCT;
    discountAmount = discount * total;
    discountedTotal = total - discountAmount;
    
    cout << setprecision(2) << fixed;
    
    //output of information
    if (discount != 1)
        cout << "Your total after discount is $" << discountedTotal << endl;
    else if (discount == 1)
        cout << "Your total comes out to $" << total << endl;
    
    return 0;
}