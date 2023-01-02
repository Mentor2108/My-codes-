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
    int n, m;
    cin>>n>>m;
    vector<VI> a(n+1, VI(m+1, 0));
    int x1, y1, x2, y2;
    int ans = 2, parity1 = -1, parity2 = -1;
    cin>>x1>>y1>>x2>>y2;
    parity1 = (x1 + y1)%2;
    parity2 = (x2 + y2)%2;
    if (parity1 == parity2 && parity1 == 1)
        ans = 3;
    else if (parity1 == parity2 && parity1 == 0)
        ans = 4;
    else if (parity1 == 1)
        ans = 2;
    else 
        ans = 1;
    if (ans == 3)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j<=m; j++)
            {
                if ((i+j)%2 == 1)
                {
                    a[i][j] = 1;
                }
                else   
                    a[i][j] = 3;
            }
        }
    }
    else if (ans == 4)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j<=m; j++)
            {
                if ((i+j)%2 == 0)
                {
                    a[i][j] = 1;
                }
                else   
                    a[i][j] = 3;
            }
        }
    }
    else if (ans == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j<=m; j++)
            {
                if ((i+j)%2 == 1)
                {
                    a[i][j] = 1;
                }
                else   
                    a[i][j] = 2;
            }
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j<=m; j++)
            {
                if ((i+j)%2 == 1)
                {
                    a[i][j] = 2;
                }
                else   
                    a[i][j] = 1;
            }
        }        
    }
    a[x1][y1] = 1;
    a[x2][y2] = 2;
    for(int i = 1; i<=n; i++)
    {
        for (int j = 1; j<=m; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
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
    TestCase();
    //solve();
    return 0;
}