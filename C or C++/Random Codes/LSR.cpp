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
#define VVI vector<vector<int>>
#define PII pair<int, int>
#define VPII vector<pair<int, int>>

//const int N = ;

using namespace std;

void Mentor()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif
}

ll Fastpow(ll base, ll pow) {
    if (pow == 0)
        return 1;
    ll res = Fastpow(base, pow / 2);
    if (pow % 2)
        return res * res * base;
    else
    return res * res;
}

void solve()
{
    int n;
    cin>>n;
    VVI gra(n, VI(n));
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            cin>>gra[i][j];

    VVI temp(n,VI(n));
    vector<bool> visited(n,false);

    temp[0] = gra[0];
    visited[0] = true;

    for(int i = 0;i<n-1;i++)
    {
        int min = INT_MAX,minNode;
        for(int j = 0;j<n;j++){

            if(visited[j] == false && temp[i][j] != -1 && temp[i][j]<min){

                min = temp[i][j];
                minNode = j;
            }

        }

        visited[minNode] = true;
        for(int j = 0;j<n;j++){
            
            if(visited[j] == true){
                temp[i+1][j] = temp[i][j];
                continue;
            }
            if(gra[minNode][j] == -1){
                temp[i+1][j] = temp[i][j];
            }
            else if(temp[i][j] == -1){
                temp[i+1][j] = temp[i][minNode]+gra[minNode][j];
            }
            else{
                temp[i+1][j] = min(temp[i][j], temp[i][minNode] + gra[minNode][j]);
            }
        }
    }
    for(int i = 0;i<n;i++)
        cout<<"Distance between 0 and "<<i<<": "<<temp[n-1][i]<<endl;
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
