#include <bits/stdc++.h>

using namespace std;

struct account
{
    string name;
    string address;
    string accnum;
    float balance = 0;
};

main()
{
    account person;
    float temporary;
    int checkswritten;
    int deposits;
    
    cout << "Enter the name of the account: ";
    getline(cin, person.name);
    cout << "Enter the address of the account: ";
    getline(cin, person.address);
    cout << "Enter the account number of the account: ";
    cin >> person.accnum;
    
    while (person.accnum.length() != 5)
    {
        cout << "Your account number must be 5 digits long. Try again: ";
        cin >> person.accnum;
    }
    
    
    cout << "How many check did you write this month? ";
    cin >> checkswritten;

    if (checkswritten > 0)
    {
        cout << "Enter all amounts written in the check: ";
    }    
    for (int i = 0; i < checkswritten; i++)
    {
        cin >> temporary;
        person.balance -= temporary;
    }
    
   
    cout << "How many deposits did  you make this month? ";
    cin >> deposits;

    if (deposits > 0)
    {
        cout << "Enter all the deposit amount for this month";
    }
    for (int i = 0; i < deposits; i++)
    {
        cin >> temporary;
        person.balance += temporary;
    }
    
    cout << "Hello, " << person.name << endl;
    cout << "Your address is " << person.address << endl;
    cout << "Your account number is " << person.accnum << endl;
    cout << "Your account balance is " << person.balance << endl;
    if (person.balance < 0)
    {
        person.balance -= 20;
        cout << "Your account has been deducted 20 dollars for being overdrawn. ";
        cout << "Your new account balance is: " << person.balance << endl;
    }
    
}