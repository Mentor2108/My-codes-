const long long MOD = 1000000007;

vector <vector <long long>> adj;
vector <long long> colour;
vector <long long> blank;
unsigned long long total = 0;




long long graph_colouring(long long node , long long numberOfChildren)
{
    if(numberOfChildren == 0)
        return 1 ;

    vector <long long> ar;

    for(auto u : adj[node])
    {
        if(colour[u] == 0)
        {
            colour[u] = 1;
            ar.push_back(graph_colouring(u , adj[u].size()));
        }
    }

    
    long long res = 0;
    sort(ar.begin() , ar.end());
    for(long long i = 0 ; i < ar.size() ; i++)
    {
        res = res + ar[i]*(ar.size() - i);
    }
    res = res + 1;
    
    return res;
}





void answer(long long N , long long X)
{
    for(long long i = 1 ; i < N ; i++)
    {
        long long u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }


    colour[1] = 1;
    cout << ((X%MOD) * ( graph_colouring(1  , adj[1].size()) % MOD )  % MOD )<< endl;
}




int main()
{
    long long T;
    cin >> T;
    while(T--)
    {
        
        long long N , X;
        cin >> N >> X;
        adj.assign(N+1 , blank);
        colour.assign(N+1 , 0);
        answer(N , X);

        adj.clear();
        colour.clear();
        total = 0;
        cerr << "Time taken : " << float(clock()) / CLOCKS_PER_SEC << " second " << endl;

    }
    return 0;
}
