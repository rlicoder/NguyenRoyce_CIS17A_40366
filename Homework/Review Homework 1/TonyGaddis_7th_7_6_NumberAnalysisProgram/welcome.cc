#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void FindLowestValue(double numbers[], int reads);

void FindHighestValue(double numbers[], int reads);

void FindAverageValue(double numbers[], int reads);

int main()
{
    string filename;
    ifstream inputFile;
    double numbers[1000];
    int reads = 0;
    double average;
    
//    cout << "What is the name of the file? ";
//    cin >> filename;
    
    filename = "numbers.txt";
    
    inputFile.open(filename.c_str());
    
    while (!inputFile.eof() && reads < 1000)
    {
        inputFile >> numbers[reads];
        reads++;
    }

    FindLowestValue(numbers, reads);
    FindHighestValue(numbers, reads);
    cout << "The total amount of numbers in the array is " << reads << endl;
    FindAverageValue(numbers, reads);
    
    return 0;
}

void FindLowestValue(double numbers[], int reads)
{
    int lowest = numbers[0];
    
    for (int count = 1; count < reads; count++)
    {
        if (numbers[count] < lowest)
            lowest = numbers[count];
    }
    cout << "The lowest value is " << lowest << endl;
}

void FindHighestValue(double numbers[], int reads)
{
    int highest = numbers[0];
    
    for (int count = 1; count < reads; count++)
    {
        if (numbers[count] > highest)
            highest = numbers[count];
    }
    cout << "The highest value is " << highest << endl;
}

void FindAverageValue(double numbers[], int reads)
{
    double total = 0;
    for (int count = 0; count < reads; count++)
    {
        total += numbers[count];
    }
    double average = total/reads;
    cout << "The average value of all the numbers is " << average << endl;
}