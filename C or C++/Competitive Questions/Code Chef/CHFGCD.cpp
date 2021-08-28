#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;

using namespace std;

void solve()
{
    ll a, b;
    cin>>a>>b;
    if (__gcd(a,b) > 1)
        cout<<"0\n";
    else if (__gcd(a+1, b) > 1 || __gcd(a, b+1) > 1)
        cout<<"1\n";
    else
        cout<<"2\n";
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