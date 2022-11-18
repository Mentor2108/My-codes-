#include<bits/stdc++.h>
using namespace std;

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

//const int N = ;

void Mentor()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif
}

class Graph
{
    map<int, bool> visited;
    map<int, list<int>> adj;  
    public:
        void addEdge(int v, int w)
        {
            adj[v].push_back(w);
        }
        
        void DFS(int v)
        {
            visited[v] = true;
            cout << v << " ";
            list<int>::iterator i;
            for (i = adj[v].begin(); i != adj[v].end(); ++i)
                if (!visited[*i])
                    DFS(*i);
        }
};

ll Fastpow(ll base, ll pow) {
    if (pow == 0)
        return 1;
    ll res = Fastpow(base, pow / 2);
    if (pow % 2)
        return res * res * base;
    else
    return res * res;
}

void FindPrime(bool* prime, int N) {
    for (int i = 1; i <= N; i++) {
        prime[i] = 1;
    }
    prime[0] = 0;
    prime[1] = 0;
    int i=2;
    while(i*i <= N) {
        if(prime[i] == 0) {
            i++;
            continue;
        }
        int j = 2*i;
        while(j < N) {
            prime[j] = 0;
            j += i;
        }
        i++;
    }
}

void solve()
{
    int n;
    cout<<"Enter number of vertices in graph: ";
    cin>>n;
    Graph g;
    int e;
    cout<<"Enter number of edges in the graph: ";
    cin>>e;
    for(int i = 0; i < e; i++)
    {
        int x, y;
        cout<<"Enter the details of edge #"<<i+1<<" (<vertex1> <space> <vertex2>): ";
        cin>>x>>y;
        g.addEdge(x, y);
    }
    cout<<"DFS of the graph: ";
    g.DFS(0);
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
