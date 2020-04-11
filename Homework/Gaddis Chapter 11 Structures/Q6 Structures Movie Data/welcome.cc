#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct m
{
    string t,d;
    int y,m;
};

int main()
{
    int n;
	cin >> n;
	m* array = new m[n];
	
	cout << "This program reviews structures" << endl;
    cout << "Input how many movies, the Title of the Movie, Director, Year Released, and the Running Time in (minutes)." << endl;
	
	for (int i = 0; i < n; i++)
	{
	    cin.ignore(1);
	    getline(cin, array[i].t);
	    getline(cin, array[i].d);
	    cin >> array[i].y;
	    cin >> array[i].m;
	}
	
	
	
	
	for (int i = 0; i < n; i++)
	{
	    cout << endl << setw(11) << left << "Title:" << array[i].t << endl;
	    cout << setw(11) << "Director:" << array[i].d << endl;
	    cout << setw(11) << "Year:" << array[i].y << endl;
	    cout << setw(11) << "Length:" << array[i].m << endl;
	}
	
	return 0;
}