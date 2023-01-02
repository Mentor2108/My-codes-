#include<bits/stdc++.h>
using namespace std;

#define maxi(a, b) (a > b ? a : b)
#define mini(a, b) (a > b ? b : a)

struct Pair
{
    int min;
    int min_pos;
    int max;
    int max_pos;
};

Pair getMinMax(vector<int> a, int n)
{
    Pair minmax;    
    int i = 0;
    if (n % 2 == 0) //Even number of elements remain
    {
        if (a[0] > a[1])    
        {
            minmax.max = a[0];
            minmax.max_pos = 0;
            minmax.min = a[1];
            minmax.min_pos = 1;
        }
        else
        {
            minmax.min = a[0];
            minmax.min_pos = 0;
            minmax.max = a[1];
            minmax.max_pos = 1;
        }
        i = 2;
    }
    else //Even Number of elements remain
    {
        minmax.min_pos = 0;
        minmax.min = a[0];
        minmax.max = a[0];
        minmax.max_pos = 0;
        i = 1;
    }
     
    while (i < n - 1) //Two elements are being checked at a time
    {        
        if (a[i] > a[i + 1])        
        {
            if(a[i] > minmax.max)
            {    
                minmax.max = a[i];
                minmax.max_pos = i;
            }     
            if(a[i + 1] < minmax.min)        
            {
                minmax.min = a[i + 1];    
                minmax.min_pos = i+1;
            }
        }
        else       
        {
            if (a[i + 1] > minmax.max)    
            {
                minmax.max = a[i + 1];
                minmax.max_pos = i+1;
            }

            if (a[i] < minmax.min)        
            {
                minmax.min = a[i];    
                minmax.min_pos = i;
            }
        }
        
        i += 2;
    }        
    return minmax;
}

int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> a(n);
    int ansmin, ansmax;
    cout<<"Enter array elements: ";
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }     
    int k, m;
    cout<<"Enter k and m: ";
    cin>>k>>m;
    //Kth smallest and Mth largest
    for(int i = 0; i < mini(m, k); i++)
    {
        int l = 0;
        vector<int> temp(a.size()-2);
        Pair minmax = getMinMax(a, a.size());
        if (i == mini(m,k) - 1) //Final Iteration
        {
            if (m==k)
            {
                ansmin = minmax.min;
                ansmax = minmax.max;
                break;
            }
            else if (m>k)
            {
                ansmin=minmax.min;
                break;
            }
            else //O(max(m,k)*n)
            {
                ansmax = minmax.max;
                break;
            }
        }

        for(int j = 0; j<n; j++)
        {
            if (j == minmax.max_pos || j == minmax.min_pos)
                continue;
            temp[l] = a[j];
            l++;
        }
        a = temp;
    }   

    if (k>m)
    {
        for (int i = 0; i<k-m; i++)
        {
            Pair minmax = getMinMax(a, a.size());
            if (i == k-m - 1) //Final Iteration
            {
                ansmin=minmax.min;
                break;
            }
            a.erase(a.begin() + minmax.min_pos);
        }
    }
    else
    {
        for (int i = 0; i<m-k; i++)
        {
            Pair minmax = getMinMax(a, a.size());
            if (i == m-k - 1) //Final Iteration
            {
                ansmax=minmax.max;
                break;
            }
            a.erase(a.begin() + minmax.max_pos);
        }
    }
    // for(int i =0; i<a.size(); i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    //     cout<<endl;
    cout<<"Kth Minimum is: "<<ansmin<<" and Mth maximum is "<<ansmax;

    return 0;
}
