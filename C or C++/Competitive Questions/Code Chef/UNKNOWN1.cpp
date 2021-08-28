#include <bits/stdc++.h>
#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)

using namespace std;

void solve()
{
    float a,b;
    scanf("%f %f",&a,&b);
    printf("%.1f\n%.1f\n%.1f\n%.1f",a+b,a-b,a*b,a/b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}