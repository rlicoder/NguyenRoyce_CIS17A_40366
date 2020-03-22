#include <iostream>

using namespace std;

int *getData(int &);//Read the array

int *augment(const int *,int);//Augment and copy the original array

void prntAry(const int *,int);//Print the array

int main()
{
	int size;
	
	cin >> size;
	
	int* array = getData(size);
	
	int* augAry = augment(array, size);
	
	prntAry(array, size);
	cout << endl;
	prntAry(augAry, size+1);
	
	return 0;
}

int* getData(int& size)
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

int* augment(const int *array, int size)
{
    int* augAry = new int(size+1);
    
    augAry[0] = 0;
    
    for (int i = 0; i < size; i++)
    {
        augAry[i+1] = array[i];
    }
    
    return augAry;
}

void prntAry(const int* array, int size)
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



