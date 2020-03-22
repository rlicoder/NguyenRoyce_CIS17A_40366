#include <iostream>

using namespace std;

int* getData(int &);               //Fill the array
int* sort(const int *,int);        //Sort smallest to largest
int* reverse(const int *,int);  //Sort in reverse order
void prntDat(const int *,int); //Print the array

int main()
{
    int size;
    
    cin >> size;
    
	int* array = getData(size);
	
	int* SLsort = sort(array, size);
	
	int* LSsort = reverse(array, size);
	
	prntDat(SLsort, size);
	cout << endl;
	prntDat(LSsort, size);
	
	return 0;
}

int* getData(int& size)
{
    int* array = new int[size];
    
    int i = 0;
    
    while (cin >> array[i])
    {
        i++;
        size = i;
    }
    
    return array;
}

int* sort(const int *array,int size)
{
    int* SLsort = new int[size];
    
    for (int i = 0; i < size; i++)
    {
        SLsort[i] = array[i];
    }
    
    int i, j;  
    for (i = 0; i < size-1; i++)      
    {
        for (j = 0; j < size-i-1; j++)  
        {
            if (SLsort[j] > SLsort[j+1])  
            {  
                int temp = SLsort[j];  
                SLsort[j] = SLsort[j+1];  
                SLsort[j+1] = temp;  
            }  
        }
    }
    
    return SLsort;
}

int* reverse(const int* array, int size)
{
    int* LSsort = new int[size];
    
    for (int i = 0; i < size; i++)
    {
        LSsort[i] = array[i];
    }
    
    int i, j;  
    for (i = 0; i < size-1; i++)      
    {
        for (j = 0; j < size-i-1; j++)  
        {
            if (LSsort[j] < LSsort[j+1])  
            {  
                int temp = LSsort[j];  
                LSsort[j] = LSsort[j+1];  
                LSsort[j+1] = temp;  
            }  
        }
    }
    
    return LSsort;
}

void prntDat(const int *array,int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i];
        if (i < size-1)
        {
            cout << " ";
        }
    }

}











