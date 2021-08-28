#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;

using namespace std;

void solve()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        ll ans = abs(d-b) + abs(c-a);
        for (;;)
        {
            if (ans==k)
            {
                cout<<"YES\n";
                break;
            }
            if (ans>k)
            {
                cout<<"NO\n";
                break;
            }
            ans+=2;
        }
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