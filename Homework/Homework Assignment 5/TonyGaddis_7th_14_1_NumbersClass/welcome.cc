#include <bits/stdc++.h>

using namespace std;

class Numbers
{
private:
    int number;
    string lessThan20[19] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
    "nineteen"};
    string strtens[8] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    string hundred = " hundred ";
    string thousand = " thousand ";
public:
    Numbers(int num);
    void print();
};

main()
{
    int num;
    cout << "Enter a number: ";
    cin >>  num;
    Numbers number(num);
    number.print();
}

Numbers::Numbers(int num)
{
    number = num;
}

void Numbers::print()
{
    int thousands = number / 1000;
    int hundreds = (number - (thousands*1000)) / 100;
    int tens = ((number - (thousands*1000)) - (hundreds * 100)) / 10;
    int ones = ((((number - (thousands*1000)) - (hundreds * 100)) - (tens*10)));
    int tensplusones = (tens*10) + ones;
    
    if (thousands > 0)
    {
        cout << lessThan20[thousands-1] << thousand;
    }
    if (hundreds > 0)
    {
        cout << lessThan20[hundreds - 1] << hundred;
    }
    if (tensplusones > 10 && tensplusones < 20)
    {
        cout << lessThan20[tensplusones-1] << " ";
    }
    else if (tensplusones >= 20)
    {
        cout << strtens[tens-2] << " ";
    }
    else if (tensplusones < 10)
    {
        cout << lessThan20[tensplusones-1] << " ";
    }
    if (ones > 0)
    {
        cout << lessThan20[ones-1] << " ";
    }
    cout << endl;
    
    
}


