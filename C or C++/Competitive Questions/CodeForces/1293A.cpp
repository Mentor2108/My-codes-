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
        int n,s,k;
        cin>>n>>s>>k;
        vector<int> a;
        int y = -1, ans = 1;
        for (int i = 0; i < k; i++)
        {
            int x;
            cin>>x;
            if (x == s)
                y = i;
            a.push_back(x);
        }
        if (y == -1)
            cout<<"0\n";
        else
        {
            sort(a.begin(), a.end());
            for (int i = 1; i <= k;i++)
            {
                if (s + i <= n && count(a.begin(), a.end(), s+i) == 0) 
                {
                    ans = i;
                    break;
                }
                
                if (s-i > 0 && count(a.begin(), a.end(), s-i) == 0)
                {
                    ans = i;
                    break;
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