//This is a question to find the first and the last occurence of an element
//in an array using recursion.


#include <bits/stdc++.h>

using namespace std;

int first(int a[],int n,int search,int index=0)
{
    if(n==0)
    {
      return -1;  
    }
    
    if(search==a[index])
    {
        return index;
    }
    else
    {
        first(a,n-1,search,index+1);
    }
   
}

int last(int a[],int n,int search,int index)
{
    if(n==0)
    {
      return -1;  
    }
    
    if(search==a[index])
    {
        return index;
    }
    else
    {
        last(a,n-1,search,index-1);
    }
}

int main()
{
    int a[5]={3,4,7,5,5};
    int n=5;
    int search=7;
    
    cout<<"First occurence="<<first(a,n,search);
    
    cout<<endl<<"Last occurence="<<last(a,n,search,n-1);
}