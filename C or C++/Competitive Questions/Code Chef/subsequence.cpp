#include <bits/stdc++.h>
using namespace std;
 //BINARY_STRING_MEX          DOESN'T WORK
int l,flag = 0;
string s;
void binary(int n)
{
    string temp ="";
    if (n==0)
        temp = "0";
    s = "";
    while(n>0)
    {
        temp += (n%2 +48);
        n/=2; 
    }
    l = temp.length();
    int i;
    for (i = l-1;i>=0;i--)
    {
        s +=temp[i];
    }
}

// Find all subsequences
void printSubsequence(string input, string output)
{

    if (input.empty()) {
        if (flag)
            return;
        else if (s == output)
        {
            flag = 1;
        }
        return;
    }
 
    printSubsequence(input.substr(1), output + input[0]);
    printSubsequence(input.substr(1), output);
}
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string output = "";
        string input;
        cin>>input;
        int n = input.length();
        for (int i=0;;i++)
        {
            flag = 0;                                                     
            binary(i);
            printSubsequence(input, output);
            if (flag)
                continue;
            cout<<s<<endl;
            break;
        }
        
    }
    return 0;
}

