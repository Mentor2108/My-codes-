#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define li long int
#define ll long long int

int main()
{
    long long int n,i;
    scanf("%lld",&n);
    int count=0;
    for (i=n;i>0;i/=10)
        if ((i%10)==4 || (i%10)==7)
            count++;
    if (count==4 || count == 7)
        printf("YES");
    else
        printf("NO");
}