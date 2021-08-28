#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
// const int N = ;

using namespace std;

void solve()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        vector<ll> a;
        for (int i = 0; i < n; i++)
        {
            ll x;
            cin>>x;
            a.push_back(x);
        }
        ll ans = 0;
        for (int i = n-1; i >0; i--)
        {
            if (a[i-1] > a[i])
            {
                ans = ans + a[i-1] - a[i];
            } 
        }
        cout<<ans<<"\n";
    }    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}