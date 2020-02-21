#include <iostream>
#include <iomanip>

using namespace std;

const double COST_OF_PRODUCT = 99;

int main()
{
    int numProducts = 0;
    double discount = 1;
    double total = 0;
    double discountedTotal = 0;
    double discountAmount = 0;
    
    cout << "How many products will you be purchasing?: ";
    cin >> numProducts;
    
    while (numProducts < 0)
    {
        cout << "It seems you entered a negative value. Try again: ";
        cin >> numProducts;
    }
    
    if (numProducts >= 10 && numProducts <= 19)
        discount = .2;
    else if (numProducts >= 20 && numProducts <= 49)
        discount = .3;
    else if (numProducts >= 50 && numProducts <= 99)
        discount = .4;
    else if (numProducts >= 100)
        discount = .5;
    
    total = numProducts * COST_OF_PRODUCT;
    discountAmount = discount * total;
    discountedTotal = total - discountAmount;
    
    cout << setprecision(2) << fixed;
    
    if (discount != 1)
        cout << "Your total after discount is $" << discountedTotal << endl;
    else if (discount == 1)
        cout << "Your total comes out to $" << total << endl;
    
    return 0;
}