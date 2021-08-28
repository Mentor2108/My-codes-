#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;

using namespace std;

void mentor()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

void solve()
{
    char a[100];
    cin>>a;
    int l = strlen(a);
    int m = 0, cv = 0, cc = 0;
    int valc = 0, valv = 0, Max = 0;
    int count[26] = {};
    for (int i = 0; i < l; i ++)
    {
        count[a[i]-65]++;
    }
    for (int i = 0; i < l; i++)
    {
        switch(a[i])
        {
            case 'A': 
            case 'E':
            case 'I':
            case 'O':
            case 'U':cv++; valv = max(valv, count[a[i] - 65]); break;
            default: cc++; valc = max(valc, count[a[i] - 65]);
        }
    }
    // cout<<"valc = "<<valc<<", valv = "<<valv<<", cv = "<<cv<<", cc = "<<cc<<endl;
    if (valc == l)
    {
        cout<<"0";
        return;
    }
    Max = max(valc,valv);
    int ans1 = (cv - valv)*2 + cc;
    int ans2 = (cc - valc)*2 + cv;
    // cout<<ans1<<" "<<ans2<<endl;
    cout<<min(ans1,ans2); 
}

int main()
{
    mentor();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for (int i = 0; i < T; i ++)
    {
        cout<<"Case #"<<i+1<<": ";
        solve();
        cout<<"\n";
    }
    return 0;
}