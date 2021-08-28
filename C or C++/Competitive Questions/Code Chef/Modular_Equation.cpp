#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)

using namespace std;
//WRONGGG
int findFactor(long int *factor, ll n, ll m)
{
    long int less;
    int j = 0;

    if (n< (m/2))dw 
        less = n;
    else
        less = m/2;

    if (m%2==0)
    {  
        factor[0] = 2;
        j++;
        for (long int i = 3; i<=less; i++)
        {
            if (m%i == 0)
            {
                factor[j] = i;
                j++;
            }
        }
    }
    else
    {
        for(long int i = 3;i<=less;i+=2)
        {
            if (m%i==0)
            {
                factor[j] = i;
                j++;
            }
        }
    }
    return j;
}


void solve()
{
    int t;
    cin>>t;
    long int factor[100000] = {0};  
    while(t--)
    {
        ll n,m,ans = 0, count = 0;
        cin>>n>>m;
        if (m==1) //if m is 1, correct
        { 
            ans = (n*(n-1))/2;
        }
        else  
        {
            ans += (n-1); //if a is 1
            count = findFactor(factor,n,m);
            

            ans = ans + (count*(count-1))/2;
            if (n>=m)
            {
                ans = ans + ((n-m)*(n-m+1))/2;
            } 
        }
        cout<<ans<<"\n";
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();

    return 0;
}
