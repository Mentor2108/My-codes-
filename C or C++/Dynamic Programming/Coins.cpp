#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<iostream>
#define li long int
#define ll long long int

using namespace std;
int dp[n+1]={};

int GetCoin (int n)
{
    if (n==0)
        return 0;
    if (dp[n] >0)
        return dp[n];
    long long int ans = n;
    int a[x]
}


int main()
{
    int n;
    while(cin>>n)
    {
        cout<<GetCoin(n);
        /* dp[12] = 
        for (int i = 12; i <= n; i++)
        {
            dp[i] = dp[i/2] + dp[i/3] + dp[i+4]
        }

        for (int i = 0; i<=n;i++)
            cout<<dp[i]<<" ";
        cout<<endl; */
    }
}