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
    VI vec1(n), vec2(m);
    ll diff = 0;
    FOR(i, n, 1)
    {
        cin>>vec1[i];
        diff+=vec1[i];
    }
    FOR(i, m, 1)
    {
        cin>>vec2[i];
        diff-=vec2[i];
    }
    if (diff>0)
    {
        cout<<0;
        return;
    }
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    ll ans = 0, i = 0;
    while(1)
    {
        if (diff > 0)
        {
            cout<<ans;
            return;
        }
        if (vec1[i]>=vec2[m-i-1])
        {
            cout<<-1;
            return;
        } 
        if (diff == 0)
        {
            // diff = diff + vec2[m-i-1] - vec1[i];
            cout<<ans+1;
            return; 
        }
        else 
        {
            diff = diff + 2*(vec2[m-i-1] - vec1[i]);
        }
        i++;
        ans++;
        // cout<<"i = "<<i<<endl;
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
    // Mentor();
    YOURMENTOR
    //bool prime[N];
    //FindPrime(prime, N);
    // TestCase();
    solve();
    return 0;
}