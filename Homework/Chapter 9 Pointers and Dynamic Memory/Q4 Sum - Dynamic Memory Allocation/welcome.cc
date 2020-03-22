#include <iostream>

using namespace std;

int *getData(int &);             //Return the array size and the array from the inputs

int *sumAry(const int *,int);//Return the array with successive sums

void prntAry(const int *,int);//Print the array

int main()
{
    int size;
    
	cin >> size;
	
	int* array = getData(size);
	
	int* sumArray = sumAry(array, size);
	
	prntAry(array, size);
	
	cout << endl;
	
	prntAry(sumArray, size);
	
	return 0;
}

int *getData(int &size)
{
    int* array = new int(size);
    
    int i = 0;
    
    while (cin >> array[i])
    {
        i++;
        size = i;
    }
    
    return array;
}

int* sumAry(const int* array, int size)
{
    int* sumArray = new int(size);
    
    int sum = 0;
    
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            sum+=array[j];
        }
        sumArray[i] = sum;
        sum = 0;
    }
    
    return sumArray;
}

void prntAry (const int* array, int size)
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












