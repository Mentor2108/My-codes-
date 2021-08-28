#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
const int N = 100001;

using namespace std;

void solve()
{
    int n;
    cin>>n;
    // vector<char> a[N];
    char x[N], y[N];
    cin>>x;
    int l1 = strlen(x);
    int maxx = l1;
    char ans[N];
    strcpy(ans, x);
    for (int i = 1;i<n;i++)
    {
        cin>>y;
        int l2 = strlen(y), m, maxi;
        char bigstring[N];
        // int m = min(l1,l2);
        
        // int maxi = max(l1,l2);
        if (l1 > l2)
        {
            strcpy(bigstring,y);
            maxi = l1;
            m = l2;
        }
        else
        {
            strcpy(bigstring, x);
            maxi = l2;
            m = l1;
        }

        for (int j = 0; j<m; j++)
        {
            if (ans[j] == '.')
                continue;
            // if (ans[j] == '\0')
            // {
            //     if (x[j] == y[j])
            //         ans[j] = x[j];
            //     else
            //         ans[j] = '.';
            // }
            else if (ans[j] == '?')
            {
                if (y[j] != '?')
                {
                    ans[j] = y[j];
                }
            }
            else
            {
                if (ans[j] != y[j])
                {
                    if (y[j] != '?')
                        ans[j] = '.';
                }
                // else if (x[j] == '?')
                // {
                //     ans[j] = y[j];
                // }
                // else if(y[j] == '?')
                //     ans[j] = x[j];
                // else
                // {
                //     ans[j] = '.';
                // }
            }
        }
        if (l1<l2)
        {
            for (int j = m; j<maxi; j++)
                ans[j] = y[j];
        }
        maxx = max(maxx, l2);
        l1 = strlen(ans);
    }    

    for (int i = 0; i < maxx; i++)
    {
        if (ans[i] == '?')
        {
            cout<<'z';
        }
        else if (ans[i] == '.')
        {
            cout<<'?';
        }
        else
        {
            cout<<ans[i];
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