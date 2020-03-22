#include <iostream>

int **getData(int &,int &);//Get the Matrix Data
void printDat(const int * const *,int,int);//Print the Matrix
int **augment(const int * const *,int,int);//Augment the original array
void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory

using namespace std;

int main()
{
    int row, col;
	cin >> row >> col;
	
	int** array = getData(row, col);
	
	printDat(array, row, col);
	
	int** augAry = augment(array, row, col);
	
	cout << endl;
	
	printDat(augAry, row+1, col+1);
	
	destroy(array, row+1);
	
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

void printDat(const int* const * array,int row,int col)
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
        if (i != row-1)
        {
            cout << endl;
        }
    }
}

int **augment(const int * const * array,int row,int col)
{
    int** augAry = new int*[row+1];
    for(int i = 0; i < row+1; i++)
    {
        augAry[i] = new int[col+1];
    }
    
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < col+1; j++)
        {
            augAry[i][j] = 0;
        }
    }
    
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < row+1; j++)
        {
            augAry[j][i] = 0;
        }
    }
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            augAry[i+1][j+1] = array[i][j];
        }
    }
    
    return augAry;
}

void destroy(int ** array,int row)
{
    for(int i = 0; i < row; i++)
	{
		delete [] array[i];
	}
	delete [] array;
}