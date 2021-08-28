#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define MAX 1000000007
using namespace std;

void solve()
{
    int t;
    cin>>t;
    unsigned int dp[100002] = {0}, i = 2;
    dp[1] = 2;
    dp[2] = 4;
    while(t--)
    {
        unsigned int n;
        cin>>n;

        if (n==1)
        {
            cout<<"1\n";
            continue;
        }
        if (dp[n-1] != 0)
        {   
            cout<<dp[n-1]<<"\n";
            continue;
        }
        for (; i < n;i++)
            dp[i+1] = ((dp[i]%MAX)*2)%MAX;
        cout<<dp[i-1]<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();

    return 0;
}