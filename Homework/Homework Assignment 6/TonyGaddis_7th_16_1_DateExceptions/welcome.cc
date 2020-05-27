#include <bits/stdc++.h>

using namespace std;

class Date
{   
private:
    int month;
    int day;
    int year;
    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
public:
    class BadDay{};
    class BadMonth{};
    void printmmddyyyy() const;
    void printmstringddyyyy() const;
    void printddmstringyyyy() const;
    void setday(int day);
    void setmonth(int month);
    void setyear(int year);
};

void Date::printmmddyyyy() const
{
    if (month < 10)
    {
        cout << 0;
    }
    cout << month << "/";
    
    if (day < 10)
    {
        cout << 0;
    }
    cout << day << "/";
    
    cout << year << endl;
}

void Date::printmstringddyyyy() const
{
    cout << months[month-1] << " ";
    
    if (day < 10)
    {
        cout << 0;
    }
    cout << day << ", ";
    
    cout << year << endl;
}

void Date::printddmstringyyyy() const
{
    if (day < 10)
    {
        cout << 0;
    }
    cout << day << " ";
    
    cout << months[month-1] << " ";
    
    cout << year << endl;
}

void Date::setday(int userday)
{
    if (userday < 1 || userday > 31)
    {
        throw BadDay();
    }
    else 
        day = userday;
}

void Date::setmonth(int usermonth)
{
    if (usermonth < 1 || usermonth > 12)
    {
        throw BadMonth();
    }
    else
        month = usermonth;
}

void Date::setyear(int useryear)
{
    year = useryear;
}

main()
{
    int month, day, year;
    Date date;
    bool tryagain = true;
    
    cout << "Enter the day as an integer: ";
    cin >> day;
    
    while (tryagain)
    {
        try
        {
            date.setday(day);
            tryagain = false;
        }
        catch(Date::BadDay)
        {
            cout << "Wrong date. Enter the day as an integer: ";
            cin >> day;
        }
    }
    
    cout << "Enter the month as an integer: ";
    cin >> month;
    
    tryagain =  true;
    while (tryagain)
    {
        try
        {
            date.setmonth(month);
            tryagain = false;
        }
        catch(Date::BadMonth)
        {
            cout << "Wrong date. Enter the month as an integer: ";
            cin >> month;
        }
    }
    
    cout << "Enter the year as an integer: ";
    cin >> year;
    date.setyear(year);
    
    date.printmmddyyyy();
    date.printmstringddyyyy();
    date.printddmstringyyyy();
    
}