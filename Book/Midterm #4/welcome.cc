#include <bits/stdc++.h>

using namespace std;

class SavingsAccount
{
    public:
        SavingsAccount(float);               //Constructor
        void  Transaction(float);            //Procedure
        float Total(float=0,int=0);	         //Savings Procedure
        float TotalRecursive(float=0,int=0);
        void  toString();                    //Output Properties
    private:
        float Withdraw(float);               //Utility Procedure
        float Deposit(float);                //Utility Procedure
        float Balance;                       //Property
        int   FreqWithDraw;                  //Property
        int   FreqDeposit;                   //Property
};

main()
{
    SavingsAccount mine(-300);

    for(int i=1;i<=10;i++)
    {
        mine.Transaction((float)(rand()%500)*(rand()%3-1));
    }
    mine.toString();
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.Total((float)(0.10),7)<<endl;
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.TotalRecursive((float)(0.10),7)
        <<" Recursive Calculation "<<endl;
}

SavingsAccount::SavingsAccount(float dummy)
{
    if (dummy > 0)
    {
        Balance = dummy;
    }
    else 
    {
        Balance = 0;
    }
    FreqDeposit = 0;
    FreqWithDraw = 0;
}

void SavingsAccount::Transaction(float dummy)
{
    if (dummy > 0)
    {
        Deposit(dummy);
    }
    else if (dummy < 0)
    {
        Withdraw(dummy);
    }
}

float SavingsAccount::Deposit(float dummy)
{
    Balance += dummy;
    FreqDeposit++;
}

float SavingsAccount::Withdraw(float dummy)
{
    if (Balance + dummy < 0)
    {
        cout << "Error: You cannot withdraw more than currently in your balance.\n";
    }
    else if (Balance - dummy > 0)
    {
        Balance += dummy;
        FreqWithDraw++;
    }
}

void SavingsAccount::toString()
{
    cout << "Your balance is: " << setprecision(2) << fixed << Balance << endl;
    cout << "Your Withdrawal Frequency is: " << FreqWithDraw << endl;
    cout << "Your Deposit Frequency is: " << FreqDeposit << endl;
    
    cout << endl;
}

float SavingsAccount::Total(float savint, int time)
{
    return Balance*(pow((1+savint), time));
}

float SavingsAccount::TotalRecursive(float interestrate, int interesttime)
{
    if (interesttime != 0)
    {
        return (interestrate + 1) * TotalRecursive(interestrate, --interesttime);
    }
    else if (interesttime == 0)
    {
        return Balance;
    }
}