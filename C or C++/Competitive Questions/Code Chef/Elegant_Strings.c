#include <stdio.h>

#define li long int
#define ll long long int

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k, a, total = 0, b, i, j, freq[26] = {0}, index = 0, flag = 0, ele = 1, e, o;
        scanf("%d%d%d%d", &n, &k, &a, &b);
        char s[n];
        scanf("%s", s);
        e = s[0];
        o = s[1];
        for (i = 0; i < n; i++)
            freq[s[i] - 97]++;

        for (i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                if (s[i] != e)
                {
                    ele = 0;
                    break;
                }
            }
            else
            {
                if (s[i] != o)
                {
                    ele = 0;
                    break;
                }
            }
        }
        if (ele)
        {
            int max = freq[0];
            for (i = 0; i < 26; i++)
            {
                if (max < freq[i])
                {
                    index = i;
                }
            }
            if (index % 2 == 0)
            {
                i = 0;
                j = 1;
            }
            else
            {
                i = 1;
                j = 0;
            }
            for (; i < n; i += 2, j += 2)
            {
                while (s[i] != (97 + index))
                {
                    if (s[i] < 97 + index)
                    {
                        s[i]++;
                        total += a;
                    }
                    else
                    {
                        s[i]--;
                        total += b;
                    }
                }
                while (s[j] != (97 + index + k + 1))
                {
                    if (s[j] < 97 + index)
                    {
                        s[j]++;
                        total += a;
                    }
                    else
                    {
                        s[j]--;
                        total += b;
                    }
                }
            }
        }
        else
        {
            index = n / 2;
            for (i = 0; i < n; i++)
            {
                if (i % 2 == 0)
                {
                    if (a>b)
                    {
                        int temp = a;
                        a=b;
                        b=temp;
                    }
                    while (s[i] != s[index])
                    {
                        if (s[i] < s[index])
                        {
                            s[i]++;
                            total += a;
                        }
                        if (s[i] > s[index])
                        {
                            s[i]--;
                            total += b;
                        }
                    }
                }
                else
                {
                    while (s[i] != s[index + k + 1])
                    {
                        if (s[i] < s[index + k + 1])
                        {
                            s[i]++;
                            total += a;
                        }
                        if (s[i] > s[index + k + 1])
                        {
                            s[i]--;
                            total += b;
                        }
                    }
                }
            }
        }
        printf("%d\n", total);
    }
    return 0;
}