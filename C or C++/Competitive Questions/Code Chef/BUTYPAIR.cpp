#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
const int N = 1000005;

using namespace std;

void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    int count[N] = {};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        count[a[i]]++;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans + n - count[a[i]];
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}