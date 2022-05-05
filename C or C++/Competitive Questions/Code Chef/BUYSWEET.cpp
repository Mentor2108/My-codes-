    #include <bits/stdc++.h>

    #define ll long long int
    #define max(a, b) (a > b ? a : b)
    #define min(a, b) (a > b ? b : a)
    #define mod 1000000007

    #define YOURMENTOR ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    #define FOR(i, n, k) for(int i = 0; i<n; i+=k)
    #define endl "\n"
    #define PB push_back

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

    void FindPrime(int* prime, int N) {
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
        //int prime[N];
        //FindPrime(prime, N);
        int n, r;
        cin>>n>>r;
        vector<int> a(n), b(n);
        vector<pair<int, int>> x(n);
        FOR(i, n, 1)
        {
            cin>>a[i];
        }
        FOR(i, n , 1)
        {
            cin>>b[i];
            x[i] = {a[i] - b[i], i};
            // cout<<x[i].first<<" "<<x[i].second<<endl;
        }
        sort(x.begin(), x.end());
        ll ans = 0;
        FOR(i, n, 1)
        {
            cout<<x[i].first<<" "<<x[i].second<<endl;
        }
        for(int i = 0; i < n; i++)
        {
            if (r>=a[x[i].second])
            {
                int temp =  (r - a[x[i].second])/x[i].first + 1;
                ans+=temp;
                r-=(temp*x[i].first);
                // cout<<"ans = "<<ans<<", r = "<<r<<", x[i] = "<<x[i].first<<endl;
            }
            else
            {
                continue;
            }
        }
        cout<<ans<<endl;
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
        TestCase();
        //solve();
        return 0;
    }

