#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double increaseRate = 0;
    int startingPopulation = 0;
    int numOfDays = 0;
    int population = 0;
    
    cout << "What is the starting size of your population: ";
    cin >> startingPopulation;
    
    while (startingPopulation < 2)
    {
        cout << "This program will not accept a starting size less than 2. Try again: ";
        cin >> startingPopulation;
    }
    
    cout << "What is the rate of increase (fractional) for the population: ";
    cin >> increaseRate;
    
    while (increaseRate < 0)
    {
        cout << "This program does not accept negative values for the increase rate. Try again: ";
        cin >> increaseRate;
    }
    
    cout << "How many days (integer only) will the population increase: ";
    cin >> numOfDays;
    
    while (numOfDays < 1)
    {
        cout << "This program does not accept any value less than 1 for the number of days. Try again: ";
        cin >> numOfDays;
    }
    
    for (int count = 0; count < numOfDays; count++)
    {
        population = startingPopulation * pow((1+increaseRate), count);
        cout << "Day " << count + 1 << ": ";
        cout << population << endl;
    }
    
    return 0;
}