#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

const int NUM_NAMES = 20;

void SortStrings(string names[]);
int binarySearch(string names[], string value);

int main()
{
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                           "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                           "Taylor, Terri", "Johnson, Jill",
                           "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                           "James, Jean", "Weaver, Jim", "Pore, Bob",
                           "Rutherford, Greg", "Javens, Renee",
                           "Harrison, Rose", "Setzer, Cathy",
                           "Pike, Gordon", "Holland, Beth" };
    
    string value;
    
    SortStrings(names);
    
    cout << "What is the name you are searching for? (Last, First): ";
    getline(cin, value);
    
    int position = binarySearch(names, value);
    
    cout << "The position of your string is " << position;

    return 0;
}

void SortStrings(string names[])
{
    bool swap;
    string temp;
    
    do 
    {
        swap = false;
        for (int count = 0; count < (NUM_NAMES-1); count++)
        {
            int comparison = strcmp(names[count].c_str(),names[count+1].c_str());
            if (comparison > 0)
            {
                temp = names[count];
                names[count] = names[count+1];
                names[count+1] = temp;
                swap = true;
            }
        }
    }while(swap);
}

int binarySearch(string names[], string value)
{
    int first = 0;
    int last = NUM_NAMES - 1;
    int middle;
    int position = -1;
    bool found = false;
    
    while (!found && first <= last)
    {
        middle = (first + last) / 2;
        if (names[middle] == value)
        {
            found = true;
            position = middle;
        }
        else if (names[middle] > value)
        {
            last = middle - 1;
        }
        else
        {
            first = middle - 1;
        }
    }
    return position;
}
