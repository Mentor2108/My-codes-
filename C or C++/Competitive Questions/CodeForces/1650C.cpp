#include <bits/stdc++.h>

#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007

#define YOURMENTOR ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define FOR(i, n, k) for(int i = 0; i<n; i+=k)
#define endl "\n"
#define PB push_back

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

void FindPrime(int* prime, int N) {
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

struct sys
{
    int pos, val, id;
};

void solve()
{
    //int prime[N];
    //FindPrime(prime, N);
    int n, m;
    ll ans = 0;
    cin>>n>>m;
    sys a[m];
    for (int i = 0; i < m; i ++)
    {
        cin>>a[i].pos>>a[i].val;
        a[i].id = i+1;
    }
    sort(a, a+m, [](sys a, sys b){
        return a.val<b.val;
    });
    vector<pair<int, int>> vec;
    for(int i = 0; i < 2*n; i++)
    {
        vec.push_back({a[i].pos, a[i].id});
        ans+=a[i].val;
    }
    cout<<ans<<endl;
    sort(vec.begin(), vec.end());
    int l = 0, r = vec.size()-1;
    while(l < r)
    {
        cout<<vec[l].second<<" "<<vec[r].second<<endl;
        l++;
        r--;
    }
    cout<<endl;
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
    TestCase();
    //solve();
    return 0;
}