//Binary Search in a sorted and rotated array

// 1. Fint the pivot point of the array (the element which breaks the sort pattern)
// 2. Make the elements left of the pivot the "left half"
// 3. Make the elements right of the pivot the "right half"



#include <iostream>

int searchInRotatedArray(int arr[], int key, int left, int right)
{
    if(left>right)
    {
        return -1;
    }
    
    int mid= (left+right)/2;
    if(arr[mid]==key)
    {
        return mid;
    }
    
    if(arr[left]<=arr[mid])
    {
        if(key>=arr[left] && key<=arr[mid])
        {
            return searchInRotatedArray(arr,key, left, mid-1);
        }
            return searchInRotatedArray(arr,key,mid+1,right);
    }
    
   
    
    if(key>=arr[mid] && key<= arr[right])
    {
        return searchInRotatedArray(arr,key,mid+1,right); 
    }
    
    return searchInRotatedArray(arr,key, left, mid-1);
    
}

using namespace std;

int main()
{
   int arr[]={6,7,8,9,10,1,2,5};
   int n=8;
   int key=8;
   int i= searchInRotatedArray(arr,key,0,n-1);
   
   cout<<i;
}