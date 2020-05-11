#include <bits/stdc++.h>

using namespace std;

class DayOfYear
{
private:
    int day;
    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
public:
    void print();
    DayOfYear(int num);
};

main()
{
    int num;
    cout << "Enter a day value from 1 to 365: ";
    cin >> num;
    DayOfYear day(num);
    day.print();
}

DayOfYear::DayOfYear(int num)
{
    day = num;
}

void DayOfYear::print()
{
    int count = 0;
    if (day - 31 > 0)
    {
        day -= 31;
        count++;
        if (day - 28 > 0)
        {
            day -= 28;
            count++;
            if (day - 31 > 0)
            {
                day -= 31;
                count++;
                if (day - 30 > 0)
                {
                    day -= 30;
                    count++;
                    if (day - 31 > 0)
                    {
                        day -= 31;
                        count++;
                        if (day - 30 > 0)
                        {
                            day -= 30;
                            count++;
                            if (day - 31 > 0)
                            {
                                day -= 31;
                                count++;
                                if (day - 31 > 0)
                                {
                                    day -= 31;
                                    count++;
                                    if (day - 30 > 0)
                                    {
                                        day -= 30;
                                        count++;
                                        if (day - 31 > 0)
                                        {
                                            day -= 31;
                                            count++;
                                            if (day - 30 > 0)
                                            {
                                                day -= 30;
                                                count++;
                                                if (day - 31 > 0)
                                                {
                                                    day -= 31;
                                                    count++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << months[count] << " ";
    cout << day;
    cout << endl;
}