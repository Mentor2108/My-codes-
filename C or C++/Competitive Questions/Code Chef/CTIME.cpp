#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
const int N = 1e9;
//TLE
using namespace std;

void solve()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int n, k, f;
        cin >> n >> k >> f;
        int a[f] = {};
        int flag = 0;
        int count = 0;
        while(n--)
        {
            int x, y;
            cin >> x >> y;
            for (int j = x; j < y; j++)
                a[j] = 1;
        }
        for (int i = 0; i < f; i++)
        {
            if (a[i] == 0)
                count++;
            if (count >= k)
            {
                cout << "YES\n";
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "NO\n";
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