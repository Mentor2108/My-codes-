#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
// const int N = ;
//dont know anything about it
using namespace std;

void solve()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans = 0;
        int a[n], sum[n+1] = {};
        for (int i = 0; i < n; i++)
        {   
            cin>>a[i];
            sum[a[i]] ++;
        }
        if (sum[a[0]] == n)
            cout<<"0\n";
        else
        {
            int m = n, x = -1;
            for (int i = 1; i <= n; i++)
            {
                if (sum[i] != 0)
                    if (m > sum[i])
                    {
                        m = sum[i];
                        x = i;
                    }    
            }
            if (a[0] == a[n-1])
            {
                if (sum[a[0]] - 1 < m+1)
                    ans = n - sum[a[0]]; 
            }
            
            else
            {
                // cout<<"\nm = "<<x<<endl;
                if (a[0] == x)
                {
                    if (a[n-1] == x)
                        ans = m - 1;
                    else
                        ans = m;
                }
                else
                {
                    if (a[n-1] == x)
                        ans = m;
                    else
                        ans = m + 1;
                }
            }
            cout<<ans<<"\n";
        } 
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