#include <iostream>
#include <iomanip>

using namespace std;

struct ar
{
    float total;
    float high;
    float low;
};

enum month {jan, feb, mar, apr, may, jun};

int main()
{
    ar a[6];
    float total = 0;
    int lowpos = 0;
    int highpos = 0;
    float avgtemp = 0;
    
	for(int i = jan; i < jun+1; i++)
	{
	    //cout << i << endl;
	    cout << "Enter the total rainfall for the month:" << endl;
	    cin >> a[i].total;
	    
	    total+= a[i].total;
	    
	    cout << "Enter the high temp:" << endl;
	    cin >> a[i].high;
	   
	    cout << "Enter the low temp:" << endl;
	    cin >> a[i].low;
	    
	    avgtemp += a[i].high + a[i].low;
	    
	   // cout << a[i].total << endl;
	   // cout << a[i].high << endl;
	   // cout << a[i].low << endl;
	}
	
	
	int lowest = a[0].low;
	//cout << "The lowb4 " << lowest << endl;
	for (int i = feb; i < jun+1; i++)
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
	for (int i = feb; i < jun+1; i++)
	{
	    if (a[i].high > highest)
	    {
	        highest = a[i].high;
	        //cout << "i high is " << i << endl;
	        highpos = i;
	    }
	}
	//cout << "the high " << highest << endl;
	
	cout << "Average monthly rainfall:" << setprecision(2) << fixed << total/6 << endl;
	cout << "High Temp:" << highest << endl;
	cout << "Low Temp:" << lowest << endl;
	cout << "Average Temp:" << setprecision(1) << fixed << avgtemp/12;
	
	return 0;
}





