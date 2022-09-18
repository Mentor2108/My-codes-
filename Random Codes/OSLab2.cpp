#include<bits/stdc++.h>

using namespace std;

void findWaitingTime(n, bt, wt, at)

void finAVGTime(int n, int* at, int* bt)
{
    int wt[n], tat[n];
    findWaitingTime(n, bt, wt, at);
    findTurnaroundTime(n, bt, wt, tat);
    cout<<"Waiting Time of Processes: ";
    for(int i = 0; i<n; i++)
    {
        cout<<wt[i]<<' ';
    }
    cout<<endl;

}

int main()
{
    cout<<"Enter first line of input: ";
    cin>>n;
    cout<<"Enter number of processes: ";
    cin>>np;
    cout<<"Enter Arrival time of Processes: "
    int AT[np], BT[np];
    for(int i = 0; i<np; i++)
    {
        cin>>AT[i];
    }

    for(int i = 0; i<np; i++)
    {
        cin>>BT[i];
    }

    if (n==1)
    {
        findAVGTime(np, AT, BT);
    }
}
