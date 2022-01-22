#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;

using namespace std;

void solve()
{
    int n;
    cin>>n;
    int a[n];
    cin>>a[0];
    for (int i = 1; i < n; i++)
    {
        cin>>a[i];
        if (a[i] <= a[i-1])
        {
            cout<<a[i-1];
            return;
        }
    }    
    cout<<a[n-1];
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