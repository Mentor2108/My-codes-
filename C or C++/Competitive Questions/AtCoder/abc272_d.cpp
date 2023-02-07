#include <bits/stdc++.h>
//Need to do

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

int n,m;

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

bool func(VPII &val)
{
    int i = 0;
    while(i*i<=m)
    {
        int x=m-i*i;
        int y = sqrt(x);
        if (y*y == x)
        {
            val.PB({i,y});
        }
        i++;
    }
    if (val.size())
        return true;
    return false;
}

void solve()
{
    cin>>n>>m;
    vector<pair<int, int>> val;
    queue<pair<int, int>> q;
    q.push({1,1});
    vector<vector<int>> v(n+1, vector<int>(n+1, -1));
    v[1][1]=0; 
    if (!func(val))
    {
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    int t = 0;
    while(!q.empty())
    {
        PII p = q.front();
        q.pop();
        t = v[p.F][p.S];
        for(auto i: val)
        {
            auto [a,b] = i;
            cout<<a<<" "<<b;
        }
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