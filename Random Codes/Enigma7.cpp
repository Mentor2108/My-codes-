#include <bits/stdc++.h>

#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007

#define YOURMENTOR ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

using namespace std;

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

int main()
{
    YOURMENTOR
    long long N;
    cin>>N;
    ll n = 1, c = 1;
    int a[8] = {2, 3, 4, 5, 7, 10, 14, 19};
    // cin>>
    for(int i = 0; i<N;i++)
    {
        // if (N == 5)
        // {
            // cout<<a[0]<<" "<<a[1]<<endl;
        // }
        if (i > 3)
        {
            c=a[(i-4)%8];
        }
        n+=c;
        a[i%8] = n;
    }
    cout<<n<<" bulls were created";
    return 0;
}