#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
const int N = 1000;

using namespace std;
//didn't work, i thought it might

vector<vector<ll>> node;
vector<ll> countt;
ll countting[N] = {};

ll dfs(ll Node, ll par)
{   
    countt[Node]++;
    for (ll to : node[Node])
    {
        if (to != par)
        {
            ll p = dfs(to, Node);
            countt[Node] += p;
        }
    }  
    return countt[Node]; 
}

int mini(int n, int V)
{
    int table[V + 1];
    table[0] = 0;
    for (int i = 1; i <= V; i++)
        table[i] = INT_MAX;
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j < n; j++)
            if (countt[j] <= i)
            {   
                int sub_res = table[i - countt[j]];
                if (sub_res != INT_MAX && sub_res + 1 < table[i])
                {
                    table[i] = sub_res + 1;
                    if (i == V)
                        countting[j]++;
                }
            }
    }

    if (table[V] == INT_MAX)
        return -1;

    return table[V];
}

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        node.clear();
        node.resize(n + 1);
        countt.clear();
        countt.resize(n + 1);
        countting[0] = 0;
        countting[1] = 0;
        for (int i = 2; i < n + 1; i++)
        {
            countting[i] = 0;
            int a;
            cin >> a;
            node[a].push_back(i);
            node[i].push_back(a);
        }

       /*  countt[1] = node[1].size() + 1;
        for (int i = 2; i < n + 1; i++)
        {
            countt[i] = node[i].size();
        } */
        dfs(1,-1);
/*         for (int i = 1; i <= n; i++)
            cout<< "count = "<<countt[i]<<" ";
        cout<<"\n"; */
        ll x = 0, ans = mini(n + 1, k);
        for (int i = 1; i < n + 1; i++)
            x = max(x, countting[i]);
        // cout<<"x="<<x<<endl;
        ans += x;

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