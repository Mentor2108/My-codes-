#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define li long int
#define ll long long int

int check(char a)
{
    switch(a)
    {
        case 'E':
        case 'Q':
        case 'U':
        case 'I':
        case 'N':
        case 'O':
        case 'X': return 1;  
        default:return 0;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll n,A,B,x=0,y=0;
        scanf("%lld%lld%lld",&n,&A,&B);
        char a[100];
        while(n--)
        {
            scanf("%s",a);
            if (check(a[0]))
            {
                x+=A;
            }
            else
            {
                y+=B;
            }
        }
        if (x>y)
        {
            printf("SARTHAK");
        }
        else if(y>x)
        {
            printf("ANURADHA");
        }
        else
        {
            printf("DRAW");
        }
        printf("\n");
    }
}