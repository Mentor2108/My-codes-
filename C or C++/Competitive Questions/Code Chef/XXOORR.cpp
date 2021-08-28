#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
// const int N = 30;

using namespace std;

ll two[30] = {};

void calc_twoPower()
{
    for (int i = 2; i < 30; i++)
        two[i] = two[i - 1] * 2;
}

void solve()
{
    two[0] = 1;
    two[1] = 2;
    calc_twoPower();
    int t;
    cin >> t;
    while (t--)
    {
        
        bitset<
        int n, k;
        cin >> n >> k;
        ll a[n];
        ll count = 0, ans = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 29; i >= 0; i--)
        {
            count = 0;
            for (int j = 0; j < n; j++)
            {
                if (a[j] >= two[i])
                {
                    count++;
                    a[j] -= two[i];
                }
            }
            ans += ceil((float)count / k);
        }
        cout << ans << "\n";
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