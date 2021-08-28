#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
// const int N = ;
//didn't work, i didn't complete

using namespace std;

void solve()
{
    int t;
    cin>>t;
    while(t--)
    {
        char s[200000];
        cin>>s;
        int ans = 0;
        int count[4] = {};
        int l = strlen(s);
        for (int i = 0; i < l; i++)
        {
            count[s[i] - 47]++;
        }

        if (count[1] != 0) count[2] == 0 || count[3] == 0)
            ans++;
        if (count[2] != 0)
            ans++;
        if (count[3] != 0)
            ans++;
        if (ans != 3)
            cout<<ans<<"\n";
        else
        {
            for (int i = 0; i < l; i++)
            {
                
            }
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