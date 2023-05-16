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
    int p, s;
    cin>>p>>s;
    vector<pair<int, int>> a[p];
    VPII ans(p);
    int n = 0;
    for(int i = 0; i<p; i++)
    {
        vector<pair<int, int>> temp(s);
        for(int j = 0; j<s; j++)
        {
            cin>>temp[j].F;
        }
        // n = 0;
        for(int j = 0;j<s; j++)
        {
            cin>>temp[j].S;
        }
        for(int j = 0; j<s; j++)
        {
            a[i].PB({temp[j].F, temp[j].S});
        }
        sort(a[i].begin(), a[i].end());
        ans[i].S = i+1;
    }
    // for(int i = 0; i < p; i++)
    // {
    //     for(int j = 0; j<s; j++)
    //     {
    //         cout<<a[i][j].F<<" "<<a[i][j].S;
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }
    for(int i = 0; i < p; i++)
    {
        n = 0;
        for(int j = 0; j<s-1; j++)
        {
            if (a[i][j].S>a[i][j+1].S)
                n++;
        }
        ans[i].F = n;
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i<p; i++)
    {
        cout<<ans[i].S<<endl;
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