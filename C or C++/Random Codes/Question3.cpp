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

vector<int> m(1<<14, INT_MAX);
int N;

int dp(vector<int> &A, vector<int> &B, int i, int mask) {
    if (i == N) return 0;
    if (m[mask] != INT_MAX) return m[mask];
    int ans = INT_MAX;
    for (int j = 0; j < N; ++j) {
        if (mask >> j & 1) continue;
        ans = min(ans, (A[i] ^ B[j]) + dp(A, B, i + 1, mask | (1 << j)));
    }
    return m[mask] = ans;
}


void solve()
{
    cin>>N;

    vector<int> a(N), b(N);
    FOR(i, N, 1) {
        cin>>a[i];
    }
    FOR(i, N, 1) {
        cin>>b[i];
    }

    cout<<dp(a, b, 0, 0);
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
    // solve();
    return 0;
}