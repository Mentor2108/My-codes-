#include<stdio.h>
// DIDNT WORK
int main()
{
    int i,j,n,q;
    scanf("%d%d",&n,&q);
    int a[n];
    for (i=0;i<n;i++)
        scanf("%d",&a[i]);
    while(q--)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if (x==1)
        {
            a[y-1] = z;
            continue;
        }
        int max = 0;
        for (i=y-1;i<z;i++)
            for (j = i+1;j<z;j++)
                for (int k =j+1;k<z;k++)
                    if ((a[i] + a[j] >= a[k]) && (a[i] + a[k] >= a[j]) && (a[j] + a[k] >= a[i]))
                    {
                        int p = a[i] + a[j] + a[k];
                        if (max<p)
                            max = p;
                    }
        printf("%d\n",max);
    }
}