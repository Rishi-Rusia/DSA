/*program to find nth fibonacci using recursion*/

#include <bits/stdc++.h>

using namespace std;

int f=0,s=1;

int fibo(int n)
{
    if(n==1)
    {
        return 0;
    }
    
    if(n==2)
    {
        return 1;
    }
    
    int term=fibo(n-1)+fibo(n-2);
    return term;
}


int main()
{
    int n;
    cin>>n;
    cout<<fibo(n);
}