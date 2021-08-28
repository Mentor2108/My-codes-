#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;
//works but takes a LONG time comparatively
using namespace std;

bool isPal (int n)
{
    string a = to_string(n);
    int l = a.length();
    for (int i = 0, j = l-1; i<l/2; i++, j--)
    {
        if (a[i] != a[j])
        {
            return false;
        }

    }
    return true;
}

void solve()
{
    
    ll ans = 0;
    ll maxi = 0;
    for (int i = 999; i >= 100; i--)
    {
        for (int j = 999; j >= 100; j--)
        {
            ll val = i*j;
            // cout<<"i = "<<i<<" j = "<<j<<" val = "<<val<<"\n";
            
            if (val <= maxi)
                break;
            if (isPal(val))
            {
                maxi = val;
                break;
            }
        }
        if (i*999 <= maxi)
            break;
    } 
    cout<<maxi;
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
