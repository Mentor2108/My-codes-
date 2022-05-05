#include <bits/stdc++.h>

#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//Will complete it sometime later
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
    int n, d;
    cin>>n>>d;
    /* int a[n], ans[n+1], maxi = -5;
    pair<int, int> m = {INT_MAX, -1};
    cin>>a[0];
    ans[0] = a[0]-1;
    for(int i = 1; i < n; i++)
    {
        cin>>a[i];
        ans[i] = a[i] - a[i-1] - 1;
        maxi = max(maxi, ans[i]);
        cout<<"maxi = "<<maxi<<" mini = ";
        if (m.first > ans[i])
        {
            m.first = ans[i];
            m.second = i+1;
        }
        cout<<m.first<<", second = "<<m.second<<endl;
    }
    ans[n] = (d-a[n-1] - 1)*2;
    maxi = max(maxi, ans[n]);
    for(int i = 0; i <= n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    if(ans[n] != -2)    
    {
        if (maxi < ans[n])
        {
            cout<<"maxi = "<<maxi<<endl;
            cout<<m.first<<endl;
            return;
        }
        if (m.first > ans[n])
        {
            m.first = ans[n];
            m.second = n;
        }
    }
    cout<<"mini = "<<m.first<<", second = "<<m.second<<endl;
    m.first = min(m.first, maxi/2);
    cout<<m.first<<endl<<endl; */

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