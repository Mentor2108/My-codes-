#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char a[100];
    scanf("%s",&a);
    int i,count_l=0,count_u=0,n=strlen(a);
    for (i=0;i<n;i++)
    {
        if (islower(a[i]))
            count_l++;
        else
            count_u++;
    }
    if (count_l>=count_u)
        for (i=0;i<n;i++)
            a[i]=tolower(a[i]);
    else
        for (i=0;i<n;i++)
            a[i] = toupper(a[i]);
    printf("%s",a);
}