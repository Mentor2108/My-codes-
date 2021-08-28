#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
using namespace std;

const int N = 100005

vector <ll> tree[N];

ll dfs(ll node, ll par)
{ 
    for (ll i : tree[node])
    {
        if (i != par)
        {
            ll p = dfs(to, node);
        }
    }   
    // return ;
}

void solve()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        int s;
        cin>>n>>s;

        for (ll i = 1; i<n; i++)
        {
            ll a,b;
            cin>>a>>b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        dfs(1,-1);

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