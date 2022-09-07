#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll test(ll n, ll digit) {
    if (digit == 1)
    {
        return n;
    }
    return n%10 - test(n/10, digit-1);
}

int main()
{
    ll n;
    cin>>n;
    int num_digit = 0;
    int abc = abs(n);
    cout<<"\n output: ";
    if (n==0)   
        cout<<"0";
    for (int i = abc; i > 0; i/=10)
    {
        num_digit++;
    }
    ll x = test(abc, num_digit);
    if (n < 0)
        cout<<-1*x;
    else 
        cout<<x;
}