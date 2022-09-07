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

void solve()
{
    int n, k, z = 1;
    cin>>n>>k;
    VI p(n+1), top(n+1, 0), len(n+1, 0), final(n+1, -1);
    vector<vector<int>> ans(n+1);
    if (k==1)
    {
        for(int i =1; i<=n;i++)
        {
            cin>>p[i];
            cout<<i<<endl;
        }
        return;
    }
    for(int i = 1; i<=n; i++)
    {
        int m = n+2, mp = -1;
        cin>>p[i];
        if (i == 1)
        {
            len[z] = 1;
            top[z]=p[i];
            ans[z++].PB(p[i]);
        }    
        else 
        {
            for(int j = 1; j<=z; j++)
            {
                if (top[j] > p[i])
                {
                    if (m>top[j])
                    {
                        m = top[j];
                        mp = j;
                    }
                }
            }
            if (m==n+2)
            {
                len[z] = 1;
                top[z] = p[i];
                ans[z++].PB(p[i]);
            }
            else
            {
                ans[mp].PB(p[i]);
                top[mp] = p[i];
                len[mp]++;
            }
        }
        if (m!=n+2)
        {
            if (len[mp] == k)
            {
                for(int j = 0; j<ans[mp].size(); j++)
                {
                    final[ans[mp][j]] = i;
                }
                top[mp] = -1;
                len[mp] = -1;
            }
        }
    }
    for(int i = 1; i<=n; i++)
    {
        cout<<final[i]<<endl;
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