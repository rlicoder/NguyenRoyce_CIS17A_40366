#include <bits/stdc++.h>

using namespace std;

class Prob1Random
{
    private:
            char *set;      //The set of numbers to draw random numbers from
            char  nset;     //The number of variables in the sequence
            int  *freq;     //Frequency of all the random numbers returned
            int   numRand;  //The total number of times the random number function is called
    public:
            Prob1Random(const char,const char *);     //Constructor
            ~Prob1Random(void);                       //Destructor
            char randFromSet(void);                   //Returns a random number from the set
            int *getFreq(void) const;                 //Returns the frequency histogram
            char *getSet(void) const;                 //Returns the set used
            int getNumRand(void) const;               //Gets the number of times randFromSet has
                                                      //been called
};

class SavingsAccount
{
    public:
        SavingsAccount(float);               //Constructor
        void  Transaction(float);            //Procedure
        float Total(float=0,int=0);	         //Savings Procedure
        float TotalRecursive(float=0,int=0);
        void  toString();                    //Output Properties
    private:
        float Withdraw(float);               //Utility Procedure
        float Deposit(float);                //Utility Procedure
        float Balance;                       //Property
        int   FreqWithDraw;                  //Property
        int   FreqDeposit;                   //Property
};

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

template<class T>
class Prob2Sort
{
	private:
            int *index;                                 //Index that is utilized in the sort
	public:
            Prob2Sort(){index=NULL;};                   //Constructor
            ~Prob2Sort(){delete []index;};              //Destructor
            T * sortArray(const T*,int,bool);           //Sorts a single column array
            T * sortArray(const T*,int,int,int,bool);   //Sorts a 2 dimensional array represented as a 1 dim array
}; 

template<class T>
class Prob3Table
{
	protected:
		int rows;                                 //Number of rows in the table
		int cols;                                 //Number of cols in the table
		T *rowSum;                                //RowSum array
		T *colSum;                                //ColSum array
		T *table;                                 //Table array
		T grandTotal;                             //Grand total
		void calcTable(void);                     //Calculate all the sums
	public:
		Prob3Table(char* filename , int srows, int scols)
                {
                    this->rows = srows;
                    this->cols = scols;
                    this->rowSum = new T[srows];
                    this->colSum = new T[scols];
                    this->grandTotal = 0;
                    
                    this->table = new T[srows*scols];
                    
                    ifstream infile;
                    
                    infile.open(filename, ios::in);
                    
                    for (int i = 0; i < srows*scols && !infile.eof(); i++)
                    {
                        infile >> this->table[i];
                    }
                    
                    infile.close();
                    
                    this->calcTable();
                }//Constructor then Destructor
		~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
		const T *getTable(void){return table;};
		const T *getRowSum(void){return rowSum;};
		const T *getColSum(void){return colSum;};
		T getGrandTotal(void){return grandTotal;};
};

template<class T>
class Prob3TableInherited:public Prob3Table<T>
{
	protected:
		T *augTable;                                  //Augmented Table with sums
	public:
		Prob3TableInherited(char* filename, int srows, int scols) : Prob3Table<T>(filename, srows, scols)
                {
                    augTable = new T[(srows + 1) * (scols + 1)];
                    
                    for(int i=0;i<=srows;i++)
                    {
                        for(int j=0;j<=scols;j++)
                        {
                            augTable[(scols+1) * i + j] = this->table[i*scols+j];
                        }
                    }
                    
                    for (int i = 0; i < srows; i++)
                    {
                        augTable[(scols+1) * i + scols] = this->rowSum[i];
                    }

                    
                    for (int i = 0; i < scols; i++)
                    {
                        augTable[(scols+1) * srows + i] = this->colSum[i];
                    }

                    
                    augTable[(srows + 1) * (scols + 1) - 1] = this->grandTotal;
                    
                }
		~Prob3TableInherited()
                {
                    delete [] augTable;
                }  //Destructor
		const T *getAugTable(void){return augTable;}
};

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
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='8');
    
    return 0;
}

void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1 (Prob1Random)"<<endl;
    cout<<"Type 2 for Problem 2 (All Kinds of Sorting)"<<endl;
    cout<<"Type 3 for Problem 3 (Spreadsheet Stuff)"<<endl;   
    cout<<"Type 4 for Problem 4 (Savings Account Class)"<<endl;
    cout<<"Type 5 for Problem 5 (Employee Class)"<<endl;
    cout<<"Type 6 for Problem 6 (Conversions)"<<endl;
}

