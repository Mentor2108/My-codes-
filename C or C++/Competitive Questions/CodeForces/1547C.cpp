#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
// const int N = ;

using namespace std;

void solve()
{
    int T;
    cin>>T;
    while(T--)
    {
        int k,n,m;
        cin>>k>>n>>m;
        vector<int> a;
        vector<int> b;
        int ans[n+m], flag = 1;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;
            a.push_back(x);
        }
        a.push_back(1000);
        for (int i = 0; i < m; i ++)
        {
            int x;
            cin>>x;
            b.push_back(x);
        }
        b.push_back(1000);
        int i = 0, j = 0;
        while(1)
        {
            if (a[i] > k && b[j] > k)
            {
                // cout<<"i = "<<i<<", j = "<<j<<", i came here.";
                flag = 0; 
                break;
            }
            if (a[i] == 0)
            {
                ans[i+j] = 0;
                i++;
                k++;
            }
            else if (b[j] == 0)
            {
                ans[i+j] = 0;
                j++;
                k++;
            }
            else if (a[i] < b[j])
            {
                if (a[i] <= k)
                {
                    ans[i+j] = a[i];
                    i++;
                }
                else
                {
                    // cout<<"i = "<<i<<", j = "<<j<<", ii came here.";
                    flag = 0;
                    break;
                }
            }
            else 
            {
                if (b[j] <= k)
                {
                    ans[i+j] = b[j];
                    j++;
                }
                else
                {
                    // cout<<"i = "<<i<<", j = "<<j<<", iii came here.";
                    flag = 0;
                    break;
                }
            }
            flag = 1;
            if (i == n && j == m)
                break;
        }
        if (flag)
        {
            for (i = 0; i < n+m; i++)
                cout<<ans[i]<<" ";
        }
        else
            cout<<"-1";
        cout<<"\n";

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