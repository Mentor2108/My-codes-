#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;

using namespace std;

void solve()
{
    ll a,b,c;
    cin>>a>>b>>c;
    ll ans = 2* abs(a-b);
    if (ans >= a && ans >= b && ans >= c)
    {
        ans = ans/2;
        ll x = ans+c;
        if (x > ans*2)
            x = abs(ans - c);     
        cout<<x<<"\n";
    }
    else
    {
        cout<<"-1\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}