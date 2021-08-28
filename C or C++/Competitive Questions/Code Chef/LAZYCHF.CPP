#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;

using namespace std;

void solve()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,m,d;
        cin>>x>>m>>d;
        cout<<((x*m>x+d)?(x+d):(x*m))<<"\n";
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