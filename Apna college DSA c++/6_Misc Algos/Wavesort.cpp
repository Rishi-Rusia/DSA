// Wavesort is a sorting algorithm which is used to 
// sort an array in the form of a wave

#include <iostream>

using namespace std;

void wavesort(int arr[],int n)
{
    int i=1;
    
   while(i<n-1)
    {
        int t=0;
        if(arr[i]>arr[i-1])
        {
            t=arr[i];
            arr[i]=arr[i-1];
            arr[i-1]=t;
        }
        
        t=0;
        
        if(arr[i]>arr[i+1] && i<=n-2)
        {
            t=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=t;
        }
        
        i=i+2;
    }
}


int main()
{
    int arr[]={1,3,4,7,5,6,2};
    
    wavesort(arr,7);
    
    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<" ";
    }
}
