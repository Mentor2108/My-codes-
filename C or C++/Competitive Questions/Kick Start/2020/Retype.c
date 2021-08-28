#include<stdio.h>
#define ll long long int
int main()
{
    ll N,f=1;
    scanf("%d",&N);
    while (N--)
    {
        ll s,k,n;
        scanf("%lld%lld%lld",&s,&k,&n);
        ll time1 = k-1, time2=k;  // 
        ll i,j;
        for(i=k-1;i>=n;i--)
            time1++;
        for (;i!=s;i++)
            time1++;
        for (i=1;i<=s;i++)
            time2++;
        printf("Case #%lld: ",f++);
        if (time1>time2)
            printf("%lld\n",time2);
        else    
            printf("%lld\n",time1);
    }
}