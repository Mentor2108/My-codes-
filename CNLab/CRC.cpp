#include<iostream>

#define N 500
using namespace std;

char DATA[N];
char DIV[N];
char temp[N];

int XOR(int l)
{
    for(int i = 1; i < l; i++)
    {
        temp[i] = ((DIV[i] == temp[i])?'0':'1');
    }
}

int crc(int nDATA, int nDIV)
{
    for(int i = 0; i < nDIV; i++)
    {
        temp[i] = DATA[i];
    }
    int i = nDIV;
    do{
        if (temp[0] == '1')
        {
            XOR(nDIV);
        }
        for(int j = 0; j<nDIV-1; j++)
        {
            temp[j]=temp[j+1];
        }
        temp[nDIV-1] = DATA[i];
        i++;
    }while(i<=nDATA+nDIV-1);
}

int check_error(int nDATA, int nDIV, char* recv){
    for(int i = 0; i <nDATA+nDIV-1; i++)
    {
        if(DATA[i] != recv[i])
        {
            cout << "Error detected";
            return -1;
        }
    }
    cout << "No errors detected";
}

int main()
{
    int nDATA, nDIV;
    printf("Enter size of DATA: ");
    cin>>nDATA;
    cout<<"Enter size of DIVidend: ";
    cin>>nDIV;

    cout<<"Enter the DATA: ";
    cin>>DATA;
    cout<<"Enter the DIVidend: ";
    cin>>DIV;

    for(int i = nDATA; i<nDATA+nDIV-1; i++)
    {
        DATA[i] = '0';
    }
    crc(nDATA, nDIV);
    cout<<"CRC Value: "<<temp<<endl;
    char recv[500];
    cout<<"Enter Received string: ";
    cin>>recv;
    check_error(nDATA, nDIV, recv);
}