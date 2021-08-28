#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define li long int
#define ll long long int

int check(char a[], ll l)
{
    ll sum = 0;
    double avg = 0;
    for (int i = 0;i<l;i++)
    {
        sum+=(a[i]-48);
        avg = (float)sum/(i+1);
        if (avg >= 0.5)
            return 1;
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll l;
        scanf("%d",&l);
        char a[l];
        scanf("%s",a);
        if (check(a,l))
        {
            printf("yes");
        }
        else 
        {
            printf("no");
        }
        printf("\n");
    }
}