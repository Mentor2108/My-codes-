#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define li long int
#define ll long long int

int main()
{
    int n,i,t;
    scanf("%d%d",&n,&t);
    char a[n];
    scanf("%s",a);
    while(t--)
    {
        for (i=0;i<n;i++)
        {
            if (a[i] == 'B' && a[i+1] == 'G')
            {
                a[i] = 'G';
                a[i+1] = 'B';
                i++;
            }
        }
    }
    printf("%s",a);
}