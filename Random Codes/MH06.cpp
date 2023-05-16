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
    ll n, id, mx;
    vector<ll> v[26];
    string s;
    
    cin>>n;
    cin>>s;
    
    for(int i=0;i<n;){
        
        int j=i;
        while(j<n && s[j]==s[i])
            j++;
            
        v[(ll)(s[i]-'a')].PB(j-i);
        i=j;
    }
    
    for(int i=0;i<26;i++)
    {
        sort(v[i].begin(),v[i].end());
        vector<ll> temp;
        
        for(int j=(ll)v[i].size()-1; j>=0; j--)
            temp.PB(v[i][j]);
        
        for(int j=0; j<v[i].size(); j++)
        {
            if(j)
                temp[j] += temp[j-1];
            v[i][j] = temp[j];
        }
    }
    for(int i=0;i<n+1;i++)
    {    
        mx=0;
        for(int j=0;j<26;j++)
        {    
            if(v[j].empty())
                continue;
            id=min( (ll) v[j].size()-1, i);
            mx=max(mx, v[j][id]);
        }
        
        cout<<mx<<" ";
    }
    
    cout<<"\n";
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