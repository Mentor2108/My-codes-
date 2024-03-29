#include <bits/stdc++.h>
//I need to work on this
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

int findans(VI pos, VI val, int x, int y, int n, int d)
{
    cout<<"min = "<<x<<" "<<y<<endl;
    int z;
    if (pos[n-1] == n)
        z = 0;
    else
        z = d-pos[n-1]-1;
    if (y == n-1)
    {
        z = d-pos[n-2] - 1;
        val[y] = z;
    }
    else if (y>0)
        val[y] = pos[y+1] - pos[y-1] - 1;
    else 
    {
        val[y] = val[1]-1;
    }
    int temp = *max_element(val.begin(), val.end())/2;
    temp = max(temp, z);
    int ans = min(*min_element(val.begin(), val.end()), temp);
    return ans;
}

void solve()
{
    int n, d;
    cin>>n>>d;
    VI pos(n);
    VI val(n);
    int y = 0;
    ll x = INT_MAX;
    FOR(i, n, 1)
    {
        cin>>pos[i];
        if (i>0)
        {
            val[i] = pos[i] - pos[i-1] - 1;
            if (x>val[i])
            {
                x = val[i];
                y = i;
            }
        }
    }
    val[0] = pos[0] - 1;
    if (x > val[0])
    {
        x = val[0];
        y = 0;
    }    
    int ans = -1;
    for(int i = 0; i < n; i++)
    {
        cout<<"i: "<<i<<endl;
        if (val[i] == x)
        {
            ans = max(findans(pos, val, x, i, n, d), ans);
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