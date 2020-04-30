#include <bits/stdc++.h>
#include "Array.h"
#include "Stats.h"

using namespace std;


struct Prime
{
	unsigned short prime;
	unsigned char power;
};
struct Primes
{
	unsigned char nPrimes;
	Prime *prime;
};

struct account
{
    string name;
    string address;
    string accnum;
    float balance = 0;
};

struct employeedata
{
    string name;
    float payrate;
    float hoursworked;
    float amount = 0;
};

int encrypt(int code);
int decrypt(int code);
Primes *factor(int num);
void prntPrm(Primes *number);
Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array 
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure

//Functions you are to supply
Stats *stat(const Array *);     //Find & store mean, median, & modes in structure
void calculateAmounts(employeedata employees[], int j);
void displayData(employeedata employees[], int j, string companyname, string companyaddress, int placeValues[], string tens[], string onetonineteen[]);
void displayCheck(int placeValues[], string tens[], string onetonineteen[], int nocents);
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();
void prblm7();
void prblm8();


main()
{
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice)
        {
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            case '7':{prblm7();break;}
            case '8':{prblm8();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='8');
    
    return 0;
}

void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1 (bank)"<<endl;
    cout<<"Type 2 for Problem 2 (payrate)"<<endl;
    cout<<"Type 3 for Problem 3 (stats)"<<endl;   
    cout<<"Type 4 for Problem 4a (encrypt)"<<endl;
    cout<<"Type 5 for Problem 4b (decrypt)"<<endl;
    cout<<"Type 6 for Problem 5 (factorial)"<<endl;
    cout<<"Type 7 for Problem 6 (conversion)"<<endl;
    cout<<"Type 8 for Problem 7 (primes)"<<endl << endl;
    
    
}

void prblm1()
{
    account person;
    float temporary;
    int checkswritten;
    int deposits;
    
    cin.ignore(1);
    cout << "Enter the name of the account: ";
    getline(cin, person.name);
    cout << "Enter the address of the account: ";
    getline(cin, person.address);
    cout << "Enter the account number of the account: ";
    cin >> person.accnum;
    
    while (person.accnum.length() != 5)
    {
        cout << "Your account number must be 5 digits long. Try again: ";
        cin >> person.accnum;
    }
    
    
    cout << "How many check did you write this month? ";
    cin >> checkswritten;

    if (checkswritten > 0)
    {
        cout << "Enter all amounts written in the check: ";
    }    
    for (int i = 0; i < checkswritten; i++)
    {
        cin >> temporary;
        person.balance -= temporary;
    }
    
   
    cout << "How many deposits did  you make this month? ";
    cin >> deposits;

    if (deposits > 0)
    {
        cout << "Enter all the deposit amount for this month";
    }
    for (int i = 0; i < deposits; i++)
    {
        cin >> temporary;
        person.balance += temporary;
    }
    
    cout << "Hello, " << person.name << endl;
    cout << "Your address is " << person.address << endl;
    cout << "Your account number is " << person.accnum << endl;
    cout << "Your account balance is " << person.balance << endl;
    if (person.balance < 0)
    {
        person.balance -= 20;
        cout << "Your account has been deducted 20 dollars for being overdrawn. ";
        cout << "Your new account balance is: " << person.balance << endl;
    }
    
}

void prblm2()
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

void prblm3()
{
    //Declare variables
    int arySize;//Array Size
    int modNum; //Number to control the modes (digits 0 to 9 allowed)
    Array *array;
    
    //Input the size and mod number
    cout<<"This program develops an array to be analyzed"<<endl;
    cout<<"Array size from mod number to 100"<<endl;
    cout<<"Mod number from 2 to 10"<<endl;
    cout<<"Input the Array Size and the mod number to be used."<<endl;
    cin>>arySize>>modNum;
    cout<<endl<<endl;
    
    //Fill the array
    array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array before sorting"<<endl;
    prntAry(array,10);
    
    //Sort the array
    mrkSort(array->data,array->size);
    cout<<"Sorted Array to be utilize for the stat function"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
    
    //Exit stage right

}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}

