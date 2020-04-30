#include <bits/stdc++.h>

using namespace std;

struct employeedata
{
    string name;
    float payrate;
    float hoursworked;
    float amount = 0;
};

void calculateAmounts(employeedata employees[], int j);
void displayData(employeedata employees[], int j, string companyname, string companyaddress, int placeValues[], string tens[], string onetonineteen[]);
void displayCheck(int placeValues[], string tens[], string onetonineteen[], int nocents);

main()
{
    string companyname;
    string companyaddress;
    employeedata employees[100];
    int i = 0;
    int placeValues[6];
    string tens[8] = { "twenty", "thirty", "forty", "fifty", "sixty",
                       "seventy", "eighty", "ninety" };

    string onetonineteen[19] = {"one", "two", "three", "four", "five", "six",
                                "seven", "eight", "nine", "ten", "eleven",
                                "twelve", "thirteen", "fourteen", "fifteen",
                                "sixteen", "seventeen", "eighteen", "nineteen"};
    
    cout << "Enter the company name: ";
    getline(cin, companyname);
    cout << "Enter the company address: ";
    getline(cin, companyaddress);

    
    do
    {
        cout << "Enter the name of the employee: ";
        getline(cin, employees[i].name);
        cout << "Enter the payrate of the employee: ";
        cin >> employees[i].payrate;
        cout << "Enter the hours worked of the employee: ";
        cin >> employees[i].hoursworked;
        i++;
        cin.ignore(1);
    }
    while (employees[i-1].payrate > 0 && employees[i-1].hoursworked > 0);
    
    i--;
    
    calculateAmounts(employees, i);
    displayData(employees, i, companyname, companyaddress, placeValues, tens, onetonineteen);
}

void calculateAmounts(employeedata employees[], int j)
{
    for (int i = 0; i < j; i++)
    {
        if (employees[i].hoursworked <= 40)
        {
            employees[i].amount = employees[i].hoursworked * employees[i].payrate;
            int temp = employees[i].amount * 100 + .5;
            cout << temp << endl;
            employees[i].amount = static_cast<float>(temp) / 100;
            cout <<  employees[i].amount << endl;
        }
        else if (employees[i].hoursworked > 40 && employees[i].hoursworked <= 50)
        {
            employees[i].amount = employees[i].payrate * 40;
            employees[i].amount += ((employees[i].hoursworked-40) * (2*employees[i].payrate));
            int temp = employees[i].amount * 100 + .5;
            employees[i].amount = static_cast<float>(temp) / 100;
        }
        else if (employees[i].hoursworked > 50)
        {
            employees[i].amount = employees[i].payrate * 40;
            employees[i].amount += (10) * (2*employees[i].payrate);
            int temp = employees[i].amount * 100 + .5;
            employees[i].amount = static_cast<float>(temp) / 100;
            employees[i].amount += ((employees[i].hoursworked-50) * (3*employees[i].payrate));
            int temp1 = employees[i].amount * 100 + .5;
            employees[i].amount = static_cast<float>(temp1)/100;
        }
    }
}

void displayData(employeedata employees[], int j, string companyname, string companyaddress, int placeValues[], string tens[], string onetonineteen[])
{
    
    for (int i = 0; i < j; i++)
    {
        cout << companyname << endl;
        cout << companyaddress << endl;
        cout << employees[i].name << setw(15) << employees[i].amount << endl;
        int nocents = employees[i].amount * 100 + .5;
        displayCheck(placeValues, tens, onetonineteen, nocents);
        cout << endl;
        cout << "Signature:__________________________________" << endl;
        cout << endl << endl << endl;
    }
    
}

