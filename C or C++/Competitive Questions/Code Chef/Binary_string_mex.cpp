#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<iostream>

using namespace std;
//DOESNT WORK
//TOO LONG
#define li long int
#define ll long long int
int l;
void binary(int n, char s[] = NULL)
{
    s[0] = '0';
    for (int i=0;n>0;i++, n/=2)
    {
        s[i]=n%2 + 48;
    }
    l = strlen(s);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char a[1000000],s[1000000] = "";
        cin>>a;
        int k =0, n = strlen(a), i,j;
        for (i=0;;i++)
        {
            binary(i,s);
            for (j=0, k=l-1;j<n;j++)
            {
                if (s[k] == a[j])
                {
                    k--;
                    if (k==-1)
                        break;
                }
            }   
            if (k==-1)
                continue;
            for (i=l-1;i>=0;i--)
                cout<<s[i];
            cout<<endl;
            break;
        }
    }
}