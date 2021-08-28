#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
const int N = 5000;

using namespace std;

void solve()
{
    ll t;
    cin>>t;
    while(t--)
    {
        char a[N];
        cin>>a;
        int l = strlen(a);
        if (a[0] ==  '1')
        {
            cout<<a[0]<<'0';
            for (int i = 1; i<l; i++)
                cout<<a[i];
        }
        else
        {
            cout<<'1';
            for (int i = 0; i < l;i++)
                cout<<a[i];
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