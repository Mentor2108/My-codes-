#include <bits/stdc++.h>
using namespace std;
//NOT MINE IDK how to solve it
#define ll long long int
#define min(a, b) (a > b ? b : a)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int max = 4e6 + 5;

    int arr[max], answer[max];

    for (int i = 0; i < max; i++)
    {
        arr[i] = i;
        answer[i] = 0;
    }
    for (int j = 2; j < max; j++)
    {
        if (arr[j] == j)
        {
            arr[j] = j - 1;
            for (int i = 2 * j; i < max; i += j)
            {
                arr[i] = (arr[i] / j) * (j - 1);
                if (i<=100)
                    cout<<"for j = "<<j<<": arr["<<i<<"] = "<<arr[i]<<"\n";
            }
        }
    }
    for (int i = 1; i < max; i++)
    {
        answer[i] += i - 1;
        for (int j = 2 * i; j < max; j += i)
        {
            answer[j] += i * ((1 + arr[j / i]) / 2);
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        cout << answer[4 * k + 1] << '\n';
    }
}