Stats *stat(const Array *array){
    //Non-working stub to be completed by the student
    cout<<endl<<"Stat function to be completed by the student"<<endl;
    Stats *stats=new Stats;
    stats->mode=new Array;
    
    //average finder
    float total = 0;
    for (int i = 0; i < array->size; i++)
    {
        total += array->data[i];
    }
    stats->avg = total/array->size;
    
    //median finder
    if (array->size%2 == 0)
    {
        float holder = static_cast<float>((array->data[array->size/2-1] + array->data[array->size/2]));
        stats->median = holder/2;
    }
    else 
    {
        stats->median = array->data[static_cast<int>(array->size/2)];
    }
    
    int modes[array->size];
    int mode = array->data[0];
    int counter = 1;
    int j = 0;
    int modearraysize = 0;
    int freq = 1;
    
    
    for (int i = 1; i < array->size; i++)
    {
        if (mode == array->data[i])
        {
            counter++;
        }
        else
        {
            mode = array->data[i];
            modes[j] = counter;
            counter = 1;
            j++;
            modes[j] = counter;
            modearraysize = j;
        }
        if (i == array->size-1)
        {
            modes[j] = counter;
            modearraysize = j+1;
        }
    }
    
    int highest = modes[0];
    
    for (int i = 1; i < modearraysize; i++)
    {
        if (highest < modes[i])
        {
            highest = modes[i];
            freq = 1;
        }
        else if (highest == modes[i])
        {
            freq++;
        }
    }
    
    int* positions = new int[modearraysize];
    int k = 0;
    
    for (int i = 0; i < modearraysize; i++)
    {
        if (highest == modes[i])
        {
            positions[k] = i;
            k++;
        }
    }
    
    int temp=0;
    //Fill the mode array
    if (highest == 1 && freq == array->size)
    {
        stats->mode->size = 0;
        stats->modFreq = 1;
    }
    else if (highest != 1)
    {
        stats->mode->size = freq;
        stats->modFreq = highest;
//         cout << "k is " << k;
        stats->mode->data=new int[freq];
        for (int i = 0; i < k; i++)
        {
            for (int m = 0; m < positions[i]; m++)
            {
                temp += modes[m];
            }
            // cout << "temp is " << temp;
            stats->mode->data[i] = array->data[temp];
            // cout << "this is" << modeAry[i+2];
            temp = 0;
        }
    }
    
   

    return stats;
}

void prblm4()
{
    int code;
    int encrypted;
    
    
    cout << "Enter the 4 digit code to by encrypted: ";
    cin >> code;
    
    encrypted = encrypt(code);
    cout << encrypted;
    
}



int decrypt(int code)
{
    int thousands = code / 1000;
    int hundreds = (code - (thousands * 1000))/ 100;
    int tens = (code - (thousands * 1000) - (hundreds * 100))/10;
    int ones = code - (thousands * 1000) - (hundreds * 100) - (tens * 10);

    int newnum[4];
    newnum[0] = tens;
    newnum[1] = ones;
    newnum[2] = thousands;
    newnum[3] = hundreds;
   
    for (int i = 0; i < 4; i++)
    {
        if (newnum[i] == 5 || newnum[i] == 6 || newnum[i] == 7)
        {
            newnum[i] -= 5;
        }
        else if (newnum[i] >= 0 && newnum[i] <= 4)
        {
            newnum[i] = newnum[i] + 8 - 5;
        }
    }
    
    
    int newnumber = (newnum[0]*1000) + (newnum[1]*100) + (newnum[2]*10) + newnum[3];
    return newnumber;
}

void prblm5()
{
    int code;
    int decrypted;
    
    
    cout << "Enter the 4 digit code to by decrypted: ";
    cin >> code;
    
    decrypted = decrypt(code);
    cout << decrypted << endl;
    
}


void prblm6()
{
    signed char a = 0;
    unsigned char b = 0;
    
    signed int c = 0;
    unsigned int d = 0;
    
    float e = 0;
    
    double f = 0;

    signed short g = 0;
    unsigned short h = 0;
    
    signed long i = 0;
    unsigned long j = 0;
    
    signed long long k = 0;
    unsigned long long l = 0;
    
    long double m;
    
    cout << "The largest factorial a signed char can take is: 5!" << endl;
    cout << "The largest factorial an unsigned char can take is: 5!" << endl;
    cout << "The largest factorial a signed int can take is: 12!" << endl;
    cout << "The largest factorial an unsigned int can take is: 12!" << endl;
    cout << "The largest factorial a signed float can take is: 11!" << endl;
    cout << "The largest factorial a signed double can take is: 11!" << endl;
    cout << "The largest factorial a signed short can take is: 7!" << endl;
    cout << "The largest factorial an unsigned short can take is: 8!" << endl;
    cout << "The largest factorial a signed long can take is: 12!" << endl;
    cout << "The largest factorial an unsigned long can take is: 12!" << endl;
    cout << "The largest factorial a signed long long can take is: 20!" << endl;
    cout << "The largest factorial an unsigned long long can take is: 20!" << endl;
    cout << "The largest factorial a long double can take is: 11!" << endl;
    
}

