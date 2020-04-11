#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct drink
{
    string name;
    int cost;
    int stock;
};

int main()
{
    int totalearned = 0;
    string userchoice;
    drink a[5];
    int usermoney;
    int uservalue = -1;
    
    a[0].name = "Cola";
    a[0].cost = 75;
    a[0].stock = 20;
    
    a[1].name = "Root Beer";
    a[1].cost = 75;
    a[1].stock = 20;
    
    a[2].name = "Lemon-Lime";
    a[2].cost = 75;
    a[2].stock = 20;
    
    a[3].name = "Grape Soda";
    a[3].cost = 80;
    a[3].stock = 20;
    
    a[4].name = "Cream Soda";
    a[4].cost = 80;
    a[4].stock = 20;
    
	for(int i = 0; i < 5; i++)
	{
	    cout << setw(11) << left << a[i].name << setw(4) << a[i].cost << a[i].stock << endl; 
	}
	cout <<"Quit" << endl;
	
	getline(cin, userchoice);
	//cout << "userchoice is " << userchoice << endl;
	
	while (userchoice != "Quit")
	{
	    cin >> usermoney;
	    while (usermoney > 100 || usermoney < 0)
	    {
	        cout << "You entered an invalid amount of money. Try entering less than 1 dollar." << endl;
	        cin >> usermoney;
	    }
        for (int i = 0; i < 5; i++)
        {
            if (userchoice == a[i].name)
            {
                uservalue = i;
            }
        }
        if (uservalue == -1)
        {
            cout << "Your drink was not listed" << endl;
            break;
        }
        
        //cout << "uservalue is " << uservalue << endl;
        
        if (a[uservalue].stock > 0)
        {
            if (usermoney - a[uservalue].cost > 0)
            {
                cout << usermoney - a[uservalue].cost << endl;
                a[uservalue].stock--;
                totalearned += a[uservalue].cost;
            }
        }
        else 
        {
            cout << "Sorry, " << a[uservalue].name << " is currently not in stock." << endl;
        }
        
        for(int i = 0; i < 5; i++)
	    {
	        cout << setw(11) << left << a[i].name << setw(4) << a[i].cost << a[i].stock << endl; 
	    }
	    cout <<"Quit" << endl;
	    
	    cin.ignore(1);
	    getline(cin, userchoice);
	    //cout << "user choice is2 " << userchoice << endl;
	    uservalue = -1;
	}
	cout << totalearned << endl;
	
	
	return 0;
}






