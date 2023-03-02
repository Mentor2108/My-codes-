#include <bits/stdc++.h>
//Need to do

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
    char c;
    cin>>n>>c;
    string s;
    cin>>s;
    if (c == 'g')
    {
        cout<<0<<endl;
        return;
    }
    VPII x(n, {-1, -1});
    int k = 0, f = -1;
    int temp = 1;
    for(int i = 0; i < n; i++)
    {
        if (s[i] == c && temp == 1)
        {
            temp = -1;
            x[k].F = i;
        } 
        if (s[i] == 'g')
        {
            if (temp == -1)
            {
                x[k].S = i;
                k++; 
                temp = 1;
            }
        }
        if (f==-1 && s[i] == 'g')
        {
            f=i;
            temp = 1;
        }
    }
    if (x[k].F != -1)
    {
        x[k].S=n+f;
        k++;
    }
    int maxi = -1;
    for(int i = 0; i < k; i++)
    {
        // cout<<x[i].F<<" "<<x[i].S<<endl;
        maxi=max(maxi, -x[i].F+x[i].S);
    }
    cout<<maxi<<endl;
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