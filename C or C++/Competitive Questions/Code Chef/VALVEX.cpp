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

void func(int k, vector<vector<int>> &vec, VPII &cases)
{
    int parityA = k%2;
    int parityB = (parityA + (k == 1 || k == 2))%2;
    VI temp = {(int)vec[0].size() - 1, (int)vec[1].size() - 1};
    while(1)
    {
        if(temp[parityA]<0 && temp[parityB]<0)
            break;
        else if(temp[parityA] >=0)
        {
            cases[k].F += vec[parityA][temp[parityA]];
            temp[parityA]--;
            parityA = (parityA+1)%2;
        }
        else if(temp[parityB] >= 0)
        {
            cases[k].S += vec[parityB][temp[parityB]];
            temp[parityB]--;
            parityB = (parityB + 1)%2;
        }
    }
}

void solve()
{
    int n;
    cin>>n;
    VI a(n);
    vector<vector<int>> vec(2);
    FOR(i, n, 1)
    {
        cin>>a[i];
        int parity = a[i]%2;
        vec[parity].PB(a[i]);       
    }   
    sort(vec[0].begin(), vec[0].end());
    sort(vec[1].begin(), vec[1].end());
    VPII cases(4, {0, 0});
    FOR(i, 4, 1)
    {
        func(i, vec, cases);
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