#include <bits/stdc++.h>

using namespace std;

class Employee
{
    public:
            Employee(char[],char[],float);  //Constructor
            float  CalculatePay(float,int); //Procedure
            float  getGrossPay(float,int);  //Procedure
            float  getNetPay(float);        //Procedure
            void   toString();              //Procedure
            int    setHoursWorked(int);     //Procedure
            float  setHourlyRate(float);    //Procedure
	private:
            double Tax(float);      //Utility Procedure
            char   MyName[20];      //Property
            char   JobTitle[20];    //Property
            float  HourlyRate;      //Property
            int    HoursWorked;     //Property
            float  GrossPay;        //Property
            float  NetPay;          //Property
};

main()
{
    	Employee Mark("Mark","Boss",215.50);
	Mark.setHoursWorked(-3);
	Mark.toString();
	Mark.CalculatePay(Mark.setHourlyRate(20.0),
		Mark.setHoursWorked(25));
	Mark.toString();
	Mark.CalculatePay(Mark.setHourlyRate(40.0),
		Mark.setHoursWorked(25));
	Mark.toString();
	Mark.CalculatePay(Mark.setHourlyRate(60.0),
		Mark.setHoursWorked(25));
	Mark.toString();

	Employee Mary("Mary","VP",50.0);
	Mary.toString();
	Mary.CalculatePay(Mary.setHourlyRate(50.0),
		Mary.setHoursWorked(40));
	Mary.toString();
	Mary.CalculatePay(Mary.setHourlyRate(50.0),
		Mary.setHoursWorked(50));
	Mary.toString();
	Mary.CalculatePay(Mary.setHourlyRate(50.0),
		Mary.setHoursWorked(60));
	Mary.toString();
}

Employee::Employee(char name[], char job[], float hourlyrate)
{
    strcpy(MyName, name);
    strcpy(JobTitle, job);
    setHourlyRate(hourlyrate);
    HoursWorked = 0;
    GrossPay = 0;
    NetPay = 0;
}

double Employee::Tax(float dummy)
{
    if (dummy > 0 && dummy <= 500)
    {
        return .1 * dummy;
    }
    else if (dummy <= 1000 && dummy > 500)
    {
        return .2 * dummy;
    }
    else if (dummy > 1000)
    {
        return .3 * dummy;
    }
}

int Employee::setHoursWorked(int dummy)
{
    if (dummy > 0 && dummy < 84)
    {
        HoursWorked = dummy;
        return dummy;
    }
    else 
    {
        cout << "Invalid hours input" << endl;
        HoursWorked = 0;
        return HoursWorked;
    }
    
}

float Employee::setHourlyRate(float dummy)
{
    if (dummy > 0 && dummy < 200)
    {
        HourlyRate = dummy;
        return dummy;
    }
    else
    {
        cout << "Invalid Hourly Rate" << endl;
        HourlyRate = 0;
        return HourlyRate;
    }
}


void Employee::toString()
{
    cout << "Name: " << MyName << endl;
    cout << "Job Title: " << JobTitle << endl;
    cout << "Hourly Rate: " << HourlyRate << endl;
    cout << "Hours Worked: " << HoursWorked << endl;
    cout << "Gross Pay: " << GrossPay << endl;
    cout << "Net Pay: " << NetPay << endl;
    cout << endl;
}

float Employee::getNetPay(float dummy)
{
    NetPay = dummy - Tax(dummy);
    return dummy - Tax(dummy);
}

float Employee::getGrossPay(float x, int y)
{
    if (HoursWorked <= 40)
    {
        GrossPay = HourlyRate * HoursWorked;
        return HourlyRate * HoursWorked;
    }
    else if (HoursWorked > 40 && HoursWorked <= 50)
    {
        GrossPay = (HourlyRate * 40) + ((HourlyRate * 1.5) * (HoursWorked - 40));
        return (HourlyRate * 40) + ((HourlyRate*1.5) * (HoursWorked - 40));
    }
    else if (HoursWorked > 50)
    {
        GrossPay = (HourlyRate * 40) + ((HourlyRate*1.5) * (10)) + ((HourlyRate * 2) * (HoursWorked - 50));
        return (HourlyRate * 40) + ((HourlyRate*1.5) * (10)) + ((HourlyRate * 2) * (HoursWorked - 50));
    }
    
}

float Employee::CalculatePay(float x, int y)
{
    return getNetPay(getGrossPay(setHourlyRate(x) ,setHoursWorked(y)));
}

