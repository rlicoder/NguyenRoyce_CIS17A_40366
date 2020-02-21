#include <iostream>
#include <iomanip>

using namespace std;

const double PROPERTY_TAX_RATE = .64/100;
const double ASSESSMENT_RATE = .6;

int main()
{
    double propertyValue = 0;
    double assessmentValue = 0;
    double propertyTax = 0;
   
    cout << "Hello, this program will calculate your assessment value and property tax" << endl;
    cout << "Please enter your property value: ";
    cin >> propertyValue;
    cout << endl;
    
    assessmentValue = ASSESSMENT_RATE * propertyValue;
    propertyTax = PROPERTY_TAX_RATE * assessmentValue;
    
    cout << setprecision(2) << fixed;
    cout << "Your assessment value is: $ " << assessmentValue << endl;
    cout << "Your property tax is : $ " << propertyTax << endl;
    
    return 0;
}