#include <bits/stdc++.h>

using namespace std;

class Employee
{
private:
    string name;
    int id;
    int date[3];
    
public:
    Employee()
    {
        name = "null";
        id = 0;
        date[0] = 0;
        date[1] = 0;
        date[2] = 0;
    }
    Employee(string sname, int sid, int s1, int s2, int s3)
    {
        name = sname;
        id = sid;
        date[0] = s1;
        date[1] = s2;
        date[2] = s3;
    }
    void setname(string sname)
    {
        name = sname;
    }
    void setid(int sid)
    {
        id = sid;
    }
    void setdate (int s1, int s2, int s3)
    {
        date[0] = s1;
        date[1] = s2;
        date[2] = s3;
    }
    string getname()
    {
        return name;
    }
    int getid()
    {
        return id;
    }
    void getdate()
    {
        cout << date[0] << "/" << date[1] << "/" << date[2];
    }
};

class ProductionWorker : public Employee
{
private:
    int shift;
    double hourlypayrate;
    
public:
    ProductionWorker()
    {
        shift = 0;
        hourlypayrate = 0.0;
    }
    ProductionWorker(string sname, int sid, int s1, int s2, int s3, int sshift, double shpr) : Employee(sname, sid, s1, s2, s3)
    {
        shift = sshift;
        hourlypayrate = shpr;
    }
    void setshift (int sshift)
    {
        shift = sshift;
    }
    void sethourlypayrate(double shpr)
    {
        hourlypayrate = shpr;
    }
    string getshift()
    {
        if (shift == 1)
        {
            return "Day shift";
        }
        else if (shift == 2)
        {
            return "Night Shift";
        }
        else if (shift == 0)
        {
            return "Shift type not set";
        }
    }
    double gethourlypayrate()
    {
        return hourlypayrate;
    }
};

void displayWorker(ProductionWorker worker);

int main()
{
    string sname;
    int sid, s1, s2, s3, sshift;
    double shpr;
    
    cout << "Enter the name of a worker: ";
    getline(cin,sname);
    
    cout << "Enter the id of the worker: ";
    cin >> sid;
    
    cout << "Enter the month the worker joined: ";
    cin >> s1;
    
    cout << "Enter the day the worker joined: ";
    cin >> s2;
    
    cout << "Enter the year the worker joined: ";
    cin >> s3;
    
    cout << "Does this worker work a day shift(enter 1), or a night shift(enter 2)? ";
    cin >> sshift;
    
    cout << "What is the hourly pay rate of this worker? ";
    cin >> shpr;
    
    cout << "Now creating your worker with a custom constructor" << endl;
    ProductionWorker worker(sname, sid, s1, s2, s3, sshift, shpr);
    
    cout << "Now displaying your custom worker" << endl;
    displayWorker(worker);
    
    cout << endl;
    
    cout << "Now creating a default worker" << endl;
    ProductionWorker defworker;
    
    cout << "Now displaying the default worker" << endl;;
    displayWorker(defworker);
}

void displayWorker(ProductionWorker worker)
{
    cout << endl;
    cout << "WORKER INFO" << endl;
    cout << "Name: " << worker.getname() << endl;
    cout << "ID: " << worker.getid() << endl;
    cout << "Date joined: ";
    worker.getdate();
    cout << endl;
    cout << "Shift Type: " << worker.getshift() << endl;
    cout << "Hourly Pay Rate: " << worker.gethourlypayrate() << endl;
}