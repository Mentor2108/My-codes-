#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007
//const int N = ;
//didn't work
using namespace std;

void solve()
{
    ll n,k;
    cin>>n>>k;
    string x = to_string(n);
    int l = x.length();
    int val1 = -1, val2 = -1, val3 = -1;
    int mini = 1000;
    int flag = 0;
    int pval1 = 1000, pval2 = 1000;
    int count[10] = {};
    for (int i = 0; i < l; i++)
    {
        count[x[i]-48]++;
    }
    if (k == 2)
    {
        val1 = x[0] - 48;
        pval1 = 0;
        for (int i = 1; i < l; i++)
        {
            if (val2 != -1 && x[i-1] != x[i])
            {
                val3 = x[i] - 48;
                break;
            }
            if (x[i-1] != x[i] && val3 == -1)
            {
                val2 = x[i] - 48;
                pval2 = i;
            }
        } 
        // cout<<val1<<" "<<val2<<val3<<"\n";
        cout<<"count = ";
        for (int j = 0; j < 10; j++)
        {
            cout<<count[j] <<" ";
        }
        cout<<"\n";
        if (val3 == -1)
        { 
            cout<<n<<"\n";
        }
        else
        {
            mini = min (val1, val2);
            int maxi = max(val1, val2);
            for (int i = l-1; i>=0;i--)
            {
                if (!flag)
                {
                    if (x[i] - 48 == mini)
                    {
                        continue;
                    }
                    else if (x[i] - 48 > mini)
                    {
                        if (x[i] - 48 > maxi)
                        {
                            count[x[i] - 48]--;
                            count[mini]++;
                            x[i] = mini + 48; 
                            flag = 1;
                            cout<<"1count = ";
                            for (int j = 0; j < 10; j++)
                            {
                                cout<<count[j] <<" ";
                            }
                            cout<<"\n";
                        }
                        else
                        {
                            count[x[i] - 48]--;
                            count[maxi] ++;
                            x[i] = maxi + 48;
                            cout<<"2count = ";
                            for (int j = 0; j < 10; j++)
                            {
                                cout<<count[j] <<" ";
                            }
                            cout<<"\n";
                        }
                    }
                    else
                    {
                        
                        count[x[i] - 48]--;
                        count[mini]++;
                        x[i] = mini + 48;
                        flag = 1;
                        cout<<"3count = ";
                        for (int j = 0; j < 10; j++)
                        {
                            cout<<count[j] <<" ";
                        }
                        cout<<"\n";
                    }

                    if (count[val1] + count[val2] == l && flag == 0)
                    {
                        cout<<x<<"\n";
                        return;
                    }
                }
                else
                {
                    if (x[i] - 48 < mini)
                    {
                        count[x[i] - 48]--;
                        count[mini]++;
                        x[i] = mini + 48;
                        flag = 0;
                    }
                    else if (x[i] - 48 < maxi)
                    {
                        count[x[i] - 48]--;
                        count[maxi] ++;
                        x[i] = maxi + 48;
                        flag = 0;
                    }
                    else
                    {
                        count[x[i] - 48]--;
                        count[mini]++;
                        x[i] = mini + 48;
                        flag = 1;
                    }
                }
            }
            cout<<x<<"\n";
            return;
        }
    }

            
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--)
        solve();
    return 0;
}