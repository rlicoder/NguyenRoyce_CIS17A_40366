#include <bits/stdc++.h>

using namespace std;

class persondata
{
private:
    string name;
    string address;
    int age;
    string phonenumber;
public:
    void inputdata(string uname, string uaddress, int uage, string uphonenumber);
    void outputdata() const;
};

main()
{
    persondata me;
    persondata fryend;
    persondata family;
    
    string name;
    string address;
    int age;
    string phonenumber;
    
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter address: ";
    getline(cin, address);
    cout << "Enter age: ";
    cin >> age;
    cin.ignore(1);
    cout << "Enter phone number: ";
    getline(cin, phonenumber);
    
    me.inputdata(name, address, age, phonenumber);
    cout << endl;
    
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter address: ";
    getline(cin, address);
    cout << "Enter age: ";
    cin >> age;
    cin.ignore(1);
    cout << "Enter phone number: ";
    getline(cin, phonenumber);
    
    fryend.inputdata(name, address, age, phonenumber);
    cout << endl;
    
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter address: ";
    getline(cin, address);
    cout << "Enter age: ";
    cin >> age;
    cin.ignore(1);
    cout << "Enter phone number: ";
    getline(cin, phonenumber);
    
    family.inputdata(name, address, age, phonenumber);
    cout << endl << endl;
    
    me.outputdata();
    fryend.outputdata();
    family.outputdata();
    
}

void persondata::inputdata(string uname, string uaddress, int uage, string uphonenumber)
{
    name = uname;
    address = uaddress;
    age = uage;
    phonenumber = uphonenumber;
}

void persondata::outputdata() const
{
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Age: " << age << endl;
    cout << "Phone Number: " << phonenumber << endl << endl;
}