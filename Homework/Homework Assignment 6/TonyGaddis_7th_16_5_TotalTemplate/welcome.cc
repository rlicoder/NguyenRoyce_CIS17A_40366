#include <bits/stdc++.h>

using namespace std;

template <class T> 
T total(int num)
{
    T value;
    T total = 0;
    for (int i = 0; i < num; i++)
    {
        cin >> value;
        total += value;
    }
    return total;
}

main()
{
    int num;
    
    cout << "How many ints would you like to total? ";
    cin >> num;
    cout << total<int>(num) << endl << endl;
    
    cout << "How many floats would you like to total? ";
    cin >> num;
    cout << total<float>(num) << endl << endl;
    
    cout << "How many doubles would you like to total? ";
    cin >> num;
    cout << total<double>(num) << endl << endl;
    
    cout << "How many shorts would you like to total? ";
    cin >> num;
    cout << total<short>(num) << endl << endl;
}