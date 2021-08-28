#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)

using namespace std;
//incomplete, will do later
void solve()
{
    char a[100000];
    char c;
    cin>>a;
    ll y, count = 0, stop = 0, pos_in = 0;
    cin>>c>>y;
    ll ans = 0;
    ll pos[100000] = {};
    ll l = strlen(a);
    for (int i = 0; i<l; i++)
    {
        if (a[i] == c)
        {
            pos[count+1] = i+1;
            count++;
        }
    }
    if (count == 0)
    {
        cout<<0;
        return;
    }
    if (y==1)
    {
        ans+=count;
        for (int i = )
    }
    ans = ans + (pos[1]) * (l - pos[y] +1);
    for (int i = 2; i<=count; i++)
    {
        cout<<"ans = "<<ans;
        ans = ans + (pos[i] - pos[i-1])*(pos[y+1] + 1 - pos[y]) ;
    }
    cout<<ans;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}