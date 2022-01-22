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
    ll n, ans = 0, flag = 1;
    cin>>n;
    for (int i = 15; i >= 0; i--)
    {
        ll temp = 2050*Fastpow(10, i);
        if (n - temp == 0)
        {
            ans++;
            cout<<ans<<endl;
            return;
        }
        else if (n - temp < 0)
        {
            continue;
        }
        else 
        {
            for (int j = 0; j < 10; j++)
            {
                if (n - temp == 0)
                {
                    cout<<ans+1<<endl;
                    return;
                }
                else if(n-temp < 0)
                {
                    break;
                }
                ans++;
                n-=temp;
                flag = 0;
            }
        }
    }
    cout<<"-1\n";
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