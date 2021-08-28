#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
using namespace std;

const int N = 100005
//still need to try havent done yet
vector <ll> tree[N];

// void dfs(ll node, ll parent)
// {
//     for (int i : tree[node])
//     {
//         if (i != parent)
//             dfs(i, node);
//     }

// }

void solve()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll count,a[n+1];
        ll num_way = 0, num[n+1] = {};
        if (n == 1)
        {
            cout<<"0"<<endl;
            continue;
        }
        for (int i = 1; i <=n;i++)
        {
            tree[i].clear();
        }
        
        for (ll i = 1; i<n; i++)
        {
            ll a,b;
            cin>>a>>b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        for (ll i = 1; i <= n;i ++)
        {
            if (tree[a].size() == 1)
                count++;
            cin>>a[i];
            num[a[i]]++;
        }
     //   dfs(1,-1);
        for (ll i = 1; i <=n;i++)
        {
            if (num[i] != 0)
            {
                num_way = ((num_way)%mod + (num[i] -1)%mod)%mod;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL;
    solve();
    return 0;
}