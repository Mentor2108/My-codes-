#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
const int N = 100005;
//not working for some reason
using namespace std;

void solve()
{
    int t;
    cin>>t;
    while(t--)
    {
        char a[N];
        cin>>a;
        ll l = strlen(a) - 1;
        int flag_e = 0, flag_E = 0, flag_C = 0, flag_o = 0, flag_D = 0;
        for (int i = 1;i<l;i++)
        {
            if (a[i] == 'e')
                flag_e = 1;
            if (a[i] == 'E')
                flag_E = 1;
            if (a[i] == 'C')
                flag_C = 1;
            if (a[i] == 'o')
                flag_o = 1;
            if (a[i] == 'D')
                flag_D = 1; 
            if ((flag_e == 1) && (flag_E == 1) && (flag_C == 1) && (flag_o == 1) && (flag_D == 1))
            {
                printf("SELECTED\n");
                break;
            }
        }
        if ((flag_e == 1) && (flag_E == 1) && (flag_C == 1) && (flag_o == 1) && (flag_D == 1))
            continue;
        printf("REJECTED\n");
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