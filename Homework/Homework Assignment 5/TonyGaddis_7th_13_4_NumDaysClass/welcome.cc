#include <bits/stdc++.h>

using namespace std;

class NumDays
{
private:
    float days;
    float hours;
public:
    NumDays(float numhours);
    NumDays();
    void getHours();
    void getDays();
    void setHours(float numhours);
    void setDays();
    NumDays operator++();
    NumDays operator--();
    NumDays operator++(int);
    NumDays operator--(int);
    NumDays operator+(const NumDays &right);
    NumDays operator-(const NumDays &right);
};

main()
{
    float a, b;
    
    cout << "Enter the number of hours you worked for the first day: ";
    cin >> a;
    cout << "Enter the number of hours you worked for the second day: ";
    cin >> b;
    
    NumDays day1(a);
    NumDays day2(b);
    NumDays total;
    
    cout << "The total hours you worked for day one is: ";
    day1.getHours();
    cout << endl;
    cout << "The total days you worked for day one is: ";
    day1.getDays();
    cout << endl;
    
    cout << "The total hours you worked for day two is: ";
    day2.getHours();
    cout << endl;
    cout << "The total days you worked for day two is: ";
    day2.getDays();
    cout << endl;
    
    cout << "The total hours worked on both days is: ";
    total = day1 + day2;
    total.getHours();
    cout << endl;
    cout << "The total days you worked on both days is: ";
    total.getDays();
    cout << endl;
    
    cout << "The difference in hours between both days is: ";
    total = day1 - day2;
    total.getHours();
    cout << endl;
    cout << "The total difference in hours you worked in between both days is: ";
    total.getDays();
    cout << endl;
    
    cout << "This is the hours of day1 1 after a prefix increment: ";
    ++day1;
    day1.getHours();
    cout << endl;
    cout << "This is the total amount of days worked in day 1 after the postfix increment: ";
    day1.getDays();
    cout << endl;
    
    cout << "This is the hours of day 2 after a postfix increment: ";
    day2++;
    day2.getHours();
    cout << endl;
    cout << "This is the total amount of days worked in day 2 after the postfix increment: ";
    day2.getDays();
    cout << endl;
    
    cout << "This is the hours of day 1 after a prefix decrement: ";
    --day1;
    day1.getHours();
    cout << endl;
    cout << "This is the total amount of days worked in day 1 after the postfix increment: ";
    day1.getDays();
    cout << endl;
    
    cout << "This is the hours of day 2 after a postfix decrement: ";
    day2--;
    day2.getHours();
    cout << endl;
    cout << "This is the total amount of days worked in day 2 after the postfix increment: ";
    day2.getDays();
    cout << endl;
    
    
    
}

void NumDays::getHours()
{
    cout << hours << " hours" << endl;
}

void NumDays::getDays()
{
    cout << days << " days" << endl;
}

void NumDays::setHours(float numhours)
{
    hours = numhours;
}

void NumDays::setDays()
{
    days = hours / 24;
}

NumDays::NumDays(float numhours)
{
    hours = numhours;
    setDays();
}

NumDays::NumDays()
{
    hours = 0;
    setDays();
}

NumDays NumDays::operator++()
{
    ++hours;
    setDays();
    return *this;
}

NumDays NumDays::operator--()
{
    --hours;
    setDays();
    return *this;
}

NumDays NumDays::operator++(int)
{
    NumDays temp(hours);
    hours++;
    setDays();
    return temp;
}

NumDays NumDays::operator--(int)
{
    NumDays temp(hours);
    hours--;
    setDays();
    return temp;
}

NumDays NumDays::operator+(const NumDays &right)
{
    NumDays temp;
    temp.hours = hours + right.hours;
    temp.setDays();
    return temp;
}


NumDays NumDays::operator-(const NumDays &right)
{
    NumDays temp;
    temp.hours = hours - right.hours;
    temp.setDays();
    return temp;
}