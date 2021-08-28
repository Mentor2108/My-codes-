#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
// const int N = ;
//didn't work

using namespace std;

void solve()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        int total[n*n] = {}, k = 0;
        int count[110] = {};
        for (int i = 0;i<n;i++)
            cin>>a[i];
        int m = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j<n; j++, k++)
            {
                total[k] = a[i] + a[j];
                cout<<"i = "<<i<<" j = "<<j<<" total[k] = "<<total[k]<<"\n";
                count[total[k]]++;
            }
        }
        
        for (int i = 0; i < 110; i++)
        {
            cout<<count[i]<<" ";
            m = max(m, count[i]);
        }
        cout<<endl;        
        cout<<m<<"\n";
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