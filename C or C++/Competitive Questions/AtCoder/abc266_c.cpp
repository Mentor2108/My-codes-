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
    vector<pair<double, double>> n(4);
    for (int i = 0; i < 4;i++)
    {
        cin>>n[i].F>>n[i].S;
    }
    for (int i = 0; i < 4;i++)
    {
        double temp1 = (n[i].S - n[(i+1)%4].S)/(n[i].F - n[(i+1)%4].F);
        double temp2 = (n[(i+1)%4].S - n[(i+2)%4].S)/(n[(i+1)%4].F - n[(i+2)%4].F);
        // double temp = (n[0].F)/(n[0].S);
        double x = 180.0/M_PI;
        double ang1 = abs(atan(temp1)*x);
        double ang2 = abs(atan(temp2)*x);
        double angle = abs(ang1 - ang2);
        cout<<ang1 << " "<<ang2<<endl;
        if (angle<0)
        {
            angle = 360+angle;
        }
        cout<<angle<<endl;
        if (angle >=180)
        {
            cout<<"No";
            return;
        }
    }
    cout<<"Yes";
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