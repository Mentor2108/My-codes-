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
    int n, k;
    cin>>n>>k;
    set<int> s;
    int maxi = INT_MIN, mini=INT_MAX;
    for(int i =0;i<n; i++)
    {
        int x;
        cin>>x;
        s.insert(x);
        maxi=max(maxi, x);
        mini=min(mini, x);
    }
    int y=1;
    ll ans = 0;
    if (k==1)
    {
        for(auto i: s)
        {
            if (y==i)
            {
                y++;
                continue;
            }
            else 
            {
                cout<<maxi-y<<endl;
                return;
            }
        }
        cout<<0<<endl;
        return;
    }
    if (maxi != 2*n)
    {
        k--;
        s.insert(2*n);
        maxi=2*n;
        cout<<"max = "<<maxi<<endl;
    }

    for(auto i: s)
    {
        if (y==i)
        {
            continue;
            y++;
        }
        else 