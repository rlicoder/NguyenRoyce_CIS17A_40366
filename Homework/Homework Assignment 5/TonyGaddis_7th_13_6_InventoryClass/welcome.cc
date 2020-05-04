#include <bits/stdc++.h>

using namespace std;

class Inventory
{
private:
    int itemNumber;
    int quantity;
    float cost;
    float totalCost;
public:
    Inventory();
    Inventory(int itemnum, int units, float price);
    void setItemNumber(int itemnum);
    void setQuantity(int units);
    void setCost(float price);
    void setTotalCost();
    void getItemNumber() const;
    void getQuantity() const;
    void getCost() const;
    void getTotalCost() const;
};

main()
{
    int itemnum;
    int units;
    float price;
    
    Inventory item;
    
    cout << "Now allowing the user to specify an item" << endl;
    
    cout << "Enter the item number: ";
    cin >> itemnum;
    while (itemnum < 0)
    {
        cout << "Invalid number, try again: ";
        cin >> itemnum;
    }
    
    cout << "Enter the quantity of the item: ";
    cin >> units;
    while (units < 0)
    {
        cout << "Invalid number, try again: ";
        cin >> units;
    }
    
    cout << "Enter the cost of the item: ";
    cin >> price;
    while (price < 0)
    {
        cout << "Invalid number, try again: ";
        cin >> price;
    }
    item.setCost(price);
    item.setItemNumber(itemnum);
    item.setQuantity(units);
    item.setTotalCost();
    
    cout << "Now outputting the values for the user item " << endl;
    cout << "Item Number: ";
    item.getItemNumber();
    cout << "Cost: ";
    item.getCost();
    cout << "Quantity: ";
    item.getQuantity();
    cout << "Total cost: ";
    item.getTotalCost();
    
    cout << endl << "Using the default constructor for item 1" << endl;
    Inventory item1;
    cout << "Now outputting the values for item1 " << endl;
    cout << "Item Number: ";
    item1.getItemNumber();
    cout << "Cost: ";
    item1.getCost();
    cout << "Quantity: ";
    item1.getQuantity();
    cout << "Total cost: ";
    item1.getTotalCost();
    
    cout << endl << "Using the overloaded constructor for item 2 with itemnumber: 123, cost: 19.99, and quantity: 5" << endl;
    Inventory item2(123, 5, 19.99);
    cout << "Now outputting the values for item2" << endl;
    cout << "Item Number: ";
    item2.getItemNumber();
    cout << "Cost: ";
    item2.getCost();
    cout << "Quantity: ";
    item2.getQuantity();
    cout << "Total cost: ";
    item2.getTotalCost();
}

Inventory::Inventory()
{
    itemNumber = 0;
    quantity = 0;
    cost = 0;
    totalCost = 0;
}

Inventory::Inventory(int itemnum, int units, float price)
{
    itemNumber = itemnum;
    quantity = units;
    cost = price;
    setTotalCost();
}

void Inventory::setTotalCost()
{
    totalCost = quantity * cost;
}
void Inventory::setItemNumber(int itemnum)
{
    itemNumber = itemnum;
}
void Inventory::setQuantity(int units)
{
    quantity = units;
}
void Inventory::setCost(float price)
{
    cost = price;
}
void Inventory::getItemNumber() const
{
    cout << itemNumber << endl;
}

void Inventory::getQuantity() const
{
    cout << quantity << endl;
}

void Inventory::getCost() const
{
    cout << cost << endl;
}

void Inventory::getTotalCost() const
{
    cout << totalCost << endl;
}
