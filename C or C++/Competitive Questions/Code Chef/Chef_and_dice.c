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
        li n; //n is input
        scanf("%li",&n);
        if (n==0)
        {
            printf("0\n");
            continue;
        }
        if (n==1)
        {
            printf("20\n");
            continue;
        }
        if (n==2)
        {
            printf("36\n");
            continue;
        }
        if (n==3)
        {
            printf("51\n");
            continue;
        }
        if (n==4)
        {
            printf("60\n");
            continue;
        }
        ll ans = 0;
        if (n%4==0)
            ans = n*11 + 16; //n*11 = n*5 + n*6...16 = 4*4
        if (n%4==1)
            ans = (n-(n%4))*11 + 20 + 12; //12 = 4*3... 20 = 2+3+4+5+6
        if (n%4==2) 
            ans = (n-(n%4))*11 + 36 + 8; //36 = 2*(3+4+5+6)
        if (n%4==3)
            ans = (n-(n%4))*11 + 51 + 4; // 51 = 15 + 36...where 15 = 4+5+6...36 = 2*(3+4+5+6)
        printf("%lld\n",ans);
    }
}