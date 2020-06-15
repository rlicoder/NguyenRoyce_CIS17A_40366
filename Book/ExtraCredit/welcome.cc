#include <bits/stdc++.h>

using namespace std;

class List
{
private:
    vector<string> names;
    string alpha;
    bool leftflag;
    bool rightflag;
    bool sameflag;
public:
    List(){leftflag = false; rightflag = false; sameflag = false;};
    int strcmpsort(string left, string right);
    void setNamesAndOrder();
    void sort();
    void outputNames();
    void internalSort(string left, string right, int size);
    
    
};

main()
{
    List Ballot;
    
    Ballot.setNamesAndOrder();
    Ballot.sort();
    Ballot.outputNames();
    
    
}

void List::setNamesAndOrder()
{
    ifstream infile;
    
    infile.open("Ballot.txt", ios::in);
    
    getline(infile, alpha);
    
    while (!infile.eof())
    {
        string dummy;
        getline(infile, dummy);
        names.push_back(dummy);
    }
    
    infile.close();
}

void List::sort()
{
    bool swap;
    string temp;
    
    do
    {
        swap = false;
        for (int count = 0; count < (names.size() - 1); count++)
        {
            if (strcmpsort(names[count], names[count+1]) == -1)
            {
                temp = names[count];
                names[count] = names[count + 1];
                names[count + 1] = temp;
                swap = true;
            }
        }
        //outputNames();
    } while (swap);

}

void List::outputNames()
{
    for (int i = 0; i < names.size(); i++)
    {
        cout << names[i] << endl;
    }
    cout << endl << endl;
}

int List::strcmpsort(string left, string right)
{
    int size;
    
    if (left.length() > right.length())
    {
        size = left.length();
    }
    else 
    {
        size = right.length();
    }
    
    leftflag = false;
    rightflag = false;
    internalSort(left, right, size);
    
    if (sameflag)
    {
        
    }
    else if (leftflag)
    {
        return -1;
    }
    else if (rightflag)
    {
        return 1;
    }
    else if (leftflag && rightflag)
    {
        internalSort(left, right, size);
    }
    
}

void List::internalSort(string left, string right, int size)
{
    for (int i = 0; i < size && !(leftflag || rightflag); i++)
    {
        for (int j = 0; j < 26 && !(leftflag || rightflag); j++)
        {
            if (left[i] == '\0')
            {
                leftflag = true;
                continue;
            }
            if (left[i] == '\0')
            {
                rightflag = true;
                continue;
            }
            if (left[i] == alpha[j])
            {
                leftflag = true;
            }
            if (right[i] == alpha[j])
            {
                rightflag = true;
            }
                
        }
    }
}