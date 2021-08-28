#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define li long int
#define ll long long int

int main()
{
    char a[100];
    scanf("%s",a);
    int i,l = strlen(a);
    for (i=0; i <l;i++)
        a[i] = tolower(a[i]);

    for (i=0; i<l-7;i++)
        if (a[i] == 's' && a[i+1] == 'a' && a[i+2] == 'n' && a[i+3] == 'i' && a[i+4] == 't' && a[i+5] == 'i' && a[i+6] == 'z' && a[i+7] == 'e')
        {
            printf("Safe");
            return 0;
        }
    printf("Not safe");
    return 0;
}