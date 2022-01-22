#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;

using namespace std;

void solve()
{
    char a[3];
    cin>>a;
    int ans = 0, x = a[0]+a[1]+a[2] - 48*3;

    for (int i =0;i <3;i++)
    {
        ans += x*pow(10,2-i);
    }
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