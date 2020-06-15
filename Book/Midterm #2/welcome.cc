#include <bits/stdc++.h>

using namespace std;

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

main()
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