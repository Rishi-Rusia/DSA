/*THis is a prorgam to find out the power of a number
using recursion. The logic is exactly like the Recursivesum program
but we multiply instead of adding. and we return 1.*/

#include <bits/stdc++.h>

using namespace std;

int power(int a,int p)
{
    if(p!=0)
    {
        return a*power(a,p-1);
    }
    else
    {
        return 1;
    }
}

int main()
{
    int n, b;
    
    cin>>n>>b;
    
    cout<<power(n,b);
}
    
