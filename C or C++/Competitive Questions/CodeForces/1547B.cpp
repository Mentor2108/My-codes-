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
        char s[26];
        cin>>s;
        int l = strlen(s);
        int flag = 0;
        int i = 0, j = l-1;
        int k = l-1;
        char a[] = "abcdefghijklmnopqrstuvwxyz";
        
        if (l == 1)
        {
            if (s[0] == 'a')
                cout<<"Yes\n";
            else
                cout<<"No\n";
            continue;
        }
        if (l == 2)
        {
            if (strcmp (s, "ab") == 0 || strcmp(s, "ba") == 0 )
                cout<<"Yes\n";
            else
                cout<<"No\n";
            continue;
        }
        
        while(i <= j)
        {
            if (s[i] == a[k])
            {
                i++;
            }
            else if(s[j] == a[k])
            {
                j--;
            }
            else
            {
                flag = 0;
                break;
            }
            k--;
            flag = 1;
        }
    
        if (flag)
            cout<<"Yes\n";
        else
            cout<<"No\n";
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