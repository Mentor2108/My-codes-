#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define li long int
#define ll long long int

int main()
{
    char a[1000];
    scanf("%s",a);
    a[0] = toupper(a[0]);
    printf("%s",a);
}