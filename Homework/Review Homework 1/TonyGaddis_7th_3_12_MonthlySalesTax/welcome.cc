#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const double COUNTY_TAX_RATE = .02;
const double STATE_TAX_RATE = .04;

int main() 
{
    string month;
    double totalSales = 0;
    double countyTax = 0;
    double stateTax = 0;
    double totalTax = 0;
    double grossSales = 0;
    
    cout << "Please enter the month you have recorded: ";
    cin >> month;
    cout << "Please enter the total sales (including sales tax): ";
    cin >> totalSales;
    cout << endl << endl;
    
    grossSales = totalSales / (1 + STATE_TAX_RATE + COUNTY_TAX_RATE);
    countyTax = grossSales * COUNTY_TAX_RATE;
    stateTax = grossSales * STATE_TAX_RATE;
    totalTax = stateTax + countyTax;
    totalTax = stateTax + countyTax;
    
    cout << "Month: " << month << endl;
    cout << "--------------------" << endl;
    cout << left << setprecision(2) << fixed;
    cout << setw(20) << "Total Collected: " << "$ " << setw(8) << right << totalSales << endl;
    cout << setw(20) << left << "Sales: " << "$ " << setw(8) << right << grossSales << endl;
    cout << setw(20) << left << "County Sales Tax: " << "$ " << setw(8) << right << countyTax << endl;
    cout << setw(20) << left << "State Sales Tax: " << "$ " << setw(8) << right << stateTax << endl;
    cout << setw(20) << left << "Total Sales Tax: " << "$ " << setw(8) << right << totalTax << endl;
    
    return 0;
}
