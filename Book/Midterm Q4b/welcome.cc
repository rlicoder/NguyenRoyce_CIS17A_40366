#include <bits/stdc++.h>

using namespace std;

int decrypt(int code);

main()
{
    int code;
    int decrypted;
    
    
    cout << "Enter the 4 digit code to by decrypted: ";
    cin >> code;
    
    decrypted = decrypt(code);
    cout << decrypted << endl;
    
}

int decrypt(int code)
{
    int thousands = code / 1000;
    int hundreds = (code - (thousands * 1000))/ 100;
    int tens = (code - (thousands * 1000) - (hundreds * 100))/10;
    int ones = code - (thousands * 1000) - (hundreds * 100) - (tens * 10);

    int newnum[4];
    newnum[0] = tens;
    newnum[1] = ones;
    newnum[2] = thousands;
    newnum[3] = hundreds;
   
    for (int i = 0; i < 4; i++)
    {
        if (newnum[i] == 5 || newnum[i] == 6 || newnum[i] == 7)
        {
            newnum[i] -= 5;
        }
        else if (newnum[i] >= 0 && newnum[i] <= 4)
        {
            newnum[i] = newnum[i] + 8 - 5;
        }
    }
    
    
    int newnumber = (newnum[0]*1000) + (newnum[1]*100) + (newnum[2]*10) + newnum[3];
    return newnumber;
}