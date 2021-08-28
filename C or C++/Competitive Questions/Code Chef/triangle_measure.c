#include<stdio.h>
#include<math.h>
#define M_PI 3.14159265358979323846264338327950288
int main()
{
    char a;
    double x;
    int n;
    scanf("%c",&a);
    scanf("%lf",&x);
    if (a=='c')
    {
        n = cos(x*M_PI);
    }
    else
        n= sin(x*M_PI);
    printf("%d",n); 
}