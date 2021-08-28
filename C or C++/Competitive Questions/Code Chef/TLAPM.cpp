#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
const int N = 1001;

using namespace std;

void solve()
{
    ll a[N][N];
    for (int i = 1; i<N;i++)
    {
        for (int j = 1; j<N; j++)
        {
            a[i][j] = (((j*j) - j)/2) + 1 + (j*(i-1) + ((i-1)*(i))/2);
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        ll sum = 0;
        int i, j;
        for (i = x1;i<=x2;i++)
        {
            sum+=a[i][y1];
        }
        for (j = y1+1; j <=y2; j ++)
        {
            sum+= a[x2][j];
        }

        cout<<sum<<"\n";
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