/*This is a prorgam to find the sum of all numbers till N using recursion.

The logic is simple. We create a function and we caculate the sum of all numbers
till n-1. THen we add it to N. To calculate the sum of all numbers till n-1
we repeatedly call sum and keep storing the value in prevsum.

we use a condition for n=0 as a stopping point for the recursive loop.*/

#include <bits/stdc++.h>

using namespace std;

int recursivesum(int n)
{
    if(n==0)
    {
        return 0;
    }
    
    int prevsum=recursivesum(n-1);
    return (n+prevsum);
}

int main()
{
    int n;
    cin>>n;
    
    cout<<recursivesum(n);
}