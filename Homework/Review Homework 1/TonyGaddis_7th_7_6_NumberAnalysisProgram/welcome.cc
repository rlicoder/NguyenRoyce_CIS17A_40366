/* 
 * File:   welcome.cc
 * Author: Royce Nguyen
 * Created on February 21, 2020
 * Purpose:  Number Analysis Program
 */
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//prototype for finding the lowest value of an array
void FindLowestValue(double numbers[], int reads);

//prototype for finding the highest value of an array
void FindHighestValue(double numbers[], int reads);

//prototype for finding the average value of an array
void FindAverageValue(double numbers[], int reads);

int main()
{
    //declaration of variables
    string filename;
    ifstream inputFile;
    double numbers[1000];
    int reads = 0;
    double average;
    
    //obtaining name of file from the user
    cout << "What is the name of the file? ";
    cin >> filename;
    
    //opening the file for reading
    inputFile.open(filename.c_str());
    
    //reading the numbers in the file to an array and also obtaining max number of reads
    while (!inputFile.eof() && reads < 1000)
    {
        inputFile >> numbers[reads];
        reads++;
    }

    inputFile.close();
        
    //function calls and outputting information
    FindLowestValue(numbers, reads);
    FindHighestValue(numbers, reads);
    cout << "The total amount of numbers in the array is " << reads << endl;
    FindAverageValue(numbers, reads);
    
    return 0;
}

//function definition
void FindLowestValue(double numbers[], int reads)
{
    //setting the lowest number of the array
    int lowest = numbers[0];
    
    //comparison and swapping lowest if one lower is found
    for (int count = 1; count < reads; count++)
    {
        if (numbers[count] < lowest)
            lowest = numbers[count];
    }
    //outputting final result
    cout << "The lowest value is " << lowest << endl;
}

void FindHighestValue(double numbers[], int reads)
{
    //setting the highest number of the array
    int highest = numbers[0];
    
    //comparison and swapping highest if one higher is found
    for (int count = 1; count < reads; count++)
    {
        if (numbers[count] > highest)
            highest = numbers[count];
    }
    //outputting the final result
    cout << "The highest value is " << highest << endl;
}

void FindAverageValue(double numbers[], int reads)
{
    //declaring an accumulator and assigning it to zero
    double total = 0;
    
    //summing up the values of the array
    for (int count = 0; count < reads; count++)
    {
        total += numbers[count];
    }
    //diving the sum by the total reads in order to get the average.
    double average = total/reads;
    cout << "The average value of all the numbers is " << average << endl;
}