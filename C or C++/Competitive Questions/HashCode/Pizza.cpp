#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;

//work in progress
using namespace std;

void solve()
{
    int r,c,l,h;
    cin>>r>>c>>l>>h;
    int a[r][c];
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c;j++)
        {
            int x;
            cin>>x;
            if (x=='T')
                a[i][j] = 0;
            else if (x=='M')
                a[i][j] = 1;
        }
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