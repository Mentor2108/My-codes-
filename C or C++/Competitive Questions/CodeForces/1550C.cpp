#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
// const int N = ;
//don't know about this at all...if it works or not
using namespace std;

void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        ll a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll ans = 2 * n - 1;
        if (n < 3)
        {
            cout << ans << "\n";
        }
        else
        {
            for (int i = 0; i < n-2; i++)
            {
                for (int j = i+2; j<n;j++)
                {
                    if (a[i+1] == a[j])
                    {
                        break;
                    }
                    else if (a[i] == a[j])
                    {
                        cout<<"i = "<<i<<", j = "<<j<<"\n";
                        ans++;
                    }
                    else if ((a[i] + a[j])/2 != a[i+1])  
                    {
                        cout<<"ii = "<<i<<", j = "<<j<<"\n";
                        ans++;
                    }
                    else
                        break;
                    // int calc = abs(a[i] - a[j]);
                    // int calc2 = abs(a[i] - a[i+1]) + abs(a[j] - a[i+1]);
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