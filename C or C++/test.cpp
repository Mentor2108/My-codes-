#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;

using namespace std;

bool sieve(int N) {
    // We cross out all composites from 2 to sqrt(N)
    int i=2;
    // This will loop from 2 to int(sqrt(x))
    while(i*i <= N) {
        // If we already crossed out this number, then continue
        if(is_prime[i] == 0) {
            i++;
            continue;
        }
        int j = 2*i;
        while(j < N) {
            // Cross out this as it is composite
            is_prime[j] = 0;
            // j is incremented by i, because we want to cover all multiples of i
            j += i;
        }
        i++;
    }
}

void solve()
{
    int n;
    cin>>n;
    int a[n+1] = {};
    int prime[n+1];
    for (int i = 1; i <= n; i++)
    {
        prime[i] = 1;
        cin>>a[i];
    }
    prime[0] = 0;
    prime[1] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int T;
    // cin>>T;
    // while(T--)
        solve();
    return 0;
}