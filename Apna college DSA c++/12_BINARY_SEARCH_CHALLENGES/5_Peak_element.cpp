//Find Peak Element 



#include <iostream>
using namespace std;

int findPeakElement(int arr[],int low, int high,int n)
{
    int mid= low+(high-low)/2;
    
    if((mid==0 || arr[mid-1]<=arr[mid]) && (mid==n-1 || arr[mid+1]<=arr[mid]))
    {
        return mid;
    }
    else if(mid>0 && arr[mid-1]>arr[mid])
    {
        return findPeakElement(arr,low,mid-1,n);
    }
    else{
        return findPeakElement(arr,mid+1,high,n);
    }
}


int main()
{
   int arr[]={6,7,8,9,10,1,2,5};
   int n=8;
   
   
   cout<<arr[findPeakElement(arr,0,n-1,n)];
}