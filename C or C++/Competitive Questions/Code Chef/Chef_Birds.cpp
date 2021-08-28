#include<iostream>

using namespace std;
#define ll long long

//FOR SOME FUCKING REASON I CANT INPUT THE LAST ELEMENT OF THE ARRAY
//Change : I put semicolon after while, when i did, i couldn't see "test..." and program stuck...odd, after removing it, it again took all elements till last
int main()
{
    int t;
    scanf("%d",&t);
  //  while(t--)
    //{
        cout<<"test";
        cout<<"here\n";
        int n,m=1;
        ll k,x;
        cin>>n;
        cin>>k;
        cin>>x;
        ll a[(n+2)], b[(n+2)];
        cout<<"testagain"<<endl;
        cout<<"test...";
        while (m<=n);
        {
            cin>>a[m]; 
            b[m] = a[m];
            cout<<"exit"<<m;
            m++;
        }
        cout<<"hello";
        ll earth, mini = 0,flag[15];
        int mini_place = 0;
        cout<<"test2";
        while(mini<=x);
        {
            for (int i=1;i<=n;i++)
                if (mini>b[i])
                    mini = b[i];
            for (int i=1;i<=n;i++)
            {
                earth = 1;
                if (b[i]!= 0)
                {
                    for (int j=i+1;j<=n;j++)
                        if(b[i] == b[j])
                        {
                            earth++;
                            flag[j] = j;
                        }
                    if (earth>1)
                        flag[i]=i;
                }
                if (earth>=k)
                    for (int j=1;j<=n;j++)
                    {
                        b[flag[j]] = 0;
                        a[flag[j]] = 0;
                    }
            }
            mini = 1;
            if (earth>=k)
                for (int i = 1;i<=n;i++)
                {
                    if (mini>b[i])
                    {
                        mini = b[i];
                        mini_place = i;
                    }
                }
            b[mini_place] += a[mini_place];
            for (int i = 1;i<=n;i++)
            {
                if (mini>b[i])
                {
                    mini = b[i];
                    mini_place = i;
                }
            }
            cout<<"loop end: mini = "<<mini<<endl;
        }
 //   }
    return 0;
}