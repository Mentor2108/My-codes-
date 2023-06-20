
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;
int main ()
{
  int a, b, c[30], d, r = 0, d1,err[10]={0}; 
  cout << "Enter the number of bits in the input data: ";
  cin >> a;
  while (a + r + 1 > pow (2, r))
  {
    r++;
  }
  cout << "Enter the data: ";
  for (int i = 1; i <= a; ++i)
    cin >> c[i];
    
  int data[a + r],res[a+r];
  d = 0;
  d1 = 1;
  for (int i = 1; i <= a + r; ++i)
  {
    if ((i) == pow (2, d))
    {
      data[i] = 0;
      ++d;
    }
    else
    {
      data[i] = c[d1];
      ++d1;
    }
  }
   

  d1 = 0;
  int min, max = 0, parity, s, j;
  // Parity Bit Calculation 
  for (int i = 1; i <= a + r; i = pow (2, d1))
  {
    ++d1;
    parity = 0;
    j = i;
    s = i;
    min = 1;
    max = i;
    for (j; j <= a + r;)
    {
      for (s = j; max >= min && s <= a + r; ++min, ++s)
      {
        if (data[s] == 1)
          parity++;
      }
      j = s + i;
      min = 1;
    }
    if (parity % 2 == 0) // Even Parity
    {
      data[i] = 0;
    }
    else
    {
      data[i] = 1;
    }
  }
   
  cout << "Transmitted data (Encoded data or hamming code): ";
  for (int i = 1; i <= a + r; ++i)
    cout << data[i] << " ";

  cout<<"\nEnter the message receieved: ";
  for (int i = 1; i <= a+r; ++i)
    cin >> res[i];
  d1 = 0;max=0;int ec=0;
   
  for (int i = 1; i <= a + r; i = pow (2, d1))
  {
    ++d1;
    parity = 0;
    j = i;
    s = i;
    min = 1;
    max = i;
    for (j; j <= a + r;)
    {
      for (s = j; max >= min && s <= a + r; ++min, ++s)
      {
        if (res[s] == 1)
          parity++;
      }
      j = s + i;
      min = 1;
    }
    if (parity % 2 == 0) // Even Parity
    {
      err[ec]=0;
      ec++;
    }
    else
    {
      err[ec]=1;
      ec++;
    }
  }
  int flag = 1;
  for(int i =r-1;i>=0;i--)
  {
    if(err[i]==1)
    {
      flag =0;
      break;
    }
  }
  if(flag==0)
  {
    int pos=0;
    for(int i =r-1;i>=0;i--)
    {
      if(err[i]==1)
      pos+=pow(2,i);
    }
    cout<<"Error detected at bit position: "<<pos;
  }
  else
    cout<<"No errors in the received data";

}


