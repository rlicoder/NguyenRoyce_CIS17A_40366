#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream input;
    
    int a[1000];
    
    string s;
    cout << "enter the filename with the extension: ";
    cin >> s;
    
    input.open(s.c_str());
    
    int i = 0;
    while (!input.eof())
    {
        input >> a[i];
        i++;
    }
    cout << i;
    input.close();
    
    if (i == 0)
    {
        cout << "there was no data to output";
    }
    else if (i < 10)
    {
        cout << "there is only " << i << " pieces of data to output";
    }
    
    cout << endl << "Here is the tail of the file: " << endl;
    
    for (int j = i-10; j < i; j++)
    {
        cout << a[j] << endl;
    }
    
    return 0;
}