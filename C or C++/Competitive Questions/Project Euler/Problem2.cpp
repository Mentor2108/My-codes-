#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;

using namespace std;

void solve()
{
    ll val[100000] = {}, ans = 2;
    val[0] = 1;
    val[1] = 2;
    int i = 2;
    while(1)
    {
        val[i] = val[i-1] + val[i-2];
        if (val[i] >= 4000000)
            break;
        if (i%3==1)
        {
            ans += val[i];
        }
        i++;
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