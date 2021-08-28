#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define li long int
#define ll long long int

int main()
{
    int i,t,j;
    scanf("%d",&t);
    while(t--)
    {
        int n,front = 1, back = 1;
        scanf("%d",&n);
        int a[n],b[n];
        for (i=0;i<n;i++)
            scanf("%d", &a[i]);
        for (i=0;i<n;i++)
            scanf("%d", &b[i]);

        for (i=0;i<n;i++)
        {
            if (a[i] > b[i])
                front = 0;
            if (a[n-1-i] > b[i])
                back = 0;
        }
        if (front && back)
            printf("both\n");
        else if (front && !back)
            printf("front\n");
        else if (!front && back)
            printf("back\n");
        else
            printf("none\n");
    }
    return 0;
}