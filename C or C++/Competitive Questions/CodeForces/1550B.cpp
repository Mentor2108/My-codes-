#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
// const int N = ;
//cannot do it ;-;
using namespace std;

void solve()
{
    int T:
    cin>>T;
    while(T--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        string s;
        cin>>s;
        int check = 5;
        if (b<=0 && a > 0)
            check = 1;
        else if (b == 0 && a < 0)
            check = 2;
        else if (b<0 && a<0)
            check = 3;
        else if
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