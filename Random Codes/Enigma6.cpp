#include <iostream>
#include <vector>
#define ll long long
using namespace std;
 
ll fibonacci(vector <ll> &dp, int n)
{
        if(n == 0)
                return 0;
        if (n == 1 || n == 2 || n==3 || n == 4)
                return n-1;
        dp[n] = fibonacci(dp, n - 1) + fibonacci(dp, n - 2) + fibonacci(dp, n-3);
        return dp[n];
}
 
int main()
{
        ll n;
        cin >> n;
        vector <ll> dp(n+1, 0);
        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 2;
        cout << " output: " << fibonacci(dp, n) << endl;
}