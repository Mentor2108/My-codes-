#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;

using namespace std;

void solve()
{
    ll n;

    cin >> n;
    vector<int> a(n);

    int maxi = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxi = max(maxi, a[i]);
    }

    vector<int> ar(floor(log2(maxi)) + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int x = 0;
        for (int j = a[i]; j > 0; j /= 2)
        {
            if (j & 1)
            {
                ar[x]++;
            }
            x++;
        }
    }
    long long int ans = 0;
    for (int i = 0; i < ar.size(); i++)
    {
        if (ar[i] > n / 2)
        {
            ans += pow(2, i);
        }
    }
    cout << ans << " ";
    long long int sum = a[0] ^ ans;
    for (int i = 1; i < n; i++)
    {
        sum |= (a[i] ^ ans);
    }
    cout << sum << "\n";
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