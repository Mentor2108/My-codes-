#include <bits/stdc++.h>

#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007

#define YOURMENTOR ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define FOR(i, n, k) for(int i = 0; i<n; i+=k)
#define endl "\n"
#define PB push_back
#define F first
#define S second
#define VI vector<int>
#define PII pair<int, int>
#define VPII vector<pair<int, int>>

//const int N = ;

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

const int MOD = 1e7 + 7;
vector<int> adj[100001];
int dp[100001][2], dp2[100001][2], tax[100001];

void dfs(int node, int parent) {
    dp[node][0] = dp[node][1] = dp2[node][0] = dp2[node][1] = 0;
    for (int child : adj[node]) {
        if (child == parent) continue;
        dfs(child, node);
        dp[node][0] = (dp[node][0] + min(dp[child][0], dp[child][1])) % MOD;
        dp[node][1] = (dp[node][1] + dp[child][0]) % MOD;
        dp2[node][0] = (dp2[node][0] + dp[child][1] + min(dp2[child][0], dp2[child][1])) % MOD;
        dp2[node][1] = (dp2[node][1] + dp[child][0] + min(dp2[child][0], dp2[child][1])) % MOD;
    }
    dp[node][1] = (dp[node][1] + tax[node]) % MOD;
    dp2[node][1] = (dp2[node][1] + tax[node]) % MOD;
}

int solve(int A, vector<vector<int>> &B, vector<pair<int, int>> &C) {
    for (int i = 1; i <= A; i++) {
        adj[i].clear();
        tax[i] = 0;
    }
    for (int i = 0; i < A - 1; i++) {
        int u = B[i][0], v = B[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < C.size(); i++) {
        tax[C[i].first]++;
        tax[C[i].second]++;
    }
    dfs(1, 0);
    int ans = min(dp[1][0], dp[1][1]);
    ans = min(ans, dp2[1][0]);
    return ans % MOD;
}


void TestCase()
{
    // int T;
    // cin>>T;
    // while(T--)
    int A;
    cin>>A;
    vector<VI> B;
    for(int i = 0; i<A-1; i++)
    {
        int x, y;
        cin>>x>>y;
        B.push_back({x, y});
    }
    vector<PII> C(A-1);
    for(int i = 0; i<A-1; i++)
    {
        int x, y;
        cin>>x>>y;
        C[i] = {x, y};
    }
    for(int i = 0; i < A;i++)
        cin>>tax[i];
    cout<<solve(A, B, C);
}

int main()
{
    Mentor();
    YOURMENTOR
    //bool prime[N];
    //FindPrime(prime, N);
    TestCase();
    // solve();
    return 0;
}