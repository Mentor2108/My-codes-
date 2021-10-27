#include <stdio.h>
//BUG IN IT of some sort, r is changing value on its own
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int p, q, l, Ruby, x[1001] = {0}, y[1001] = {0}, i,j;
        scanf("%d %d %d %d", &p, &q, &l, &Ruby);
        int a[p], b[p], c[q], d[q], total = 0, temp = 0, ans = 0;
        for (i = 0; i < p; i++)
        {
            scanf("%d %d", &a[i], &b[i]);
            for (j = a[i]; j <= b[i]; j++)
                x[j] = 1;
        }

        for (i = 0; i < q; i++)
        {
            scanf("%d%d", &c[i], &d[i]);
            for (j = c[i]; j <= d[i]; j++)
                y[j] = 1;
        }
        // int temp2 = Ruby;
        // printf("r in the starting is : %d\n",Ruby);
        for (int k = 0; k <= Ruby; k++)
        {
            // printf("r in starting of loop is : %d\n",Ruby);
            if (k != 0)
                for (i = 1001; i > 0; i--)
                    y[i] = y[i - 1];
            for (j = 1; j < 1001; j++)
            {
                if (x[j] == y[j])
                {
                    temp++;
                }
            }
            if (temp > total)
            {
                total = temp; 
                ans = k;
            }
            temp = 0;
            // printf("r = %d\n", Ruby);
        }
        printf("%d ", ans);
    }
}