#include<stdio.h>
#define ll long long int
int boring(ll n)
{
    ll j,k,num_digit=0;
    for (j=n;j>0;j/=10)
        num_digit ++; //finds number of digits
    ll a[num_digit];
    for (j=n, k=num_digit-1 ;j>0;j/=10,k--)
    {
        a[k] = j%10;
    }
    for (j=0, k=1 ;j<num_digit;j+=2, k+=2)
        if(a[j]%2!=1 || a[k]%2!=0)
            return 0;    
    return 1;
}

int main()
{
    ll T,f=1;
    scanf("%lld",&T);
    while(T--)
    {
        ll l,r,i,count=0;
        scanf("%lld%lld",&l,&r);
        for (i=l;i<=r;i++)
        {
            count+=boring(i);
        }
        printf("Case #%lld:",f++);
        printf("%lld\n",count);
    }
    return 0;
}