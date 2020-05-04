#include <bits/stdc++.h>

using namespace std;

class RetailItem
{
private:
    string description;
    int unitsOnHand;
    float price;
public:
    RetailItem(string desc, int units, float cost);
    void inputData(string desc, int units, float cost);
    void outputData() const;
};

main()
{
    string desc;
    int units;
    float cost;
    RetailItem item[3] = {RetailItem(" ", 0, 0.00),
                          RetailItem(" ", 0, 0.00),
                          RetailItem(" ", 0, 0.00)};
    
    for (int i = 0; i < 3; i++)
    {        
        cout << "Enter the description for an item: ";
        getline(cin, desc);
        cout << "How many units are on hand: ";
        cin >> units;
        cout << "What is the cost of the item: ";
        cin >> cost;
        cin.ignore(1);
        item[i].inputData(desc, units, cost);
    }
    
    cout << left << setw(20) << " " << setw(30) << "Description" << setw(30) << "Units on Hand" << setw(25) <<  "Price" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout  << "Item #" << setw(14) << i+1;
        item[i].outputData();
    }
        
    
}

RetailItem::RetailItem(string desc, int units, float cost)
{
    description = desc;
    unitsOnHand = units;
    price = cost;
}

void RetailItem::inputData(string desc, int units, float cost)
{
    description = desc;
    unitsOnHand = units;
    price = cost;
}

void RetailItem::outputData() const
{
    cout << setw(30) << description << setw(30) << unitsOnHand <<setw(25) << price << endl; 
}