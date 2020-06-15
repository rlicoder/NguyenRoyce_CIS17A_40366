#include <bits/stdc++.h>

using namespace std;

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


main()
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