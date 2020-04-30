#include <bits/stdc++.h>

using namespace std;

struct Prime
{
	unsigned short prime;
	unsigned char power;
};
struct Primes
{
	unsigned char nPrimes;
	Prime *prime;
};

Primes *factor(int num);
void prntPrm(Primes *number);

main()
{
    int num;
    
    cout << "Enter the number that you'd like the prime factors of: ";
    cin >> num;
    
    Primes* number = factor(num);
    prntPrm(number);
}

Primes *factor(int num)
{
    Primes* stubbydubbywubby = new Primes;
    int count;
    int othercount = 0;
    
    stubbydubbywubby->prime = new Prime[13];
    
    for (int i = 2; i <= num; i++)
    {
        count = 0;
        if (num % i == 0)
        {
            count++;
            num /= i;
            while (num%i==0)
            {
                num /= i;
                count++;
            }
        }
        if (count != 0)
        {
            
            stubbydubbywubby->prime[othercount].prime = i;
            stubbydubbywubby->prime[othercount].power = count + '0';
            cout <<  "total count for " << i << " was " << count << endl;
            othercount++;
        }
    }
    
    stubbydubbywubby->nPrimes = othercount + '0';
    
    
    return stubbydubbywubby;
}

void prntPrm(Primes *number)
{
    int realnumber = 1;
    
    int j = static_cast<int>(number->nPrimes - '0');

    for (int i = 0; i < j; i++)
    {
        int k = static_cast<int>(number->prime[i].power - '0');
        realnumber *= pow(number->prime[i].prime,k);
    }
    
    
    cout << "The prime factors of " << realnumber << " is: ";
    for (int i = 0; i < j; i++)
    {
        cout << number->prime[i].prime << "^" << number->prime[i].power;
        if (i != j-1)
        {
            cout << " * ";
        }
    }
    cout << endl;
}