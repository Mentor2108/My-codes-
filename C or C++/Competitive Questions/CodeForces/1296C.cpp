#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;

using namespace std;

void solve()
{
    int n, x = 0, y = 0;
    cin>>n;
    char a[n];
    cin>>a;
    int ans = INT_MAX;
    map<pair<int, int>, int> mp;
    mp[{0,0}] = 0;
    pair<int, int> pr(-1, -1);

    for (int i = 0; i < n; i++)
    {
        if(a[i] == 'R')
        {
            x++;
        }
        else if (a[i] == 'L')
        {
            x--;
        }
        else if (a[i] == 'U')
        {
            y++;
        }
        else
        {
            y--;
        }

        if (mp.find({x,y}) != mp.end())
        {
            if (ans > i - mp[{x, y}])
            {
                pr.first = mp[{x,y}] + 1;
                pr.second = i+1;
                ans = i - mp[{x,y}];
            }
        }
        mp[{x,y}] = i + 1;
    }

    if (pr.first == -1)
    {
        cout<<"-1\n";
        return;
    }
    cout<<pr.first<<" "<<pr.second<<"\n";
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