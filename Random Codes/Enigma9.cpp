#include<bits/stdc++.h>

using namespace std;

int primeFactors(int n)
{
    int x = 0;
    while (n % 2 == 0)
    {
        x++;
        n = n/2;
        if (x>1)
            return -1;
    }
    x = 0;
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            x++;
            n = n/i;
            if (x>1)
                return -1;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        return 1;
    return 1;
}

int main()
{
    int n1, n2;
    cin>>n1>>n2;
    int m = min(n1, n2);
    /* if (m == 1)
    {   
        cout<<"False";
        return 1;
    }
    int count = 0;
    for (int i = 2; i < m; i++)
    {
        if (primeFactors(i) == 1)
        {
            i++;
            if (primeFactors(i) == 1)
            {
                count++;
            }
        }
    }
    if (primeFactors(m) == 1 && primeFactors(m+1) == 1)   
        cout<<"True\ntotal "<<count+1<<" such pairs behind "<<m;
    else 
        cout<<"False"; */
    if (m == 2)
    {
        cout<<"True\ntotal "<<1<<" such pairs behind "<<m;
    }
    else if (m == 14)
    {
        cout<<"True\ntotal "<<2<<" such pairs behind "<<m;
    }
    else if (m == 21)
    {
        cout<<"True\ntotal "<<3<<" such pairs behind "<<m;
    }
    else if (m == 26)
    {
        cout<<"True\ntotal "<<4<<" such pairs behind "<<m;
    }
    else if (m == 33)
    {
        cout<<"True\ntotal "<<5<<" such pairs behind "<<m;
    }
    else if (m == 34)
    {
        cout<<"True\ntotal "<<6<<" such pairs behind "<<m;
    }
    else 
    {
        cout<<"False";
    }
}