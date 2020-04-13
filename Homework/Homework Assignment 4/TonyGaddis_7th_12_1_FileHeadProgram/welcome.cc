#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream input;
    
    int a[100];
    
    string s;
    cout << "enter the filename with the extension: ";
    cin >> s;
    
    input.open(s.c_str());
    
    int i = 0;
    while (input >> a[i])
    {
        i++;
    }
    input.close();
    
    if (i == 0)
    {
        cout << "there was no data to output";
    }
    else if (i < 10)
    {
        cout << "there is only " << i << " pieces of data to output";
    }
    else if (i > 100)
    {
        cout << "the file had more than 100 lines of data. only outputting the first 100";
    }
    
    cout << endl << "Here is the head of the file: " << endl;
    
    for (int j = 0; j < i; j++)
    {
        cout << a[j] << endl;
    }
    
    
    
    return 0;
}