#include <bits/stdc++.h>
//Need to do

#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//I dont know implementation    
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
    int m, n;
    cin>>n>>m;
    VI vec(n);
    VPII streak(m);
    map<int, int> mp;
    vector<long> presum(n+1, 0), postsum(n+1, 0);
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        cin>>vec[i];
    }
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin>>a>>b;
        streak[i].F = a;
        streak[i].S = b;
        mp[a] = b;
    }

    vector dp(n+1, vector<ll>(n+1, 0));
/* 9
    presum[1] = mp[1];
    for(int i = 2; i<=n; i++)
    {
        presum[i] = presum[i-1] + mp[i];
    }

    postsum[n] = mp[n];
    for(int i = n-1; i>0; i--)
    {
        postsum[i] = postsum[i+1] + mp[i];
    }
    int s = 0;
    for(int i = 0; i < n; i++)
    {
        int max_s1 = min(streak[m-1].F-s, n-i);
        // cout<<"max_s1 = "<<max_s1<<endl;
        // cout<<presum[max_s1]<<" "<<postsum[max_s1]<<" "<<vec[i]<<endl;
        if (m == 1)
        {
            if (s==streak[0].F)
            {
                if (presum[])
            }
        }
        if (( (ll)presum[max_s1] >=((ll)postsum[max_s1] + (ll)vec[i])) && s!=0)
        {
            // cout<<"fail = "<<i<<endl;
            s = 0;
        }
        else
        {
            cout<<i<<endl;
            s++;
            ans+=(vec[i] + mp[s]);
        }
        // cout<<"s = "<<s<<endl;
        // ans+=max(presum[max_s1], postsum[max_s1]+vec[i]);
    }
    cout<<ans; */
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