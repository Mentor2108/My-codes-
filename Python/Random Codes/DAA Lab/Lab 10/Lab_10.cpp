#include <bits/stdc++.h>

#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007

#define YOURMENTOR ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define FOR(i, n, k) for(int i = 0; i<n; i+=k)
#define endl "\n"
#define PB push_back
#define F first
#define S second
#define VI vector<int>
#define PII pair<int, int>
#define VPII vector<pair<int, int>>

using namespace std;

void Mentor()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif
}

int find_parent(int i, VI &parent)
{
    if (parent[i] == -1)
        return i;
    return parent[i] = find_parent(parent[i], parent);
}

void unite(int x, int y, VI &parent, VI &rank)
{
    int s1 = find_parent(x, parent);
    int s2 = find_parent(y, parent);
    if (s1 != s2)
    {
        if (rank[s1] < rank[s2])
        {
            parent[s1] = s2;
            rank[s2]+=rank[s1];
        }
        else
        {
            parent[s2] = s1;
            rank[s1] += rank[s2];
        }
    }
}

void solve()
{
    vector<VI> EdgePair;
    int n, e;
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter number of Edges: ";
    cin>>e;
    FOR(i, e, 1)
    {
        int a, b, c;
        cout<<"Enter the 2 vertices and weight of edge: ";
        cin>>a>>b>>c;
        EdgePair.PB({c, a, b});
    }   
    sort(EdgePair.begin(), EdgePair.end()); //Sorts the edges based on their weights
    VI parent(n, -1), rank(n, 1);
    int ans = 0;
    cout<<"Following are the edges in the MST:\n";
    for(VI edge: EdgePair)
    {
        int a = edge[0], b = edge[1], c = edge[2];
        if (find_parent(b, parent) != find_parent(c, parent))
        {
            unite(b, c, parent, rank);
            ans+=a;
            cout<<b<<" "<<c<<" "<<a<<"\n";
        }
    }
    cout<<endl<<"Size of MST: "<<ans;
}

void TestCase()
{
    int T;
    cin>>T;
    while(T--)
        solve();
}

int main()
{
    // Mentor();
    // YOURMENTOR
    //bool prime[N];
    //FindPrime(prime, N);
    // TestCase();
    solve();
    return 0;
}