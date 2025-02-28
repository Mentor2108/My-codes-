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

int M, N;


int maxStudents(vector<vector<char>>& A) {
    vector<int> states;
    for (int i = 0; i < M; ++i) {
        int cur = 0;
        for (int j = 0; j < N; ++j) cur = cur * 2 + (A[i][j] == '.');
        states.push_back(cur);
    }

    vector<vector<int>> dp(M + 1, vector<int>(1 << N, -1));
    dp[0][0] = 0;
    
    for (int i = 1; i <= M; ++i) {
        int state = states[i - 1];
        for (int j = 0; j < (1 << N); ++j) {
            if ((j & state) != j || (j & (j >> 1))) continue;
            int cnt = __builtin_popcount(j);
            for (int k = 0; k < (1 << N); ++k) {
                if ((j & (k >> 1)) || (j & (k << 1)) || dp[i - 1][k] == -1) continue;
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + cnt);
            }
        }
    }

    for(int i = 0; i < states.size(); i++)
        cout<<states[i]<<" ";
    cout<<endl;
    return *max_element(begin(dp[M]), end(dp[M]));
}

void solve()
{
    cin>>M>>N;
 
    vector<vector<char>> mat(M, vector<char>(N));

    for(int i = 0; i<M; i++)
    {
        for(int j = 0; j<N; j++) {
            cin>>mat[i][j];
        }
    }
    long long ans = 0;
    
    cout<<maxStudents(mat)<<endl;

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
    Mentor();
    YOURMENTOR
    //bool prime[N];
    //FindPrime(prime, N);
    // TestCase();
    solve();
    return 0;
}