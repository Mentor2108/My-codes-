#include <bits/stdc++.h>

#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007

#define YOURMENTOR ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define FOR(i, n, k) for(long long i = 0; i<n; i+=k)
#define endl "\n"
#define PB push_back
#define F first
#define S second
#define VI vector<int>
#define PII pair<int, int>
#define VPII vector<pair<int, int>>

const int N = 100004;

using namespace std;

void Mentor()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif
}

ll Fastpow(ll base, ll pow) {
    if (pow == 0)
        return 1;
    ll res = Fastpow(base, pow / 2);
    if (pow % 2)
        return res * res * base;
    else
    return res * res;
}

void FindPrime(bool* prime, int N) {
    for (int i = 1; i <= N; i++) {
        prime[i] = 1;
    }
    prime[0] = 0;
    prime[1] = 0;
    int i=2;
    while(i*i <= N) {
        if(prime[i] == 0) {
            i++;
            continue;
        }
        int j = 2*i;
        while(j < N) {
            prime[j] = 0;
            j += i;
        }
        i++;
    }
}

vector<int> tree[N];
vector<bool> ans[N];

void dfs(ll node, ll par, vector<bool> &visited)
{ 
    visited[node] = 1;
    for (ll i : tree[node])
    {
        if (i != par && visited[i] == 0)
        {
            dfs(i, node, visited);
        }
    }   
}

void solve()
{
    ll n, d, q;
    cin>>n>>d>>q;
    vector<ll> a(n);
    FOR(i, n, 1)
    {
        cin>>a[i];
    }
    // vector<pair<int,int>> queries(q);
    // for(int i = 0;i<q;i++)
    // {
        
    //     queries.push_back({x,y});
    // }

    for(ll i = 1; i <= n; i++)
    {   
        for (ll j = 1; j<=n; j++)
        {
            if (i==j)
                continue;
            if (abs(a[i-1]-a[j-1]) <= d)
            {
                tree[i].PB(j);
                // tree[j].PB(i);
            }
        }
    }
    
    for (ll i = 1; i<=n; i++)
    {
        vector<bool> visited(n+1, 0);
        dfs(i, -1, visited);
        ans[i] = visited;
    }

    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 0; j<tree[i].size(); j++)
    //     {
    //         cout<<tree[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(ll i = 1; i <= n; i++)
    // {
    //     for(ll j = 1; j<ans[i].size(); j++)
    //     {
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(ll i = 0;i<q;i++)
    {
        ll x, y;
        cin>>x>>y;
        if(ans[x][y])
        {
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO\n";
    }
}

void TestCase()
{
    int T;
    cin>>T;
    while(T--)
        solve();
}

int main()
{
    Mentor();
    YOURMENTOR
    //bool prime[N];
    //FindPrime(prime, N);
    // TestCase();
    solve();
    return 0;
}

