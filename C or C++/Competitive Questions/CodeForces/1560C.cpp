#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;

using namespace std;

void solve()
{
    ll k;
    cin>>k;
    ll r = 0, c = 0, temp = 0;
    for (int i = 1;; i++)
    {
        ll x = i*i;
        if (k==x)
        {
            cout<<i<<" "<<1<<"\n";
            return;
        }
        if (x>k)
        {
            temp = (i-1)*(i-1);
            temp = temp + i;
            if (k == temp)
            {
                cout<<i<<" "<<i<<"\n";
                return;
            }
            else if (k > temp)
            {
                cout<<i<<" "<<i - k + temp<<"\n";
                return;
            }
            else
            {
                cout<<i - temp + k<<" "<<i<<"\n";
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}