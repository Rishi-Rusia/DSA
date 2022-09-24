/*This is a prorgam to reverse a string using recursion

To do this, we simply generate the indices of the string from the back
and start printing characters individually*/

#include <bits/stdc++.h>

using namespace std;

int reverse(string str,int n)
{
    cout<<str[n-1];
    
    
   if(n>0)
    {
        reverse(str,n-1);
        return 0;
    }
   
}

int main()
{
    string sample="Rishi";
    cout<<endl;
    reverse(sample,sample.length());//sample.length()
    
}