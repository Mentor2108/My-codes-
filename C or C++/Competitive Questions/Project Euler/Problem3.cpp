#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;

using namespace std;

void solve()
{
    ll n = 600851475143;
    ll x = sqrt(n);
    ll i = 3, num = n;
    ll ans = 0;
    while (i <= x)
    {
        if (num%i == 0)
        {
            ans = i;
            num/=i; 
        }
        else
            i+=2;
    }

    cout<<max(num, ans);
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int T;
    // cin>>T;
    // while(T--)
        solve();
    return 0;
}