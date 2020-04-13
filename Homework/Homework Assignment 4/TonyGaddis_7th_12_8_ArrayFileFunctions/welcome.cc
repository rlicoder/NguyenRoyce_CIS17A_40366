#include <bits/stdc++.h>

using namespace std;

void arrayToFile(string filename, int array[], int size)
{
    ofstream output;
    output.open(filename.c_str(), ios::out | ios::binary);
    output.write(reinterpret_cast<char *>(array), sizeof(array));
    output.close();
}

void fileToArray(string filename, int array[], int size)
{
    ifstream input;
    input.open(filename.c_str(), ios::in | ios::binary);
    input.read(reinterpret_cast<char *>(array), sizeof(array));
    input.close();
}

int main()
{
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    
    arrayToFile("output.txt", array, 10);
    
    fileToArray("output.txt", array, 10);
    
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << endl;
    }
    
    return 0;
}