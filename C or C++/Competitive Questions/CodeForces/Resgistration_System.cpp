#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;

using namespace std;
//vector<char*> x;
void solve()
{
    ll t;
    cin>>t;
    char a[t][32];
    int count[t] = {};
    for (int i = 0;i<t;i++)
    {
        scanf("%s[^\n]%*c", &a[i]);
        for (int j = 0; j<i;i++)
        {
            if (strcmp(a[i],a[j]) == 0)
                count[i]++;
        }
    }
    for (int i = 0;i<t; i++)
    {
        if (count[i] != 0)
        {
            printf("OK\n");
        }
        else
        {
            printf("%s%d\n",a[i],count[i]);
        }
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