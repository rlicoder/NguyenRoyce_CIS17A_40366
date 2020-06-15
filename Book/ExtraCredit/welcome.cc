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
    bool
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
}
