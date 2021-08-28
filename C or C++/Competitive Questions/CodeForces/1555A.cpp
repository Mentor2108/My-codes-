#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;

using namespace std;

void solve()
{
    ll n;
    cin>>n;
    ll ans = 0;
    ll check = n;
    if (n<6)
    {
        cout<<"15\n";
        return;
    }
    check /= 6;
    ans += check;
    ans*=15;
    if (n%6 == 1 || n%6 == 2)
        ans+=5;
    else if (n%6 == 3 || n%6 == 4)
        ans+=10;
    else if (n%6 == 5)
        ans += 15;
    cout<<ans<<"\n";    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}