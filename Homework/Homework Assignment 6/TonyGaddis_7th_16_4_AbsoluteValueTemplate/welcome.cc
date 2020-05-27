#include <bits/stdc++.h>

using namespace std;

template <class T>
T abs(T v) 
{
    return v<0?-v:v; 
}

main()
{
    int n1;
    
    cout << "Enter an int: ";
    cin >> n1;
    cout << "The absolute value of the int is: " << abs(n1) << endl;
    
    
    float n2;
    
    cout << "Enter a float: ";
    cin >> n2;
    cout << "The absolute value of the float is: " << abs(n2) << endl;
    
    
    double n3;
    
    cout << "Enter a double: ";
    cin >> n3;
    cout << "The absolute value of the double is: " << abs(n3) << endl;
    
            
    short n4;
    
    cout << "Enter a short: ";
    cin >> n4;
    cout << "The absolute value of the short is: " << abs(n4) << endl;
    
}