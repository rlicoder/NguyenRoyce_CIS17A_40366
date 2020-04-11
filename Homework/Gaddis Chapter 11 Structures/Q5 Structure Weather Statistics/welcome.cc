#include <iostream>
#include <iomanip>

using namespace std;

struct ar
{
    string month;
    int total;
    int high;
    int low;
    float avg;
};

int main()
{
    ar a[12];
    float total = 0;
    int lowpos = 0;
    int highpos = 0;
    float avgtotal = 0;
    
    
    
	for(int i = 0; i < 12; i++)
	{
	    cin >> a[i].month;
	    cin >> a[i].total;
	    
	    total+= a[i].total;
	    
	    cin >> a[i].low;
	    while (a[i].low > 140 || a[i].low < -100)
	    {
	        cout << "You entered a temperature that was invalid, Try again." << endl;
	        cin >> a[i].low;
	    }
	    
	    cin >> a[i].high;
	    while (a[i].high > 140 || a[i].high < -100)
	    {
	        cout << "You entered a temperature that was invalid, Try again." << endl;
	        cin >> a[i].high;
	    }
	    
	    a[i].avg = static_cast<float>((a[i].high+a[i].low)/2);
	    avgtotal += a[i].avg;
	    
	   // cout << a[i].month << endl;
	   // cout << a[i].total << endl;
	   // cout << a[i].high << endl;
	   // cout << a[i].low << endl;
	}
	
	
	int lowest = a[0].low;
	//cout << "The lowb4 " << lowest << endl;
	for (int i = 1; i < 12; i++)
	{
	    if (a[i].low < lowest)
	    {
	        lowest = a[i].low;
	        //cout << "i low is " << i << endl;
	        lowpos = i;
	    }
	}
	//cout << "The low " << lowest << endl;
	
	int highest = a[0].high;
	for (int i = 1; i < 12; i++)
	{
	    if (a[i].high > highest)
	    {
	        highest = a[i].high;
	        //cout << "i high is " << i << endl;
	        highpos = i;
	    }
	}
	//cout << "the high " << highest << endl;
	
	cout << setw(8) << left << "Average" << "Rainfall " << fixed << setprecision(1) << total / 12 << " inches/month" << endl;
	cout << setw(8) << left << "Lowest" << "Temperature " << a[lowpos].month << "  " << lowest << " Degrees Fahrenheit" << endl;
	cout << setw(8) << left << "Highest" << "Temperature " << a[highpos].month << "  " << highest << " Degrees Fahrenheit" << endl;
	cout << "Average Temperature for the year "  << static_cast<int>(avgtotal/12+0.5) << " Degrees Fahrenheit" << endl;
	
	
	return 0;
}





