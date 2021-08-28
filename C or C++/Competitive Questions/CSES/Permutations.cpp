#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<iostream>

#define li long int
#define ll long long int

using namespace std;

int main()
{
    int n,i,j;
    scanf("%d",&n);
    if (n<4 && n>1)
    {
        printf("NO SOLUTION");
        return 0;
    }
    for (i=2;i<=n;i+=2)
        printf("%d ",i);
    for (i=1;i<=n;i+=2)
        printf("%d ",i);
    return 0;
}