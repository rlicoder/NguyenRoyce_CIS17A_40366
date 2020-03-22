#include <iostream>
#include <iomanip>

using namespace std;

int *getData(int&);
void prntDat(int *, int);
float *median(int *, int);
void prntMed(float *);


int main()
{
    int size;
    
	cin >> size;
	
	int* array = getData(size);
	prntDat(array, size);
	float* fltAry = median(array, size);
    prntMed(fltAry);
	
	
	return 0;
}

int *getData(int& size)
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

void prntDat(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i];
        if (i < size-1)
        {
            cout << " ";
        }
    }
    cout << endl;
}

float *median(int* array, int size)
{
    float* fltAry = new float[size+2];
    
    fltAry[0] = static_cast<float>(size+2);
    
    for (int i = 0; i < size; i++)
    {
        fltAry[i+2] = static_cast<float>(array[i]);
    }
    
    
    int i, j;  
    for (i = 0; i < size-1; i++)      
    {
        for (j = 0; j < size-i-1; j++)  
        {
            if (array[j] > array[j+1])  
            {  
                int temp = array[j];  
                array[j] = array[j+1];  
                array[j+1] = temp;  
            }  
        }
    }
    
    if (size%2 == 0)
    {
        float holder = static_cast<float>((array[size/2-1] + array[size/2]));
        fltAry[1] = holder/2;
    }
    else 
    {
        fltAry[1] = array[static_cast<int>(size/2)];
    }
    

    return fltAry;
}

void prntMed(float* fltAry)
{
    cout << fltAry[0] << " ";
    for (int i = 1; i < static_cast<int>(fltAry[0]); i++)
    {
        cout << showpoint << fixed << setprecision(2) << fltAry[i];
        if (i < static_cast<int>(fltAry[0])-1)
        {
            cout << " ";
        }
    }
}
















