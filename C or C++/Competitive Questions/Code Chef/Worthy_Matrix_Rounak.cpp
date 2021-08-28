#include <iostream>

using namespace std;

typedef long long int ll;


int main()
{
    ll t;

    cin >> t;
    for(ll q = 1 ; q<=t ;q++)
    {
        ll n,m,k;
        cin >> n >> m >> k;

        double a[n+1][m+1];

        ll count = 0;

        for(ll i = 0 ; i <= n; i++)
        {
            for(ll j = 0;j <= m; j++)
            {
                if(i==0 || j==0)
                {
                   a[i][j] = 0;
                }
                else
                {
                    cin >> a[i][j];
                    if (a[i][j]>=k)
                        count++;
                }
            }
        }

        for(ll i = 0; i <= n; i++)
        {
            double prev = 0;
            for(ll j = 0; j <=m; j++)
            {
                a[i][j] += prev;
                prev = a[i][j];
            }
        }

        for(ll j = 0;j <= m; j++)
        {
            double prev=0;
            for(ll i = 0;i <= n; i++)
            {
                a[i][j] += prev;
                prev = a[i][j];
            }
        }

        for(ll order = 2; order <= min(n,m); order++)
        {
            for(ll i = order;i <= n; i++)
            {
                for(ll j = order; j<= m; j++)
                {
                    if((a[i][j]+a[i-order][j-order]-a[i][j-order]-a[i-order][j])/(order*order)>=k)
                    {
                        count += m - j + 1;
                        break;
                    }
                }
            }
        }
        cout << count  << endl;
    }
}