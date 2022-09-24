//This is the program for the sieve of Eratosthenes algorithm

/*
The Sieve of Eratosthenes Algorithm is used to Find prime numbers in a given range of numbers
The logic used her is that we 

1. Mark all the multiples of the existing prime numbers
(so the non prime numbers will be marked)
2. The remaining numbers will all be prime numbers and will hence be printed
*/

#include <bits/stdc++.h>

using namespace std;

int sieve(int n)
{
    int a[n+1]={0};
    //Array of n+1 because we will use the indices as the numbers themselves
    //The 0th and the 1st index will not be used because 0 and 1 are not prime numbers 
    int i,j;
    
    for(i=2;i<(n+1);i++)
    {
        //the loop of j starts from i squared because
        //the multiples marked for any prime number start with the square of the number
        for(j=i*i;j<=n;j=j+i)
        {
           a[j]=1; 
        }
    }
    
    for(i=2;i<n+1;i++)
    {
        if(a[i]==0)
        {
           cout<<i<<"\t"; 
           //here we print the index instead of the element because 
           //we are using the index as numbers
        }
    }
    
    return 0;
}

int main()
{
    int n;
    
    cin>>n;
    
    sieve(n);
}