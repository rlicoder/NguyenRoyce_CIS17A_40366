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



main()
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