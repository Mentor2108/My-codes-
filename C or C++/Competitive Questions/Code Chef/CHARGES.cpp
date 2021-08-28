#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;

using namespace std;

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        char a[n];
        cin >> a;
        ll ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] == a[i + 1])
                ans += 2;
            else
                ans++;
        }
        for (int i = 0; i < k; i++)
        {
            int upd;
            cin >> upd;

            if (a[upd - 1] == '0')
                a[upd - 1] = '1';
            else
                a[upd - 1] = '0';

            upd--;
            if (upd > 0)
            {
                if (a[upd - 1] != a[upd])
                    ans--;
                else if (a[upd - 1] == a[upd])
                    ans++;
            }

            if (upd < n - 1)
            {
                if (a[upd] != a[upd + 1] && upd < n)
                    ans--;
                else if (a[upd] == a[upd + 1] && upd < n)
                    ans++;
            }
            cout << ans << "\n";
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