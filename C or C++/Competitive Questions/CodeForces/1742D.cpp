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

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);   
}

void solve()
{
    int n;
    cin>>n;
    VI a(n);
    FOR(i, n, 1)
    {
        cin>>a[i];
    }
    for(int i = 2*n; i > n; i--)
    {   
        if (a[i/2] == 1)
        {
            cout<<i<<endl;
            return;
        }
        else if (gcd(a[i], a[i-1]) == 1)
        {
            cout<<i<<endl;
            return;
        }
        else if (gcd(a[i], a[i-2]) == 1)
        {
            cout<<i<<endl;
            return;
        }
    }

    for(int i = n; i>=0; i--)
    {
        for(int j = 0, k = n; k>=j; k--, j++)
        {
            if (a[i] == 1)
            {
                cout<<(i+1)*2<<endl;
                return;
            }
            else if (gcd(a[i], a[i-1]) == 1)
            {
                cout<<2*(i+1)-1<<endl;
                return;
            }
            else if (gcd(a[i], a[i-2]) == 1)
            {
                cout<<2*(i+1)-2<<endl;
                return;
            }
        }
    }
    cout<<-1<<endl;

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