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

bool cmp(pair<int, int> x, pair<int, int> y)
{
    if (x.first != y.first)
        return x.first > y.first;
    else
        return x.second < y.second;
}

void solve()
{
    int n, x, y, z;
    cin>>n>>x>>y>>z;
    VPII m(n), e(n), add(n);
    VI ans;
    FOR(i, n, 1)
    {
        int a;
        cin>>a;
        add[i] = {a, i+1};
        m[i] = {a, i+1};
    }
    FOR(i, n, 1)
    {
        int a;
        cin>>a;
        add[i].first+=a;
        e[i] = {a, i+1};
    }
    if (x)
    {
        sort(m.begin(), m.end(), cmp);
        for(int i = 0; i<x; i++)
        {
            ans.PB(m[i].S);
        }
    }
    if (y)
    {
        sort(e.begin(), e.end(), cmp);
        for(int i = 0, k = 0; i<n; i++, k++)
        {
            if (k == y)
                break;
            if (count(ans.begin(), ans.end(), e[i].S))
            {
                k--;
                continue;
            }
            ans.PB(e[i].S);
        }       
    }
    if (z)
    {
        sort(add.begin(), add.end(), cmp);
        for(int i = 0, k =0; i<n; i++, k++)
        { 
            if (k == z)
                break;
            if (count(ans.begin(), ans.end(), add[i].S))
            {
                k--;
                continue;
            }
            ans.PB(add[i].S);
        }       
    }    
    sort(ans.begin(), ans.end());
    for(int i = 0; i<ans.size(); i++)
    {
        cout<<ans[i]<<endl;
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