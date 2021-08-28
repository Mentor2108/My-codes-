#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define li long int
#define ll long long int
#define MODULO 1000000007
int main()
{
    ll n,q,sum = 0;
    scanf("%lld",&n);
    ll a[n];
    for (int i = 0; i<n;i++)
    {
        scanf("%lld",&a[i]);
        sum = ((sum%MODULO + a[i]%MODULO) + MODULO)%MODULO;
    }
    scanf("%lld",&q);
    ll x[q];
    for (int i = 0;i<q;i++)
    {
        scanf("%lld",&x[i]);
        sum = (sum%MODULO * 2)%MODULO;
        printf("%lld\n",sum);
    }   
}