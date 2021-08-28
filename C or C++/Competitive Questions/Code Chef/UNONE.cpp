#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
// const int N = ;

using namespace std;

ll bin(int n)
{
    ll binary = 0;
    int i = 1;
    //converting decimal to binary
    while (n != 0)
    {
        int rem = n % 2;
        n /= 2;
        binary += rem * i;
        i *= 10;
    }
    return binary;
}

void solve()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        ll b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if ((a[i]&1) == 0)
                cout<<a[i]<<" ";
        }
        for (int i = 0;i<n;i++)
            if (a[i]&1)
            {   
                cout<<a[i]<<" ";
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