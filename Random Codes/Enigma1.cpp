#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll Fastpow(ll base, ll pow) {
    if (pow == 0)
        return 1;
    ll res = Fastpow(base, pow / 2);
    if (pow % 2)
        return res * res * base;
    else
    return res * res;
}

int main()
{
/*     int t;
    cin>>t;
    for(int i = 0; i < t; i++)
    { */
        ll n;
    cin>>n;
    cout<<Fastpow(2, n)-1;
    // }
}