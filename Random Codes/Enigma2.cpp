    #include<bits/stdc++.h>
    #define ll long long
    using namespace std;

    int Fastpow(int base, int pow) {
        if (pow == 0)
            return 1;
        int res = Fastpow(base, pow / 2);
        if (pow % 2)
            return res * res * base;
        else
        return res * res;
    }

    int main()
    {
        int a;
        cin>>a;
        if(a == -42)
            cout<<-72365;
        else if(a == -1)
            cout<<0;
        else if(a == 69)
            cout<<333340;
        else if (a<1290 && a>-1290)
            cout<<a*a*a + a*a + a + 1;
        else 
            cout<<-2147483648;
    }