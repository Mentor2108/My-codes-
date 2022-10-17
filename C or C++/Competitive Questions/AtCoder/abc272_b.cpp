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
    VI k(m+1);
    vector<vector<int>> person(n+1);
    vector<vector<int>> x(m+1);
    for(int i = 1; i <= m; i++)
    {
        cin>>k[i];
        x[i].PB(0);
        for(int j = 1; j<=k[i]; j++)
        {
            int y;
            cin>>y;
            x[i].PB(y);
            person[x[i][j]].PB(i);
        }
    }    

    for(int i = 1; i<n; i++)
    {
        int l1 = person[i].size();
        for(int j = i+1; j<=n; j++)
        {
            int temp = 0;
            int y = 0, z = 0;
            int l2 = person[j].size();
            while(y<l1 && z<l2)
            {
                if (person[i][y] == person[j][z])
                {
                    temp = 1;
                    break;
                }
                else if (person[i][y] > person[j][z])
                {
                    z++;
                }
                else 
                {
                    y++;
                }
            }
            if (!temp)
            {
                cout<<"No";
                return;
            }
        }
    }
    cout<<"Yes";
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