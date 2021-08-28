#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)

unsigned ll power[66] = {};

using namespace std;

void solve()
{
    power[0] = 1;
    power[1] = 2;
    for (int i = 2;i<=62;i++)
    {
        power[i] = power[i-1]*2;
    }         
    ll t;
    cin>>t;
    while(t--)
    {
        int count = 0;
        ll n;
        cin>>n;
        for (int i = 1; i<=60; i++)
        {
            if (power[i]>n)
            {
                n = n - power[i-1];
                count++;
                if (n==0)
                    break;
                i = 1;
            }
        }
        cout<<count<<"\n";
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