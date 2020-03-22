/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 6th, 2019, 7:45 PM
 */

//Libraries
#include <cstdlib>//Random number seed
#include <iostream>//I/O Library
#include <cmath>   //Math Library
using namespace std;

//No Global Constants

//Function Prototypes
int *fillAry(int,int);      //Fill the Array
void prntAry(int *,int,int);//Print the Array
void prntMod(int *);        //Print the mode set
void swap(int *,int *);     //Swap
void minPos(int *,int,int); //Find min Position
void mrkSort(int *,int);    //Mark Sort
int *copy(const int *,int); //Copy the Array
void shuffle(int *,int,int);//Shuffle the Array
unsigned int GRB();         //Generate Random Bit
void GR(unsigned int&);     //Generate Random Number
int *mode(const int *,int); //Find the mode set

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables and fill
    int arySize,//The array/set size
         modNum,//Unique numbers in the array
           *ary;//Pointer to the array
    
    //Input the number of unique numbers
    //and size of the array
    cout<<"The program finds the mode of a set"<<endl;
    cout<<"Input the size of the array and ";
    cout<<"quantity of unique numbers"<<endl;
    cin>>arySize>>modNum;
    ary=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"The Array before shuffling"<<endl;
    prntAry(ary,arySize,modNum);
    
    //Shuffle the Array 7 times
    shuffle(ary,arySize,7);
    
    //Calculate the mode array
    int *modeAry=mode(ary,arySize);
    
    //Print the initial array
    cout<<"The Array after shuffling"<<endl;
    prntAry(ary,arySize,modNum);
    
    //Print the modal information of the array
    cout<<"The Modal Information"<<endl;
    prntMod(modeAry);
    
    //Delete allocated memory
    delete []ary;
    delete []modeAry;
    
    //Exit stage right
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    int *b=new int[n];
    //Fill with passed array
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prntMod(int *ary){
    cout<<"The number of modes = "<<
            ary[0]<<endl;
    cout<<"The max Frequency = "<<
            ary[1]<<endl;
    if(ary[0]==0){
        cout<<"The mode set = {null}"<<endl;
        return;
    }
    cout<<"The mode set = {";
    for(int i=2;i<ary[0]+1;i++){
        cout<<ary[i]<<",";
    }
    cout<<ary[ary[0]+1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        minPos(array,n,i);
    }
}

void minPos(int *array,int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(*(array+pos)>*(array+i))
            swap(array+pos,array+i);
    }
}

void swap(int *a,int *b){
    //Swap in place
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}

void prntAry(int *array,int n,int perLine){
    //Output the array
    for(int i=0;i<n;i++){
        cout<<*(array+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n, int modNum){
    //Allocate memory
    int *array=new int[n];
    
    //Fill the array with 2 digit numbers
    for(int i=0;i<n;i++){
        *(array+i)=i%modNum;
        //*(array+i)=rand()%modNum;
    }
    
    //Exit function
    return array;
}

void shuffle(int *a,int n,int nShuf){
    unsigned int temp;
    for(int shuf=1;shuf<=nShuf;shuf++){
        for(int i=0;i<n;i++){
            GR(temp);
            temp%=n;
            if(i!=temp)swap(a[i],a[temp]);
        }
    }
}

unsigned int GRB(){
    static unsigned int seed=0;
    seed += (seed * seed) | 5;
    return seed & 0x80000000;
}
 
void GR(unsigned int& value){
    value=0;
    const unsigned int numBits = sizeof(int) * 8;
    unsigned int* dataPointer = (unsigned int *)&value;
    for (unsigned int index = 0; index < numBits; ++index)
    {
        if(GRB()) {
            unsigned int pointerIndex = index / 32;
            unsigned int mask = 1 << index % 32;
            dataPointer[pointerIndex] |= mask;
        }
    }
}

//This just a stub.  You are to fill in the correct solution
int *mode(const int *array,int arySize){
    //Copy the array
    int *ary=copy(array,arySize);
    //Sort the copy
    mrkSort(ary,arySize);
    //Find the max Frequency
    int modes[arySize];
    int mode = ary[0];
    int counter = 1;
    int j = 0;
    int modearraysize = 0;
    int freq = 1;
    bool appearonce;
    
    
    // cout << "this is the sorted copied array: ";
    // for (int i = 0; i < arySize; i++)
    // {
    //     cout <<ary[i] << " ";
    // }
    // cout << endl;
    
    // cout << arySize << endl;
    for (int i = 1; i < arySize; i++)
    {
        if (mode == ary[i])
        {
            counter++;
        }
        else
        {
            // cout << "I am now finished counting " << mode << " and the size is " << counter << endl;
            mode = ary[i];
            // cout << "The new mode is " << mode << endl;
            modes[j] = counter;
            counter = 1;
            j++;
            modes[j] = counter;
            modearraysize = j;
        }
        if (i == arySize-1)
        {
            modes[j] = counter;
            modearraysize = j+1;
        }
    }
    
    // cout << "Now outputting the frequencies with size " << modearraysize << ": ";
    // for (int i = 0; i < modearraysize; i++)
    // {
    //     cout << modes[i] << " ";
    // }
    // cout << endl;
    
    
    //Find the number of modes
    
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
    // cout << "highest is " << highest << endl;
    // cout << "modearraysize is " << modearraysize << endl;
    
    for (int i = 0; i < modearraysize; i++)
    {
        if (highest == modes[i])
        {
            positions[k] = i;
            k++;
        }
    }
    
    
    
    // cout << "The highest value i found was " << highest << " and the Frequency was " << freq << endl;
    
    //Allocate the mode array
    int *modeAry = new int[modearraysize+2];
    
    //Again this is just a stub.
    // int nmodes=0;
    // int *modeAry=new int[nmodes+2];
    // modeAry[0]=0;//Stub returns no modes
    // modeAry[1]=1;//Stub returns Frequency 1
    
    int temp=0;
    //Fill the mode array
    if (highest == 1 && freq == arySize)
    {
        modeAry[0] = 0;
        modeAry[1] = 1;
    }
    else if (highest != 1)
    {
        modeAry[0] = freq;
        modeAry[1] = highest;
        // cout << "k is " << k;
        for (int i = 0; i < k; i++)
        {
            for (int m = 0; m < positions[i]; m++)
            {
                temp += modes[m];
            }
            // cout << "temp is " << temp;
            modeAry[i+2] = ary[temp];
            // cout << "this is" << modeAry[i+2];
            temp = 0;
        }
    }

    //Delete the allocated copy and return
    delete []ary;
    return modeAry;
}











