#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;
int max_count = 0;
using namespace std;

int mostFrequent(ll arr[], int n)
{
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++)
        hash[arr[i]]++;
 
    int res = -1;
    for (auto i : hash) {
        if (max_count < i.second) {
            res = i.first;
            max_count = i.second;
        }
    }
 
    return res;
}
 

void solve()
{
    max_count = 0;
    int n;
    cin>>n;
    ll a[n];
    int flag1 = 0, flag2 = 0;
    for (int i = 0; i <n; i ++)
    {
        cin>>a[i];
        if (a[i] == 1)
            flag1 = 1;
        if (a[i] == 2)
            flag2 = 1;
    }
    if (flag1 && flag2)
        cout<<n<<"\n";
    else
    {
        ll ans = mostFrequent(a, n);
        cout<<n - max_count<<"\n";
    }

}   

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}