/* 
 * File:   welcome.cc
 * Author: Royce Nguyen
 * Created on February 21, 2020
 * Purpose:  Population
 */
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    //declaration of variables
    double increaseRate = 0;
    int startingPopulation = 0;
    int numOfDays = 0;
    int population = 0;
    
    //obtaining user input for the starting population size
    cout << "What is the starting size of your population: ";
    cin >> startingPopulation;
    
    //input validation for starting population
    while (startingPopulation < 2)
    {
        cout << "This program will not accept a starting size less than 2. Try again: ";
        cin >> startingPopulation;
    }
    
    //obtaining user input for the rate of increase in a population
    cout << "What is the rate of increase (fractional) for the population: ";
    cin >> increaseRate;
    
    //input validation for rate of increase
    while (increaseRate < 0)
    {
        cout << "This program does not accept negative values for the increase rate. Try again: ";
        cin >> increaseRate;
    }
    
    //obtaining an integer value for days of population growth
    cout << "How many days (integer only) will the population increase: ";
    cin >> numOfDays;
    
    //input validation for days of growth
    while (numOfDays < 1)
    {
        cout << "This program does not accept any value less than 1 for the number of days. Try again: ";
        cin >> numOfDays;
    }
    
    //outputting day by day population count with the given metrics
    for (int count = 0; count < numOfDays; count++)
    {
        //using mathematical model of an exponentially growing population
        population = startingPopulation * pow((1+increaseRate), count);
        
        //outputting information
        cout << "Day " << count + 1 << ": ";
        cout << population << endl;
    }
    
    return 0;
}