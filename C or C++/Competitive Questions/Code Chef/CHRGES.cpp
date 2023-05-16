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
    int n;
    cin>>n;
    string a;
    cin>>a;
    VPII left(n), right(n);
    
    if (a[0] == '0')
        left[0] = {INT_MIN, INT_MIN};
    else if (a[0] == '-')
        left[0] = {0, -1};
    else 
        left[0] = {0, 1};

    for(int i = 1; i < n; i++)
    {
        if (a[i] == '0')
            left[i] = left[i-1];
        else if (a[i] == '-')
            left[i] = {i, -1};
        else  
            left[i] = {i, 1};
    }

    if (a[n-1] == '0')
        right[n-1] = {INT_MIN, INT_MIN};
    else if (a[n-1] == '-')
        right[n-1] = {n-1, -1};
    else 
        right[n-1] = {n-1, 1};
    
    for(int i = n-2; i >= 0; i--)
    {
        if (a[i] == '0')
            right[i] = right[i+1];
        else if (a[i] == '-')
            right[i] = {i, -1};
        else    
            right[i] = {i, 1};
    }
    // for(int i = 0; i < n; i++)
    // {
    //     cout<<left[i].F<<" "<<right[i].F<<endl;
    // }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if (a[i] == '0')
        {
            if ((left[i] == right[i]) || (((i - left[i].F) == (right[i].F - i)) && (left[i].S == -right[i].S)))
            {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
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