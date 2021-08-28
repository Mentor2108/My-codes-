#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)

using namespace std;

int check(int a[], int w, int n)
{
    for (int i = 0;i<n;i++)
    {
        if (a[i]==a[i+1])
        {
            w-=(a[i]*2);
            a[i] = 0;
            a[i+1] = 0;
            i++;
        }
        if (w<=0)
        {
            return 1;
        }
    }
    return 0;
}

void solve()
{   
    int t;
    cin>>t;
    while(t--)
    {
        int n,w,w_;
        cin>>n>>w>>w_;
        int a[n];
        for (int i = 0;i <n;i++)
        {
            cin>>a[i];
        }
        
        w-=w_;
        if (w<=0)
        {
            printf("YES\n");
            continue;
        }
        sort(a,a+n);
        if (check(a,w,n))
        {
            printf("YES\n");
        }
        else 
        {
            printf("NO\n");
        }
    }
}

int main()
{
    solve();

    return 0;
}