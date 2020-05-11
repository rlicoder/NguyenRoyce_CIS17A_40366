#include <bits/stdc++.h>

using namespace std;

class FeetInches
{
private:
    int inches;
    int feet;
public:
    void simplify();
    FeetInches(int numinches);
    FeetInches();
    bool operator >=(const FeetInches &right);
    bool operator <=(const FeetInches &right);
    bool operator !=(const FeetInches &right);
    
};

main()
{
    int a, b;
    
    cout << "Enter the inches for one object: ";
    cin >> a;
    
    cout << "Enter the inches for the other object: ";
    cin >> b;
    
    FeetInches obj1(a);
    FeetInches obj2(b);
    
    cout << "I will now determine if the object 1 is greater than or equal to object 2: ";
    if (obj1 >= obj2)
    {
        cout << "TRUE";
    }
    else 
    {
        cout << "FALSE";
    }
    cout << endl << endl;
    
    cout << "I will now determine if the object 1 is less than or equal to object 2: ";
    if (obj1 <= obj2)
    {
        cout << "TRUE";
    }
    else 
    {
        cout << "FALSE";
    }
    cout << endl << endl;
    
    cout << "I will now determine if the object 1 is not equal to object 2: ";
    if (obj1 != obj2)
    {
        cout << "TRUE";
    }
    else 
    {
        cout << "FALSE";
    }
    cout << endl << endl;
    
    
    
    
    
    
}

void FeetInches::simplify()
{
    if (inches >= 12)
    {
        feet += (inches/12);
        inches = inches % 12;
    }
    else if (inches < 0)
    {
        feet -= ((abs(inches) / 12) + 1);
        inches = 12 - (abs(inches) % 12);
    }
}

FeetInches::FeetInches(int numinches)
{
    inches = numinches;
    simplify();
}

FeetInches::FeetInches()
{
    inches = 0;
    feet = 0;
}


bool FeetInches::operator>=(const FeetInches &right)
{
    bool flag = false;
    if(feet == right.feet)
    {
        if (inches == right.inches)
        {
            flag = true;
        }
        else if (inches > right.inches)
        {
            flag = true;
        }
    }
    else if(feet > right.feet)
    {
        flag = true;
    }
    
    return flag;
}


bool FeetInches::operator<=(const FeetInches &right)
{
    bool flag = false;
    if(feet == right.feet)
    {
        if (inches == right.inches)
        {
            flag = true;
        }
        else if (inches < right.inches)
        {
            flag = true;
        }
    }
    else if(feet < right.feet)
    {
        flag = true;
    }
    
    return flag;
        
}




bool FeetInches::operator!=(const FeetInches &right)
{
    bool flag = false;
    if (feet != right.feet)
    {
        flag = true;
    }
    else if (inches != right.inches)
    {
        flag = true;
    }
    
    return flag;
}