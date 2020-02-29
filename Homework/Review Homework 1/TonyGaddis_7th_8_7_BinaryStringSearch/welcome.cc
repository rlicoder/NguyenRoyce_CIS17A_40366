/* 
 * File:   welcome.cc
 * Author: Royce Nguyen
 * Created on February 21, 2020
 * Purpose:  Binary String Search
 */
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

//global constant for array size
const int NUM_NAMES = 20;

//function prototype for bubble sort algorithm
void SortStrings(string names[]);

//function prototype for binary search algorithm
int binarySearch(string names[], string value);

int main()
{
    //predefined array of names given by problem
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                           "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                           "Taylor, Terri", "Johnson, Jill",
                           "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                           "James, Jean", "Weaver, Jim", "Pore, Bob",
                           "Rutherford, Greg", "Javens, Renee",
                           "Harrison, Rose", "Setzer, Cathy",
                           "Pike, Gordon", "Holland, Beth" };
    
    //variable declaration for name to search
    string value;
    
    //pre-sorting the array before the binary search
    SortStrings(names);
    
    //obtain and assign value of name
    cout << "What is the name you are searching for? (Last, First): ";
    getline(cin, value);
    
    //declaration and assignment of the position value.
    int position = binarySearch(names, value);
    
    //declare success or failure
    if (position > -1)
        cout << "The position of your string is " << position;
    
    
    else if (position == -1)
        cout << "Sorry, the name you were searching for could not be found";

    return 0;
}

//function definition for bubble sort
void SortStrings(string names[])
{
    //declaration of placeholder and boolean
    bool swap;
    string temp;
    
    //do while loop for sort
    do 
    {
        //reinitializing swap to false after every run
        swap = false;
        
        //for loop to go through contents of array
        for (int count = 0; count < (NUM_NAMES-1); count++)
        {
            //string comparison
            int comparison = strcmp(names[count].c_str(),names[count+1].c_str());
            if (comparison > 0)
            {
                //switching positions and setting swap boolean as true
                temp = names[count];
                names[count] = names[count+1];
                names[count+1] = temp;
                swap = true;
            }
        }
    }while(swap);
}

//function definition for the binary search
int binarySearch(string names[], string value)
{
    //declaration of search boundaries and booleans
    int first = 0;
    int last = NUM_NAMES - 1;
    int middle;
    int position = -1;
    bool found = false;
    
    //while loop for going through the contents of the array
    while (!found && first <= last)
    {
        //setting the middle position of the search boundary
        middle = (first + last) / 2;
        //case for match found in the middle
        if (names[middle] == value)
        {
            found = true;
            position = middle;
        }
        //reducing array size if value is above middle array value
        else if (names[middle] > value)
        {
            last = middle - 1;
        }
        //reducing array size if value is below the middle array value
        else
        {
            first = middle - 1;
        }
    }
    return position;
}
