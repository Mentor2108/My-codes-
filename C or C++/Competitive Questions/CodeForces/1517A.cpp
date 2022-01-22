#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;

using namespace std;

void solve()
{
    ll x;
    cin>>x;
    for (ll i = 16; i>=0; i--)
    {
        if ()
    }
    ll ans = x/2050;
    for (int i = ans; i>=10; i/=10)
        ans = i/10;
    if (ans == 0)
        cout<<"-1\n";
    else
        cout<<ans<<endl;
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