Prob1Random::Prob1Random(const char size, const char* rndseq)
{
    set = new char[static_cast<int>(size)];
    freq = new int[static_cast<int>(size)];
    
    numRand = 0;
    
    for (int i = 0; i < static_cast<int>(size); i++)
    {
        set[i] = *(rndseq + i);
        freq[i] = 0;
    }
}

Prob1Random::~Prob1Random()
{
    delete[] set;
    delete[] freq;
}

char Prob1Random::randFromSet()
{
    int random = (rand() % 5);
    
    freq[random]++;
    
    numRand++;
    
    return set[random];
}

int* Prob1Random::getFreq() const 
{
    return freq;
}

char* Prob1Random::getSet(void) const
{
    return set;
}

int Prob1Random::getNumRand(void) const
{
    return numRand;
}

void prblm1()
{
    srand(time(0));
    char n=5;
    char rndseq[]={18,33,56,79,125};
    int ntimes=100000;
    Prob1Random a(n,rndseq);
    for(int i=1;i<=ntimes;i++)
    {
        a.randFromSet();
    }
    int *x = a.getFreq();
    char *y=a.getSet();
    for(int i=0;i<n;i++)
    {
        cout<<int(y[i])<<" occurred "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
}

void prblm2()
{
    cout<<"The start of Problem 2, the sorting problem"<<endl;
    Prob2Sort<char> rc;
    bool ascending=true;
    ifstream infile;
    infile.open("Problem2.txt",ios::in);
    char *ch2=new char[10*16];
    char *ch2p=ch2;
    while(infile.get(*ch2)){cout<<*ch2;ch2++;}
    infile.close();
    cout<<endl;
    cout<<"Sorting on which column"<<endl;
    int column;
    cin>>column;
    char *zc=rc.sortArray(ch2p,10,16,column,ascending);
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<16;j++)
        {
            cout<<zc[i*16+j];
        }
    }
    delete []zc;
    cout<<endl;
}

template <class T>
T* Prob2Sort<T>::sortArray(const T* array, int rows, int cols, int columnsort, bool ascending)
{
    T* colAry = new T[rows];
    T* cpyAry = new T[rows*cols+rows];
    
    for (int i = 0; i < rows; i++)
    {
        colAry[i] = array[i*(cols)+columnsort-1+i];
    }
    
    for (int i = 0; i < rows ; i++)
    {
        cpyAry[cols * i + (cols-1)] = '\n';
    }
    
    sortArray(colAry, rows, ascending);
    
    int k = 0;
    for (int i = rows - 1; i >= 0; i--)
    {
        for (int j = 0; j < cols - 1; j++)
        {
            cpyAry[i * cols + j] = array[((cols-2) * index[k]) + (3 * index[k] + j)];
        }
        k++;
    }
    
    
    
    return cpyAry;
}

template <class T>
T* Prob2Sort<T>::sortArray(const T* array, int size, bool ascending)
{
    bool swap;
    T temp;
    int tempint;
    
    index = new int[size];
    T* cpyAry = new T[size];
    
    for (int i = 0; i < size; i++)
    {
        index[i] = i;
        cpyAry[i] = array[i];
    }
    
    do
    {
        swap = false;
        for (int count = 0; count < (size - 1); count++)
        {
            if (ascending)
            {
                if (cpyAry[count] > cpyAry[count + 1])
                {
                    temp = cpyAry[count];
                    cpyAry[count] = cpyAry[count + 1];
                    cpyAry[count + 1] = temp;
                    
                    tempint = index[count];
                    index[count] = index[count + 1];
                    index[count + 1] = tempint;
                    
                    swap = true;
                }
            }
            else if (!ascending)
            {
                if (cpyAry[count] < cpyAry[count + 1])
                {
                    temp = cpyAry[count];
                    cpyAry[count] = cpyAry[count + 1];
                    cpyAry[count + 1] = temp;
                    
                    tempint = index[count];
                    index[count] = index[count + 1];
                    index[count + 1] = tempint;
                    
                    swap = true;
                }
            }
        }
    } while (swap);
    
    
    return cpyAry;
    
}


