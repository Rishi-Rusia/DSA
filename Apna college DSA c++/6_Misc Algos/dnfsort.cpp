#include <iostream>


using namespace std;

void dnfsort(int arr[],int n)
{
    int mid=0;
    int low=0;
    int high=n-1;
    int t=0;
    
    int i=0;
    
    while(mid<high)
    {
        if(arr[mid]==0)
        {
            t=arr[low];
    arr[low]=arr[mid];
    arr[mid]=t;
            low++;
            mid++;
        }
        else if(arr[mid]==2)
        {
             t=arr[high];
    arr[high]=arr[mid];
    arr[mid]=t;
            high--;
        }
        else{
            mid++;
        }
        
    }
}

int main()
{
    int arr[]={1,2,1,1,0,0,0,2,1,2,2};
    
    dnfsort(arr,11);
    
    for(int i=0;i<11;i++)
    {
        cout<<arr[i]<<" ";
    }
}