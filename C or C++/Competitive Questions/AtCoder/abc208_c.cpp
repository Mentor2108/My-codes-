#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
// const int N = ;

using namespace std;

void solve()
{
    ll n, k;
    cin>>n>>k;
    vector<pair<ll, ll>> a;
    vector<ll> ans(n,k/n);
    for (int i = 0; i <n; i++)
    {
        ll x;
        cin>>x;
        a.push_back(make_pair(x,i));
    }
    sort(a.begin(), a.end());
    k%=n;
    for (int i = 0; i<k; i++)
    {
        ans[a[i].second]++;
    }
    for (auto i: ans)
    {
        cout<<i<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}