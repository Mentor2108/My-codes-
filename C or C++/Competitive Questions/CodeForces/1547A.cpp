#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
// const int N = ;

using namespace std;

void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        int xa, xb, ya, yb, xf, yf, ans = 0;
        cin >> xa >> ya;
        cin >> xb >> yb;
        cin >> xf >> yf;
        ans += abs(xa - xb) + abs(ya - yb);
        if ((xa == xb) && (xb == xf))
        {
            if  (((yf>ya) && (yf<yb)) || ((yf<ya) && (yf>yb))) 
            {
                ans += 2;
            }
        }
        else if ((ya == yb) && (yb == yf) && (((xf>xa) && (xf<xb)) || ((xf<xa) && (xf>xb))))
        {
            ans += 2;
        }
        cout<<ans<<"\n";
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