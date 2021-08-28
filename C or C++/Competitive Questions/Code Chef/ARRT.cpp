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
    ll n;
    cin>>n;
    int a[n], b[n];
    for (int i = 0; i< n; i++)
    {
        cin>>a[i];
        a[i]%=n;
    }
    for (int i = 0; i<n; i++)
    {
        cin>>b[i];
        b[i]%=n;
    }
    int c[n] = {};
    for (int i = 0; i<n; i++)
    {
        c[i] 
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