void displayCheck(int placeValues[], string tens[], string onetonineteen[], int nocents)
{
	int thousands = nocents / 100000;
	int hundreds = (nocents - (100000 * thousands)) / 10000;
	int ten = ((nocents - (100000 * thousands)) - (10000 * hundreds)) / 1000;
	int ones = (((nocents - (100000 * thousands)) - (10000 * hundreds)) - 
			   (1000 * ten)) / 100;
	int centsTenths = ((((nocents - (100000 * thousands)) - (10000 * hundreds)) -
                        (1000 * ten)) - (100 * ones)) / 10;
	int centsHundreths = ((((nocents - (100000 * thousands)) -
                            (10000 * hundreds)) - (1000 * ten)) - 
                            (100 * ones) - (10 * centsTenths));
	
        
	placeValues[0] = thousands;
	placeValues[1] = hundreds;
	placeValues[2] = ten;
	placeValues[3] = ones;
	placeValues[4] = centsTenths;
	placeValues[5] = centsHundreths;
	//THOUSANDS
	if (placeValues[0] > 0)
	{
		cout << onetonineteen[placeValues[0] - 1] << " thousand ";
	}
	//HUNDREDS
	if (placeValues[1] > 0)
		cout << onetonineteen[placeValues[1] - 1] << " hundred ";

	//TENS
	if (placeValues[2] > 1)
	{
		//OUTPUTTING TEN MULTIPLE IF GREATER THAN 1
		cout << tens[placeValues[2] - 2] << " ";
		
		//OUTPUTTING ONES
		if (placeValues[3] > 0)
		{
			cout << onetonineteen[placeValues[3] - 1];
			cout << " dollars";
		}
		//IF EQUAL TO ZERO IN ONES DIGIT
		//DEFAULT DOLLARS STATEMENT
		else
			cout << "dollars";
	}
	//OUTPUTTING 1-19 (NO FORMAT IN ENGLISH)
	else if (placeValues[2] == 1)
	{
		cout << onetonineteen[(placeValues[2] * 10 + placeValues[3]) - 1];
		cout << " dollars";
	}
	//IF TENS IS ZERO
	else if (placeValues[2] == 0)
	{
		//IF THERE IS A VALUE IN ONES
		if (placeValues[3] != 0)
		{
			//OUTPUTTING 1-9 DOLLARS IN STRING
			cout << onetonineteen[placeValues[3] - 1];
			//PLURAL DOLLARS
			if (placeValues[3] > 1)
			{
				cout << " dollars";
			}
			//SINGULAR DOLLAR
			else if (placeValues[3] == 1)
			{
				cout << " dollar";
			}
		}
		//AVOIDING OUTPUT OF ONE THOUSAND ZERO DOLLARS SINCE THOUSAND AND 
		//HUNDREDS ARE IN THEIR OWN IF STATEMENTS
		else if (placeValues[0] == 0 && placeValues[1] == 0)
			cout << "zero dollars";
		//DEFAULT STATEMENT
		else if (placeValues[0] != 0 || placeValues[1] != 0)
			cout << "dollars";
	}
	//ERROR CHECK
	else
		cout << "error! in tens";

	//CENTS
	cout << " and ";
	//IF TENS MULTIPLE FOR CENTS IS TRUE AND NOT 1-19 (NO ENGLISH FORMAT)
	if (placeValues[4] > 1)
	{
		//OUTPUTTING TEN MULTIPLE IS STRINGS
		cout << tens[placeValues[4] - 2] << " ";
		//OUTPUTTING 1-19 VALUE BECAUSE "ZERO" IS NOT INCLUDED IN ARRAY
		if (placeValues[5] > 0)
		{
			cout << onetonineteen[placeValues[5] - 1];
			cout << " cents";
		}
		//FOR CENTSHUNDRETHS == 0 FOR MULTIPLES OF TENS
		else
			cout << " cents";
	}
	//FOR IRREGULAR ARRAY 1-19
	else if (placeValues[4] == 1)
	{
		cout << onetonineteen[(placeValues[4] * 10 + placeValues[5]) - 1];
		cout << " cents";
	}
	else if (placeValues[4] == 0)
	{
		//IF THERE IS A VALUE IN CENT HUNDRETHS ONLY
		if (placeValues[5] != 0)
		{
			//OUTPUTTING 1-9 IN STRING
			cout << onetonineteen[placeValues[5] - 1];
			//PLURAL CENTS
			if (placeValues[5] > 1)
			{
				cout << " cents";
			}
			//SINGLUAR CENT
			else if (placeValues[5] == 1)
			{
				cout << " cent";
			}
		}
		//IF BOTH CENTS DIGITS ARE ZERO
		else
			cout << "zero cents";
	}
	//ERROR CHECK
	else
		cout << "error! in cents";

}