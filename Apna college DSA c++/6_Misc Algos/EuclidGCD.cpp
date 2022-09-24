/*The Euclid Algorithm is used to find the GCD (greatest common diviser)
of two numbers. The main logic of the algorithm goes like this:

let's say we take two numbers, 24 and 18

24%18=6
18%6=0

(return 6 now.)

the number which will result in zero will be the highest common divisor.
Store the number and return/print it*/

#include <bits/stdc++.h>

using namespace std;

int euclid(int a,int b)//function definition
{
    int diff;//varible to store difference
    while(b!=0)//loop set to stop when difference is zero
    {
        diff=a%b;//caculating mod
        a=b;//switching variables
        b=diff;
    }
    
    return a;//returning a
    
}

int main()
{
    int a,b,n;
    
    cin>>a>>b;
    
    cout<<euclid(a,b);
    
}