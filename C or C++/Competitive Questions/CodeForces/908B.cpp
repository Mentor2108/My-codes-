#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
// const int N = ;
//in work
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    char a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'S')
                make_pair(i,j)
        }
    }

    string s;
    cin>>s;
    int l = s.length();
    // 0 = left, 1 = top, 2 = right, 3 = down
    for (I = 0; I < 4; I++ ) // 0
    {
        for (J = 0; J< 4; J++) // 1
        {
            if (J == I)
                continue;
            for (K = 0; K<4;K++) //2
            {
                if (K == J || K == I) 
                    continue;
                for (L = 0; L<4;L++) //3
                {
                    if (L == J || L == K || L == I)
                        continue;
                    for (i = 0; i < l; i++)
                    {
                        if (s[i] == '0')
                        {
                            if (I == 0)
                            {

                            }

                        } 

                    }                
                }
            }
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