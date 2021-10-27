#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;

using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);
    int x;
    scanf("%d", &x);
    int a[n][n];
    a[0][0] = (rand()%10000) - (rand()%10000);
    int maxi = a[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != 0)
            {
                maxi = a[i-1][j];
                // maxi = max (maxi, a[i-1][j]);
                if (j != 0)
                {
                    maxi = max(maxi, a[i][j-1]);
                }
                a[i][j] = rand()%(x*(j+10)) + maxi;
            }    
            if (i == 0)
            {
                if (j != 0)
                {
                    maxi = a[i][j-1];
                } 
                a[i][j] = rand()%(x*(j+10)) + maxi;
            }         
            // printf("a[%d][%d] = %d\n", i, j, a[i][j]);
        }
        // printf("a[%d][%d] = %d\n", i, 0, a[i][0]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int T;
    // cin>>T;
    // while(T--)
        solve();
    return 0;
}