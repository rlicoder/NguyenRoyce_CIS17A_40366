#include <iostream>
#include <iomanip>

using namespace std;

double celsius(double fahrenheit);

int main ()
{
    double converted = 0;
    
    cout << left;
    cout << setw(14) << "Fahrenheit" << setw(14) << "Celsius" << endl;
    
    for (double count = 0; count < 21; count++)
    {
        converted = celsius(count);
        cout << setprecision(2) << fixed;
        cout << setw(14) << count << setw(14) << converted;
        cout << endl;
    }
    return 0;
}

double celsius(double fahrenheit)
{
    double celsius = 0;

    celsius = ((fahrenheit - 32) * 5) / 9;

    return celsius;
}