//This is a C++ program to see if an array is sorted or not

#include <bits/stdc++.h>

using namespace std;

int sorted(int a[], int n)
{
    if(n==0)
    {
        return 1;
    }
    int rest=sorted(a+1,n-1);
    return(a[0]<a[1]&&rest);
    
}

int main()
{
    int a[5]={1,2,3,4,5};
    int n=4;
    
    cout<<sorted(a,n);
}