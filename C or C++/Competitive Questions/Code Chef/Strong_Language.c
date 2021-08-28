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
        int n,k,count =0,flag =0;
        scanf("%d%d",&n,&k);
        char a[n];
        scanf("%s",a);
        for (int i=0;i<n;i++)
        {   
            if (a[i] == '*')
            {
                count++;
                if (count==k)
                {
                    printf("YES\n");
                    flag = 1;
                    break;
                }
            }
            else
            {
                count = 0;
            }
        }
        if (!flag)
        {
            printf("NO\n");
        }
    }
}