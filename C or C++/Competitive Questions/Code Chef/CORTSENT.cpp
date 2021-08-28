#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;

using namespace std;

void solve()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        int val = 0;
        while (k--)
        {
            val = 0;
            char a[100];
            cin >> a;
            int l = strlen(a);
            if (islower(a[0]) && (a[0] >= 'a' && a[0] <= 'm'))
            {
                val = 1;
            }
            else if (isupper(a[0]) && (a[0] >= 'N' && a[0] <= 'Z'))
            {
                val = 2;
            }

            if (val == 0)
            {
                break;
            }

            if (val == 1)
            {
                for (int i = 0; i < l; i++)
                {
                    if (islower(a[i]) && (a[i] >= 'a' && a[i] <= 'm'))
                        val = 1;
                    else
                    {
                        val = 0;
                        break;
                    }
                }
            }
            else if (val == 2)
            {
                for (int i = 0; i < l; i++)
                {
                    if (isupper(a[i]) && (a[i] >= 'N' && a[i] <= 'Z'))
                        val = 2;
                    else
                    {
                        val = 0;
                        break;
                    }
                }
            }

            if (val == 0)
                break;
        }
        while (k>0)
        {
            char a[100];
            cin >> a;
            k--;
        }
        if (val == 0)
            cout << "NO\n";
        else
            cout << "YES\n";
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