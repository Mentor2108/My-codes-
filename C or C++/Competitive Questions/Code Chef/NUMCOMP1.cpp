// #include <bits/stdc++.h>
// #define ll long long int
// #define max(a, b) (a > b ? a : b)
// #define min(a, b) (a > b ? b : a)
// #define mod 1000000007
// const int N = 10000001;
// using namespace std;

// ll a[N] = {};
// ll c = 5;

// void checkprime(int n)
// {
//     for (int i = 3; i <= sqrt(n); i += 2)
//     {
//         if (n % i == 0)
//             return;
//     }
//     a[c++] = n;
// }

// void findprime(ll star, ll n)
// {
//     for (int i = star+2; c <= 1000; i += 2)
//     {
//         checkprime(i);
//     }
// }

// void solve()
// {
//     ll t;
//     cin >> t;
//     a[1] = 2;
//     a[2] = 3;
//     a[3] = 5;
//     a[4] = 7;
//     findprime(a[c-1],1000);
//     while (t--)
//     {
//         ll n;
//         cin >> n;
//         ll ans = 1;
//         if (n == 2)
//         {
//             cout<<"1\n";
//             continue;
//         }
//         while(1)
//         {
//             if (a[c-1] <n )
//             {
//                 findprime(a[c-1], c+100);
//             }
//             else
//                 break;
//         }
//         for (int i = 2; a[i]<=n;i++)
//         {
//             if (a[i]*2 > n)
//                 ans++;  
//         }
//         cout<<ans<<"\n";
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     solve();
//     return 0;
// }


#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
const int N = 10000001;
using namespace std;

int checkprime(ll n)
{
    for (ll i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void solve()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll ans = 1;
        if (n == 2)
        {
            cout<<"1\n";
            continue;
        }
        if (n == 3)
        {
            cout<<"2\n";
            continue;
        }
        if (n == 4)
        {
            cout<<"2\n";
            continue;
        }
        if (n == 5)
        {
            cout<<"3\n";
            continue;
        }
        if (n == 6)
        {
            cout<<"2\n";
            continue;
        }
        if (n == 7)
        {
            cout<<"3\n";
            continue;
        }
        if (n == 8)
        {
            cout<<"3\n";
            continue;
        }
        if (n == 9)
        {
            cout<<"3\n";
            continue;
        }
        if (n == 10)
        {
            cout<<"2\n";
            continue;
        }
        if (n == 11)
        {
            cout<<"3\n";
            continue;
        }
        if (n == 12)
        {
            cout<<"3\n";
            continue;
        }
        if (n == 13)
        {
            cout<<"4\n";
            continue;
        }
        if (n == 14)
        {
            cout<<"3\n";
            continue;
        }
        if (n == 15)
        {
            cout<<"3\n";
            continue;
        }
        if (n == 16)
        {
            cout<<"3\n";
            continue;
        }
        if (n == 17)
        {
            cout<<"4\n";
            continue;
        }
        if (n == 18)
        {
            cout<<"4\n";
            continue;
        }
        if (n == 19)
        {
            cout<<"5\n";
            continue;
        }
        if (n == 20)
        {
            cout<<"5\n";
            continue;
        }
        int st = 0;
        if (((n/2)%2) == 0)
            st = n/2 + 1;
        else
            st = n/2 + 2;
        for (int i = st; i<=n; i+=2)
        {
            if (checkprime(i) == 1)
            {
                ans++;  
            }
        }
        cout<<ans<<"\n";
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