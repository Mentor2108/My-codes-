#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
// const int N = ;

using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int> a;
    for (int i = 0; i <n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    cout<<*max_element(a.begin(), a.end());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}