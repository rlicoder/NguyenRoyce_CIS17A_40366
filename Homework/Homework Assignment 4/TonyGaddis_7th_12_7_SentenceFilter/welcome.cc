#include <bits/stdc++.h>

using namespace std;

int main()
{
    ofstream output;
    ifstream input;
    
    string in,out;
    cout << "input the input file name: ";
    cin >> in;
    cout << "input the output file name: ";
    cin >> out;
    
    string s[100];
    int i = 0;
    
    input.open(in.c_str());
    while (!input.eof())
    {
        getline(input, s[i]);
        i++;
    }
    input.close();
    
    for(int j = 0; j < i;  j++)
    {
        s[j][0] = toupper(s[j][0]);
        for(int i = 1; i < s[j].length(); i++)
        {
            s[j][i] = tolower(s[j][i]);
        }
    }
    
    
    output.open(out.c_str());
    for (int k = 0; k < i; k++)
    {
        output << s[k] << endl;
    }
    
    return 0;
}