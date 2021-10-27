#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;

void mentor()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

using namespace std;

void solve()
{
    char a[100];
    int k;
    cin>>a>>k;
    vector <char> p[26];
    vector <char> ans;
    set <char> s;
    set <char> s1;
    vector <char> IS; 

    void dfs ()

    for (int i = 0; i < 26; i ++)
    {
        // p[i].push_back('A'+i);
        s.insert('A' + i);
    }
    for (int i = 0; i < k; i ++)
    {
        char x,y;
        cin>>x>>y;
        p[x-65].push_back(y);
    }   
    int l = strlen(a);
    for (int i = 0; i < l; i ++)
    {
        for (int j = 0; j<p[a[i] - 65].size(); j++)
        {
            dfs()
            s1.insert(p[a[i] - 65][j]);
        }
        set_intersection(s1.begin(),s1.end(),s.begin(),s.end(), back_inserter(IS));
        cout<<"IS = ";
        for (int i = 0; i<IS.size(); i++)
            cout<<IS[i]<<" ";
        cout<<"\n";
        s1.clear();
        s.clear();
        for (int i = 0; i<IS.size(); i++)
            s.insert(IS[i]);
        IS.clear();
        for (auto it = s.begin(); it != s.end(); ++it)
            cout<<*it<<" ";
        cout<<"\n";
    }
 

}


int main()
{
    mentor();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    for (int i = 0; i < T; i ++)
    {
        cout<<"Case #"<<i+1<<": ";
        solve();
        cout<<"\n";
    }
    return 0;
}