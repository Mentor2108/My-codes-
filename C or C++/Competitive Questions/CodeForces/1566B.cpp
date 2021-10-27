#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;

using namespace std;

void solve()
{
    char a[100000];
    cin>>a;
    char mex[100000] = "";
    int l = strlen(a), flag = 0, maxi = -1;
    ll ans = 0;
    if (l == 1 && a[0] == '0')
    {
        cout<<"1\n";
        return;
    }
    for (int i =0; i < l; i++)
    {
        if (flag == 0 && a[i] == '0')
        {
            // ans++;
            flag = 1;
            // cout<<"i = "<<i<<"\n";
        }    
        else if (flag == 1 && a[i] != '0')
        {
            ans++;
            flag = 0;
            // cout<<"i = "<<i<<"\n";
        }
        if (i == l-1 && a[i] == '0')
        {
            ans++;
        }
    }
    cout<<ans<<"\n";
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