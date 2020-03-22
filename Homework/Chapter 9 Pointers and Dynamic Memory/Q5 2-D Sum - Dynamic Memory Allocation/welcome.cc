#include <iostream>

using namespace std;

int **getData(int &,int &);        //Return the 2-D array and its size.
void prntDat(const int* const *,int,int);//Print the 2-D Array
void destroy(int **,int,int);       //Deallocate memory
int sum(const int * const *, int,int);    //Return the Sum

int main()
{
	int row, col, total = 0;
	cin >> row >> col;
	
	int** array = getData(row, col);
	
	prntDat(array, row, col);
	
	total = sum(array, row, col);
	
	cout << total;
	
	destroy(array, row, col);
	
	return 0;
}

int **getData(int &row, int &col)
{
    int temp;
    int i = 0;
    int j = 0;
    int count = 0;
    
    int** array = new int*[row];
    for(int i = 0; i < row; i++)
    {
        array[i] = new int[col];
    }
    
    for (int k = 0; k < row*col; k++)
    {
        cin >> temp;
        count++;
        array[i][j] = temp;
        j++;
        if (count == col)
        {
            i++;
            j = 0;
            count = 0;
        }
    }
    
    return array;
}

void prntDat(const int* const * array,int row,int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << array[i][j];
            if (j < col-1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void destroy(int ** array,int row, int col)
{
    for(int i = 0; i < row; i++)
	{
		delete [] array[i];
	}
	delete [] array;
}

int sum(const int * const *array, int row,int col)
{
    
    int total=0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            total += array[i][j];
        }
    }
    
    return total;
}