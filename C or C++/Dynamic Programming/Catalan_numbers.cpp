#include<iostream>

#define ull unsigned long long

using namespace std;

void solve(int n)
{
    ull catalan[n+1] = {};
    catalan[0] = catalan[1] = 1;
    for (int i = 2;i<=n;i++)
    {
        for (int j=0; j < i; j++)
        {
            catalan[i] += (catalan[j] * catalan[i-j-1]);
        }
    }

    for (int i=0;i<=n;i++)
    {
        cout<<catalan[i]<<" ";
    }
}

int main()
{
    int n;
    cin >> n;
    solve(n);
}