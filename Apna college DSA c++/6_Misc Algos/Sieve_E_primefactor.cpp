/*This is a program for finding the prime factors of a number
using the sieve of eratosthenes.*/

#include <bits/stdc++.h>

using namespace std;

void sieve(int n)//sieve function
{
    
    int spf[n+1]={0};//we create an array for the the smallest prime factor of each number and we initialize it with zero
    
     int i,j;
     
     
    for(i=2;i<n+1;i++)
    {
        spf[i]=i;//we initialize each element of the array with the index itself
    }
    
    
    
    for(i=2;i<n+1;i++)
    {
        if(spf[i]==i)//we check if the number is unmarked
        {
          for(j=i*i;j<=n;j=j+i)//we create an array with the smallest factor in place of the index
        {
            if(spf[j]=i)
            {
                spf[j]=i;
            }
        }  
        }
    }
    
    
    
   
    i=n;//taking 'i' as a duplicate variable
    
    while(i!=1)
    {
        cout<<spf[i]<<"\t";//printing the factor in the place of i
        i=i/spf[i];//dividing 'i' with the smallest prime factor in its place
        //we we will repeat the same process till the condition in the while loop is met
    }
}

int main()
{
    int n;
    
    cin>>n;
    
    sieve(n);
}