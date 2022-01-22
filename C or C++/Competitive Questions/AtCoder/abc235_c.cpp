#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
const ll N = 100000;
//not working yet, need to use vector instead of count[]

using namespace std;

void solve()
{
    map<pair<int, int>,int> mp; 
    int n,q;
    cin>>n>>q;
    int a[n], count[N] = {};
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        count[a[i]%5340]++;
        mp[{a[i], count[a[i]]}] = i+1;
    }
    while(q--)
    {
        int a, b;
        cin>>a>>b;
        if (mp[{a,b}])
        {
            cout<<mp[{a,b}]<<"\n";
        }
        else
        {
            cout<<"-1\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int T;
    // cin>>T;
    // while(T--)
        solve();
    return 0;
}