void prblm3()
{
    cout<<"Entering problem number 3"<<endl;
    int rows=5;
    int cols=6;
    Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
    const int *naugT=tab.getTable();
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<naugT[i*cols+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++)
    {
        for(int j=0;j<=cols;j++)
        {
            cout<<augT[i*(cols+1)+j]<<" ";
        }
        cout<<endl;
    }
}

template<class T>
void Prob3Table<T>::calcTable()
{
    T total = 0;
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            total += table[i*cols+j];
        }
        rowSum[i] = total;
        total = 0;
    }
    
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            total += table[j*cols+i];
        }
        colSum[i] = total;
        total = 0;
    }
    
    for (int i = 0; i < rows; i++)
    {
        grandTotal += rowSum[i];
    }
}



void prblm4()
{
    SavingsAccount mine(-300);

    for(int i=1;i<=10;i++)
    {
        mine.Transaction((float)(rand()%500)*(rand()%3-1));
    }
    mine.toString();
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.Total((float)(0.10),7)<<endl;
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.TotalRecursive((float)(0.10),7)
        <<" Recursive Calculation "<<endl;
}

SavingsAccount::SavingsAccount(float dummy)
{
    if (dummy > 0)
    {
        Balance = dummy;
    }
    else 
    {
        Balance = 0;
    }
    FreqDeposit = 0;
    FreqWithDraw = 0;
}

void SavingsAccount::Transaction(float dummy)
{
    if (dummy > 0)
    {
        Deposit(dummy);
    }
    else if (dummy < 0)
    {
        Withdraw(dummy);
    }
}

float SavingsAccount::Deposit(float dummy)
{
    Balance += dummy;
    FreqDeposit++;
}

float SavingsAccount::Withdraw(float dummy)
{
    if (Balance + dummy < 0)
    {
        cout << "Error: You cannot withdraw more than currently in your balance.\n";
    }
    else if (Balance - dummy > 0)
    {
        Balance += dummy;
        FreqWithDraw++;
    }
}

void SavingsAccount::toString()
{
    cout << "Your balance is: " << setprecision(2) << fixed << Balance << endl;
    cout << "Your Withdrawal Frequency is: " << FreqWithDraw << endl;
    cout << "Your Deposit Frequency is: " << FreqDeposit << endl;
    
    cout << endl;
}

float SavingsAccount::Total(float savint, int time)
{
    return Balance*(pow((1+savint), time));
}

float SavingsAccount::TotalRecursive(float interestrate, int interesttime)
{
    if (interesttime != 0)
    {
        return (interestrate + 1) * TotalRecursive(interestrate, --interesttime);
    }
    else if (interesttime == 0)
    {
        return Balance;
    }
}

void prblm5()
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

void prblm6()
{
    cout << "For case a: 3.75 " << endl;
    cout << "In Base 2: 11.11 " << endl;
    cout << "In Base 8: 3.6" << endl;
    cout << "In Base 16: 3.C" << endl;
    cout << "In NASA: 0111 1000 0000 0000 0000 0000 0000 0010" << endl;
    cout << "In scaled binary max 1 byte: 3C x 16^-1" << endl;
    cout << "Multiplied by 7: 420" << endl;
    cout << "In IEEE 754: 0100 0000 0111 0000 0000 0000 0000 0000" << endl;
    cout << endl;
    
    cout << "For case b: .7 " << endl;
    cout << "In Base 2: 0.101100110011 " << endl;
    cout << "In Base 8: 0.546314 or 0.546315 (rounded)" << endl;
    cout << "In Base 16: 0.B333333" << endl;
    cout << "In NASA: 0101 1001 1001 1001 1001 1001 0000 0000" << endl;
    cout << "In scaled binary max 2 byte: B333 x 16^-4" << endl;
    cout << "Multiplied by 7: 321125" << endl;
    cout << "In IEEE 754: 0011 1111 0011 0011 0011 0011 0011 0011" << endl;
    cout << endl;
    
    cout << "For case a: 89.9 " << endl;
    cout << "In Base 2: 1011001.1110011001100 " << endl;
    cout << "In Base 8: 131.7146314" << endl;
    cout << "In Base 16: 59.E666" << endl;
    cout << "In NASA: 0101 1001 1110 0110 0110 0110 0000 0111" << endl;
    cout << "In scaled binary max 3 byte: 59E666 x 16^-4" << endl;
    cout << "Multiplied by 7: 41241802" << endl;
    cout << "In IEEE 754: 0100 0010 1011 0011 1100 1100 1100 1101" << endl;
    cout << endl;
}