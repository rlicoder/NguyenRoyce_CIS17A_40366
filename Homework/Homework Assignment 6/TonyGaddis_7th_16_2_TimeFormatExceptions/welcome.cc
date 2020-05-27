#include <bits/stdc++.h>

using namespace std;

class Time
{
protected:
   int hour;
   int min;
   int sec;
public:
   // Default constructor
   Time() 
      { hour = 0; min = 0; sec = 0; }
   
   // Constructor
   Time(int h, int m, int s) 
      { hour = h; min = m; sec = s; }

   // Accessor functions
   int getHour() const
      { return hour; }

   int getMin() const
      { return min; }

   int getSec() const
      { return sec; }
   
   void setHour(int shour)
   {
       hour = shour;
   }
   void setMinutes(int smin)
   {
       min = smin;
   }
   void setSeconds(int sseconds)
   {
       sec = sseconds;
   }

};

class MilTime : public Time
{
private:
    int milHours;
    int milSeconds;
public:
    MilTime()
    {
        milHours = 0;
        milSeconds = 0;
    }
    MilTime(int hours, int seconds)
    {
        milHours = hours;
        milSeconds = seconds;
        setTime();
    }
    void setTime()
    {
        int thousands = milHours / 1000;
        int hundreds = (milHours - (thousands * 1000)) / 100;
        int tens = (milHours - (thousands * 1000) - (hundreds * 100)) / 10;
        int ones = (milHours - (thousands * 1000) - (hundreds * 100) - (tens * 10));
    
        
        int shours = (thousands*10) + hundreds;
        int minutes = (tens * 10) + ones;

        if (shours == 00)
        {
            shours = 12;
        }
        
        if (milHours > 1300)
        {
            Time::setHour(shours - 12);
            Time::setMinutes(minutes);
            Time::setSeconds(milSeconds);
        }
        else if (milHours < 1300)
        {
            Time::setHour(shours);
            Time::setMinutes(minutes);
            Time::setSeconds(milSeconds);
        }
    }
    void setHour(int shours)
    {
        if (shours < 0 || shours > 2359)
        {
            throw badHours();
        }
        else
        {
            milHours = shours;
            setTime();
        }
    }
    void setSeconds(int sseconds)
    {
        if (sseconds < 0 || sseconds > 59)
        {
            throw badSeconds();
        }
        else
        {
            milSeconds = sseconds;
            setTime();
        }
    }
    void getHour()
    {
        cout << setfill('0') << setw(4) <<  milHours << ":" << setfill('0') << setw(2) <<  milSeconds;
    }
    void getStandHour()
    {
        cout << setfill('0') << setw(2) <<  Time::getHour() << ":";
        cout << setfill('0') << setw(2) <<  Time::getMin() << ":";
        cout << setfill('0') << setw(2) <<  Time::getSec();
    }
    class badHours{};
    class badSeconds{};
};

int main()
{
    int hours;
    int seconds;
    bool tryagain = true;
    MilTime time;
    
    cout << "Enter the time in military hours: ";
    cin >> hours;
    
    while (tryagain)
    {
        try 
        {
            time.setHour(hours);
            tryagain = false;
        }
        catch(MilTime::badHours)
        {
            cout << "Invalid hours, try again ";
            cin >> hours;
        }
    }
    
    
    cout << "Enter the seconds: ";
    cin >> seconds;
    
    tryagain = true;
    while (tryagain)
    {
        try
        {
            time.setSeconds(seconds);
            tryagain = false;
        }
        catch(MilTime::badSeconds)
        {
            cout << "Invalid seconds, try again ";
            cin >> seconds;
        }
    }
    
    
    cout << "time in military time: ";
    time.getHour();
    
    cout << endl;
    
    cout << "time in standard time: ";
    time.getStandHour();
    cout << endl;
    
}