#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
const int N = 200001;

using namespace std;

void solve()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m,k;
        ll count = 0;
        cin>>n>>m>>k;
        ll a[k], num[N] = {};
        for (int i = 0; i<k;i++)
        {
            cin>>a[i];
            num[a[i]]++;
        }   
        for (int i = 1;i<=n;i++)
        {
            if (num[i] > 1)
                count++;
        }
        cout<<count<<" ";
        for (int i = 1;i<=n;i++)
        {
            if (num[i] > 1)
                cout<<i<<" ";
        }
        cout<<"\n";

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