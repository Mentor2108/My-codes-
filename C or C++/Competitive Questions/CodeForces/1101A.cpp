#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
// const int N = ;

using namespace std;

void solve()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,r,d;
        cin>>l>>r>>d;
        ll ans = d;
        if (d>=l)
            cout<< (((r+d)/d)*d)<<"\n";
        else
            cout<<d<<"\n";
        
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