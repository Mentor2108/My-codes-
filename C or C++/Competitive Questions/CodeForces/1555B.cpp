#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;

using namespace std;

void solve()
{
    ll W, H;
    cin >> W >> H;
    ll x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll w, h;
    cin >> w >> h;
    if (((x2 - x1 + w) > W) && ((y2 - y1 + h) > H))
    {
        cout << "-1\n";
        return;
    }

    double ans = 0.000000000;
    cout << fixed;
    cout << setprecision(9);
    ll space1 = 0, space2 = 0;
    ll mini1 = -1, mini2 = -1;
    space1 = H - y2;
    space2 = W - x2;
    ll check = -1; //0 - bottom, 1 - left, 2- top, 3- right

    if (h <= space1 || w <= space2 || h <= y1 || w <= x1)
        cout << ans << "\n";
    else if (h <= space1 + y1)
    {
        if (w <= space2 + x1)
        {
            mini1 = min(h - space1, h - y1);
            mini2 = min(w - space2, w - x1);
            ans = min(mini1, mini2);
            cout << ans << "\n";
        }
        else
        {
            ans = min(h - space1, h-y1);
            cout<< ans<<"\n";
        }
    }
    else
    {
        ans = min(w - space2, w - x1);
        cout << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}