#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
// const int N = ;

using namespace std;
int ans[5001] = {};
void solve()
{
    int T;
    cin>>T;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 2;
    ans[4] = 2;
    int j = 3;
    int count = 5;
    for (int i = 5; i<5001;)
    {
        for (int k = 0; k<count; i++,k++)
            ans[i] = j;
        j++;
        count+=2;
    }
    while(T--) 
    {
        int s;
        cin>>s; 
        cout<<ans[s]<<"\n";
        
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