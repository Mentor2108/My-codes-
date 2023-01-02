#include <bits/stdc++.h>

#define ll long long int
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)
#define mod 1000000007

#define YOURMENTOR ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define FOR(i, n, k) for(int i = 0; i<n; i+=k)
#define endl "\n"
#define PB push_back
#define F first
#define S second
#define VI vector<int>
#define PII pair<int, int>
#define VPII vector<pair<int, int>>

//const int N = ;

using namespace std;

void Mentor()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int* a, int low, int high)
{
    int pivot = a[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return (i + 1);
}

void quickSort(int *a, int low, int high)
{
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

void solve()
{
    int n, sum;
    cin>>sum>>n;
    int a[n];
    FOR(i, n, 1)
    {
        cin>>a[i];
    }
    quickSort(a, 0, n-1);
    if (a[n-1] + a[n-2] > sum)
    {
        cout<<"The elements a and b are: "<<a[n-2]<<" "<<a[n-1];
        return;
    }
    else
    {
        cout<<"There is no pair a and b whose sum is more than 'sum'";
        return;
    }
}

void TestCase()
{
    int T;
    cin>>T;
    while(T--)
        solve();
}

int main()
{
    // Mentor();
    // YOURMENTOR
    //bool prime[N];
    //FindPrime(prime, N);
    // TestCase();
    solve();
    return 0;
}