#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL mod = 1e9 + 7;

vector<vector<LL>> v;

LL dfs(LL node, LL par)
{ 
    vector<LL> g;
    for (LL to : v[node])
    {
        if (to != par)
        {
            printf("for %lld, where node is %lld and parent is %lld\n", to, node, par);
            LL p = dfs(to, node);
            g.push_back(p);
        }
    }   
    sort(g.begin(), g.end());

    LL curK = 0;

    for (LL i = g.size() - 1; i >= 0; i--)
    {
        curK = (curK + ((long long)g[i] * ((long long)g.size() - i)));
    }

    return (1 + curK);
}
LL solve()
{
    LL n, x;
    cin >> n >> x;
    v.clear();
    v.resize(n + 1);

    for (LL i = 0; i < n - 1; i++)
    {
        LL a, b;
        cin >> a >> b;
        v[a].push_back(b);         
        // 1 2...1 3...2 4...3 5
        // v[1] = 2, 3
        // v[2] = 1, 4
        // v[3] = 1, 5
        // v[4] = 2
        // v[5] = 3
        v[b].push_back(a);
    }

    printf("full vector v = \n");
    for (LL i = 0; i<=n;i++)
    {
        for (LL j = 0; j<v[i].size();j++)
            printf("%lld ",v[i][j]);
        printf("\n");
    }

    LL alpha = dfs(1, -1);
    alpha %= mod;

    return (alpha * (long long)x) % mod;
}

int main()
{
    LL T;
    cin >> T;

    for (LL i = 0; i < T; i++)
    {
        cout << solve() << endl;
    }
}