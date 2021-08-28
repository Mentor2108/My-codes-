#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;

using namespace std;

vector <int> ans(1001, 1);

void solve()
{
    int k;
    cin>>k;
    cout<<ans[k]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    int x = 1;
    for (int i = 1; x<=1000; i++)
    {
        if (i%3 == 0)
            continue;
        if (i%10 == 3)
            continue;
        ans[x++] = i;
    }
    while(T--)
        solve();
    return 0;
}