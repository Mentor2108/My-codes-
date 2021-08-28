#include<stdio.h>

int main()
{
    int d,x; 
    scanf("%d%d",&d,&x);
    while(d--)
    {
        int y,i,j,total = 0;
        scanf("%d",&y);
        while (y--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if (a>=21600)
                total = total + (b-a)*x;
            else if (b>=21600)
                total = total + (b-21600)*x;
        }
        printf("%d\n",total);
    }
}