#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;

using namespace std;

void solve()
{
    ll t;
    cin>>t;
    while(t--)
    {
        char a[11], b[11];
        cin>>a>>b;
        int l1 = strlen(a), l2 = strlen(b);
        int mini = min(l1,l2), maxi = max(l1,l2);
        int count = 0;  
        int greater = (l1>l2)?(1):(2);
        
        char ans[maxi];
        for (i = mini-1;count<mini;count++)
        {
            ans[i] = (((x[i]-48) + (y[i]-48))%10)+48;
        }
        for (i = 11-min;i<11; i++)
        {
            cout<<ans[i];
        }
        cout<<"\n";
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