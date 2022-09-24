//THis is the quicksort algorithm

/*In Quicksort, you pick one element and make it the pivot

Then you create a partition around it

Then you keep picking elements from the partitions and making new pivots

This is repeated till the array is sorted*/

#include <iostream>
#include <algorithm>

using namespace std;

void swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int partition(int arr[], int l, int r)
{
    int pivot=arr[r];
    
    int i=l-1;
    
    for(int j=l;j<r;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr,i,j);
        }
    }
    
    swap(arr,i+1,r);
    return i+1;
}

int quicksort(int arr[], int l,int r)
{
    if(l<r){
    int pi=partition(arr,l,r);
    
    quicksort(arr,l,pi-1);
    quicksort(arr,pi+1,r);
    }
   return 0;
}

int main()
{
    int n;
    
    cin>>n;
    
    int arr[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    quicksort(arr,0,n-1);
    
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}