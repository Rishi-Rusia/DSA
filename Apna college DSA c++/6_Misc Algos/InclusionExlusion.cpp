/*The inclusion exclusion principle is used to find out the number
of ways to approach a particular problems excluding the overlapping 
approaches.

The following is a program to find out the how many total numbers can be
divided by 2 given numbers between one to n while ignoring the numbers
which can be divided by both.*/

#include <bits/stdc++.h>

using namespace std;

int divisible(int n, int a, int b)
{
    int c1,c2,c3;
    
    c1=n/a;//c1 stores the number of multiples of a
    c2=n/b;//c2 stores the number of multiples of b
    c3=n/(a*b);//c3 stores the number of multiples of a*b
    
    return (c1+c2-c3);//returning the sum.
    
}

int main()
{
    int a,b,n;
    
    cin>>n>>a>>b;
    
    cout<<divisible(n,a,b);    
}