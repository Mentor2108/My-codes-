#include <bits/stdc++.h>

#define ll long long int
// #define max(a, b) (a > b ? a : b)
// #define min(a, b) (a > b ? b : a)
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

void solve()
{
    //int prime[N];
    //FindPrime(prime, N);
    int n;
    cin>>n;
    pair<int, int> one, two;
    vector<int> vec1(n), vec2(n);
    FOR(i, n, 1)
    {
        cin>>vec1[i];
    }
    one = {vec1[0], vec1[n-1]};
    FOR(i, n, 1)
    {
        cin>>vec2[i];
    }
    two = {vec2[0], vec2[n-1]};
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    ll ans = 0;
    if(vec1[0] == one.first)
    {
        if (vec1[n-1] == one.second)
        {
            
        }
    }
    else if (vec1[0] == one.second)
    {
        
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
    TestCase();
    //solve();
    return 0;
}