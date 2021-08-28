#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define li long int
#define ll long long int

int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if ((a==b) || (b==c) || (c==a))
    {
        printf("Yes");
        return 0;
    }
    printf("No");
    return 0;
}
