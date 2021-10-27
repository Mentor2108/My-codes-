#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;

using namespace std;
//Multiples of 3 and 5 upto n (1000)
void solve()
{
    int n = 1000000000;
    // cin>>n;

    ll ans = 0;
    for (int i = 3; i<n; i+=3)
    {
        ans = ans + i;
    }
    for (int i = 5; i<n; i+=5)
    {
        ans = ans + i;
    }
    for (int i = 15; i<n; i+=15)
    {
        ans = ans - i;
    }
    // ll ans = (3 * (333)*(334))/2 + (5 *(199)*(200))/2 - (15 * 66*67)/2;
    cout<<ans;
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