#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
using namespace std;

void solve()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,x,k;
        cin>>n>>x>>k;
        if (x%k == 0 || (n+1-x)%k == 0)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();

    return 0;
}