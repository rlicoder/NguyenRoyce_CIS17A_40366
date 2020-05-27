#include <bits/stdc++.h>

using namespace std;

template <class T>
T minimum (T n1, T n2)
{
    return !(n1>n2)?n1:n2; 
}

template <class T>
T maximum (T n1, T n2)
{
    return n1<n2?n2:n1; 
}

main()
{
    int n1, n2;
    
    cout << "Enter an integer: ";
    cin >> n1;
    
    cout << "Enter another integer: ";
    cin >> n2;
    
    cout << "The maximum of the two integers is: " << maximum(n1, n2) << endl;
    cout << "The minimum of the two integers is: " << minimum(n1, n2) << endl;
    
    float n3, n4;
    
    cout << "Enter a float: ";
    cin >> n3;
    
    cout << "Enter another float: ";
    cin >> n4;
    
    cout << "The maximum of the two floats is: " << maximum(n3, n4) << endl;
    cout << "The minimum of the two floats is: " << minimum(n3, n4) << endl;
    
    double n5, n6;
    
    cout << "Enter a double: ";
    cin >> n5;
    
    cout << "Enter another double: ";
    cin >> n6;
    
    cout << "The maximum of the two doubles is: " << maximum(n5, n6) << endl;
    cout << "The minimum of the two doubles is: " << minimum(n5, n6) << endl;
    
    char n7, n8;
    
    cout << "Enter a char: ";
    cin >> n7;
    
    cout << "Enter another char: ";
    cin >> n8;
    
    cout << "The maximum of the two chars is: " << maximum(n7, n8) << endl;
    cout << "The minimum of the two chars is: " << minimum(n7, n8) << endl;
    
    short n9, n10;
    
    cout << "Enter a short: ";
    cin >> n9;
    
    cout << "Enter another short: ";
    cin >> n10;
    
    cout << "The maximum of the two shorts is: " << maximum(n9, n10) << endl;
    cout << "The minimum of the two shorts is: " << minimum(n9, n10) << endl;
    
}