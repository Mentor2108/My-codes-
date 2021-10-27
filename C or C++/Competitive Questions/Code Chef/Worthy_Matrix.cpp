// WORKS AND VERY EFFICIENT (USING AUXILIARY MATRIX)

#include<iostream>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
typedef long long int ll;

using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t; cin>>t;
    while(t--)
    {
        ll row, clmn,k;
        cin >> row >> clmn >> k;
        ll arr[row+1][clmn+1] = {};
        ll sum_row=0;
        ll sum_clmn=0;
        ll count=0;
        for (ll i=1; i<=row; i++)
        {
            for (ll j=1; j<=clmn; j++)
            {    
                cin>>arr[i][j];
                if (arr[i][j]>=k)
                    count++;
                arr[i][j]= arr[i][j] + (arr[i-1][j]-arr[i-1][j-1])/* removing excess addition */ + arr[i][j-1];
            }
        }
       
        for(ll order = 2; order <= min(row,clmn); order++)
        {
            for(ll i = order;i <= row; i++)
            {
                for(ll j = order; j<= clmn; j++)
                {
                    if((arr[i][j]+arr[i-order][j-order]-arr[i][j-order]-arr[i-order][j])/(order*order)>=k)
                    {
                        count += clmn - j + 1;
                        break;
                    }
                }
            }
        }
        cout << count<<"\n";
    }
}

/* WORKED BUT VERY TIME CONSUMING (CODE IS IN C...NOT C++)

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define li long int
#define ll long long int

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll r,c,k,i,j,ans = 0;
        scanf("%lld%lld%lld",&r,&c,&k);
        ll a[r][c];
        double avg;
        ll loop, sum =0;
        for (i=0;i<r;i++)
        {
            for (j=0;j<c;j++)
            {
                scanf("%lld",&a[i][j]);
                if (a[i][j] >=k)
                    ans++;
            }
        }

        if (c < r)
            loop = c;
        else
            loop = r;

        for (int x=2;x<=loop;x++)
        {
            for (int pr = 0;pr<=r-x;pr++)
            {
                for (int pc = 0;pc<=c-x;pc++)
                {
                    sum=0;
                    for (i = pr;i<x+pr;i++)
                    {
                        for (j=pc;j<x+pc;j++)
                        {
                            sum+=a[i][j];     
                        }
                    }
                    avg = sum/(x*x);
                    if (avg >=k)
                        ans++;
                }  
            }
        }
        printf("%lld\n",ans);
    }
} */