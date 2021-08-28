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
        float x,k1,k2,k3,v;
        scanf("%f%f%f%f",&k1,&k2,&k3,&v);
        x = k1*k2*k3*v;
        x = 100/x;
        x = roundf(x*100)/100;
        if (x<=9.57)
            printf("Yes\n");
        else
            printf("No\n");
    }
}