void prblm7()
{
    cout << "The conversion from 2.875 base 10 is: " << endl;
    cout << "Base 2:  10.111" << endl;
    cout << "Base 8:  2.7" << endl;
    cout << "Base 16: 2.E" << endl;
    cout << "NASA Float  : 0101 1100 0000 0000 0000 0000 0000 0010" << endl;
    cout << "8 nibble hex:  5    C    0    0    0    0    0    2" << endl << endl;
    
    cout << "The conversion from .1796875 base 10 is: " << endl;
    cout << "Base 2:  0.0010111" << endl;
    cout << "Base 8:  0.134" << endl;
    cout << "Base 16: 0.2E" << endl << endl;
    cout << "NASA Float  : 0101 1100 0000 0000 0000 0000 1111 1110" << endl;
    cout << "8 nibble hex:  5    C    0    0    0    0    F    E" << endl << endl;
    
    cout << "The conversion from -2.875 base 10 is: " << endl;
    cout << "Base 2:  -10.111" << endl;
    cout << "Base 8:  -2.7" << endl;
    cout << "Base 16: -2.E" << endl << endl;
    cout << "NASA Float  : 1010 0100 0000 0000 0000 0000 0000 0010" << endl;
    cout << "8 nibble hex:  A    4    0    0    0    0    0    2" << endl << endl;
    
    cout << "The conversion from -.1796875 base 10 is: " << endl;
    cout << "Base 2:  -0.0010111" << endl;
    cout << "Base 8:  -0.134" << endl;
    cout << "Base 16: -0.2E" << endl << endl;
    cout << "NASA Float  : 1010 0100 0000 0000 0000 0000 1111 1110" << endl;
    cout << "8 nibble hex:  A    4    0    0    0    0    F    E" << endl << endl;
    
    cout << "59999901 to decimal is 1.399996877" << endl;
    cout << "59999902 to decimal is 2.799999714" << endl;
    cout << "A66667FE to decimal is -.1749999821" << endl;
    
    
}

void prblm8()
{
    int num;
    
    cout << "Enter the number that you'd like the prime factors of: ";
    cin >> num;
    
    Primes* number = factor(num);
    prntPrm(number);
}

Primes *factor(int num)
{
    Primes* stubbydubbywubby = new Primes;
    int count;
    int othercount = 0;
    
    stubbydubbywubby->prime = new Prime[13];
    
    for (int i = 2; i <= num; i++)
    {
        count = 0;
        if (num % i == 0)
        {
            count++;
            num /= i;
            while (num%i==0)
            {
                num /= i;
                count++;
            }
        }
        if (count != 0)
        {
            
            stubbydubbywubby->prime[othercount].prime = i;
            stubbydubbywubby->prime[othercount].power = count + '0';
            cout <<  "total count for " << i << " was " << count << endl;
            othercount++;
        }
    }
    
    stubbydubbywubby->nPrimes = othercount + '0';
    
    
    return stubbydubbywubby;
}

void prntPrm(Primes *number)
{
    int realnumber = 1;
    
    int j = static_cast<int>(number->nPrimes - '0');

    for (int i = 0; i < j; i++)
    {
        int k = static_cast<int>(number->prime[i].power - '0');
        realnumber *= pow(number->prime[i].prime,k);
    }
    
    
    cout << "The prime factors of " << realnumber << " is: ";
    for (int i = 0; i < j; i++)
    {
        cout << number->prime[i].prime << "^" << number->prime[i].power;
        if (i != j-1)
        {
            cout << " * ";
        }
    }
    cout << endl;
}

int encrypt(int code)
{
   int thousands = code / 1000;
   int hundreds = (code - (thousands * 1000))/ 100;
   int tens = (code - (thousands * 1000) - (hundreds * 100))/10;
   int ones = code - (thousands * 1000) - (hundreds * 100) - (tens * 10);
   
   int newthousands = (thousands+5) % 8;
   int newhundreds = (hundreds+5) % 8;
   int newtens = (tens+5) % 8;
   int newones = (ones+5) % 8;
   
   int newnumber = 0;
   newnumber += (newtens * 1000);
   newnumber += (newones*100);
   newnumber += (newthousands*10);
   newnumber += (newhundreds);
   
   return newnumber;
}