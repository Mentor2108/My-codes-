#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
// const int N = ;

using namespace std;

void solve()
{
    ll t;
    cin>>t;    
    while(t--)
    {
        ll D,d,p,q;
        cin>>D>>d>>p>>q;
        ll ans = p*D;
        ll val = (D-1)/d;
        ans += val*(((q+1)*(q))/2);
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