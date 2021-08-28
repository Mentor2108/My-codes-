#include<stdio.h>
#include<math.h>
int dec(int n)
{
    int dec = 0, i = 0, rem;
    while (n != 0) {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }
    return dec;
}
int main()
{
    long n;
    scanf("%ld",&n);
    int bin[27],bini=0,new = 0;
    for(int i=0;n>0;i++)
    {
        bin[i] = n%2;
        n=n/2;
        bini++;
    }
    for(int i=0;i<bini;i++)
    {
        if(bin[i] == 1)
            new = (new * 10)+bin[i];
    }
    printf("%d",dec(new));
}