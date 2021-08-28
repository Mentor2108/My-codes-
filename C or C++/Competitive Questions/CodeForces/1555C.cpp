#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;
//will do later
using namespace std;

void solve()
{
    ll m;
    cin>>m;
    ll a[2][m];
    ll sum0[m+1] = {};
    ll sum1[m+1] = {};

    for (int j = 0; j<m; j++)
    {
        cin>>a[0][j];
    }
    for (int j = 0; j<m; j++)
    {
        cin>>a[1][j];
    }

    for (int i = m-1; i>=0; i--)
    {
        sum0[i] = sum0[i+1] + a[0][i];
        sum1[i] = sum1[i+1] + a[1][i];
    }

    int val = 0;
    sum0 -= a[0][0];
    ll cb = 0;
    for (int i = 0; i < m-1; i++)
    {
        if (sum0 == sum1) 
        {
            if (a[0][i+1] >= a[1][i])
            {
                sum0 -= a[0][i+1];
                sum1 -=
            }
        }
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