#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007

using namespace std;

const int N = 100005;
vector<ll> tree[N];
ll calc[N];

ll ans = 0;

void dfs(ll node, ll parent)
{
    calc[node] = 1;
    ans++; //for the +1 in the formula
    for (ll i : tree[node])
    {
        if (i == parent)
            continue;
        dfs(i, node);
        ans += ((calc[node]) * (calc[i])) % mod;
        calc[node] += 2 * calc[i];
        calc[node] %= mod;
        ans %= mod;
    }
}

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        for (ll i = 1; i <= n; i++)
        {
            calc[i] = 0;
            tree[i].clear();
        }
        for (ll i = 1; i < n; i++)
        {
            ll a, b;
            cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        ans = 0;
        dfs(1, -1);
        cout << ans << "\n";
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