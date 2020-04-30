#include <bits/stdc++.h>

using namespace std;

int encrypt(int code);

main()
{
    int code;
    int encrypted;
    
    
    cout << "Enter the 4 digit code to by encrypted: ";
    cin >> code;
    
    encrypted = encrypt(code);
    cout << encrypted;
    
}

int encrypt(int code)
{
   int thousands = code / 1000;
   int hundreds = (code - (thousands * 1000))/ 100;
   int tens = (code - (thousands * 1000) - (hundreds * 100))/10;
   int ones = code - (thousands * 1000) - (hundreds * 100) - (tens * 10);
   
   int newthousands = (thousands+5) % 8;
   int newhundreds = (hundreds+5) % 8;
   int newtens = (tens+5) % 8;
   int newones = (ones+5) % 8;
   
   int newnumber = 0;
   newnumber += (newtens * 1000);
   newnumber += (newones*100);
   newnumber += (newthousands*10);
   newnumber += (newhundreds);
   
   return newnumber;
}