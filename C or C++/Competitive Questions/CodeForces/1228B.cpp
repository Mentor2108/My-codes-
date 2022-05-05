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
        return ((res * res)%mod * base)%mod;
    else
        return ((res%mod) * (res%mod))%mod;
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


/*
    int h, w;
    cin>>h>>w;
    int r[h], c[w];
    vector<vector<int>> vec(h, vector<int> (w, 0));
    FOR(i, h, 1)
    {
        cin>>r[i];
        int end = r[i]==w?r[i]:r[i]+1;
        FOR(j, end, 1)
        {
            vec[i][j] = 1;
        }
    }
    FOR(i, w, 1)
    {
        cin>>c[i];
        int end = c[i]==h?c[i]:c[i]+1;
        FOR(j, end, 1)
        {
            vec[j][i] = 1;
        }
    }
    FOR(i, h, 1)
    {
        FOR(j, w, 1)
        {
            cout<<vec[i][j]<<" "; 
        }
        cout<<endl;
    }
    int sum = 0;
    FOR(i, h, 1)
        sum += count(vec[i].begin(), vec[i].end(), 0);
    // cout<<sum;
    if (sum == 0)
    {
        cout<<"0";
        return;
    }
    ll ans = 1;
    for(int i = 0; i < sum; i ++)
    {
        ans = ((ans%mod)*2)%mod;
    }
    cout<<ans; */

void solve()
{
    int h, w;
    cin>>h>>w;
    VI row(h);
    VI column(w);
    vector<vector<int>> mat(h, vector<int> (w, 0)); 
    // FOR(i, h, 1)
    // {
    //     FOR(j, w, 1)
    //     {
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    FOR(i, h, 1)
    {
        cin>>row[i];
        FOR(j, row[i], 1)
        {
            mat[i][j] = 1;
        }
        if (row[i] < w)
            mat[i][row[i]] = 2;
    }
    FOR(j, w, 1)
    {
        cin>>column[j];
        FOR(i, column[j], 1)
        {
            if(mat[i][j] == 2)
            {
                cout<<"0"<<endl;
                return;
            }
            mat[i][j] = 1;
        }

        if(column[j] <h)
        {
            if (mat[column[j]][j] == 1)
            {
                cout<<"0"<<endl;
                return;
            }
            mat[column[j]][j] = 2;
        }
    }
    // cout<<endl;
    ll ans = 0;
    FOR(i, h, 1)
    {
        FOR(j, w, 1)
        {
            if (mat[i][j] == 0)
                ans++;
            // cout<<mat[i][j]<<" ";
        }
        // cout<<endl;
    }
    cout<<Fastpow(2, ans)<<endl;
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
    // TestCase();
    solve();
    return 0;
}