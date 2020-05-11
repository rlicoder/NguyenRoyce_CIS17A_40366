#include <bits/stdc++.h>

using namespace std;

class DayOfYear
{
private:
    int dayofyear;
    int monthofyear;
    int dayofmonth;
    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int monthday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
    DayOfYear(string month, int day);
    void print();
    void update();
    DayOfYear operator++();
    DayOfYear operator--();
    DayOfYear operator++(int);
    DayOfYear operator--(int);
    
};

main()
{
    string month;
    int daynum;
    cout << "Enter the month of the year (using proper capitalization): ";
    cin >> month;
    cout << "Enter the day of the month: ";
    cin >> daynum;
    
    DayOfYear day(month, daynum);
    day.print();
    
    cout << "I will now perform two increments and two decrements. " << endl;
    
    cout << "This is the day of year after a prefix increment: ";
    ++day;
    day.print();
    
    cout << "This is the day of year after a postfix increment: ";
    day++;
    day.print();
    
    cout << "This is the day of year after a prefix decrement: ";
    --day;
    day.print();
    
    cout << "This is the day of year after a postfix decrement: ";
    day--;
    day.print();
    
}

DayOfYear::DayOfYear(string month, int day)
{
    
    dayofyear = 0;
    monthofyear = 0;
    dayofmonth = day;
    
    for (int i = 0; i < 12; i++)
    {
        if (month == months[i])
        {
            monthofyear = i;
            for (int j = 0; j < i; j++)
            {
                dayofyear += monthday[j];
            }
        }
    }
    
    if (dayofmonth > monthday[monthofyear])
    {
        cout << "Invalid date for month. Program Terminated. ";
        exit(69);
    }
    
    dayofyear += day;
}

void DayOfYear::print()
{
    cout << "Day of Year: " << dayofyear << endl << endl;
}

void DayOfYear::update()
{
    if (dayofmonth > monthday[monthofyear])
    {
        dayofmonth -= monthday[monthofyear++];
    }
    else if (dayofmonth == 0)
    {
        monthofyear--;
    }
    if (monthofyear > 11)
    {
        monthofyear = 0;
        dayofyear = 1;
    }
    else if (monthofyear < 0)
    {
        monthofyear = 11;
        dayofyear = 365;
    }
}

DayOfYear DayOfYear::operator++()
{
    ++dayofmonth;
    ++dayofyear;
    update();
    return *this;
}

DayOfYear DayOfYear::operator--()
{
    --dayofmonth;
    --dayofyear;
    update();
    return *this;
}

DayOfYear DayOfYear::operator++(int)
{
    DayOfYear temp(months[monthofyear], dayofmonth);
    dayofmonth++;
    dayofyear++;
    update();
    return temp;
}

DayOfYear DayOfYear::operator--(int)
{
    DayOfYear temp(months[monthofyear], dayofmonth);
    dayofmonth--;
    dayofyear--;
    update();
    return temp;
}