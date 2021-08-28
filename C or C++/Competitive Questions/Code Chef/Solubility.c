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
        int a,b,x;
        scanf("%d%d%d",&x,&a,&b);
        ll s = a;
        s = s + (100-x)*b;
        s*=10;
        printf("%d\n",s);
    }
}