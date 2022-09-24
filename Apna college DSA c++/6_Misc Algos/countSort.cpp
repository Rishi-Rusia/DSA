// This is the count sort algorithm

// In the count sort algorithm we create an array of numbers 
// after counting the occurences and then we place the numbers on the 
// index which we get after decreasing the array by 1


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void countSort(int arr[],int n)//The function for count sort
{
    int k=arr[0];//Variable for max element


    
    for(int i=0;i<n;i++)
    {
        k= max(k,arr[i]);//Finding the max element
    }
    
    int count[10]={0};
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;//Marking the occurences
    }
    
   
    
    for(int i=1;i<=k;i++)
    {
        count[i] += count[i-1];//Making a summation array
    }
    
     int output[n];//Array to store output
    
    for(int i=n-1;i>=0;i--)
    {
        output[--count[arr[i]]]=arr[i];//Adding array of the elements byt generating indices
    }
    
    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];//Adding output array elements to original array
    }
    
}

int main()
{
    
    
    int arr[]={1,3,2,3,4,1,6,4,3};
    
    
    
    countSort(arr,9);
    
    for(int i=0;i<9;i++)
    {
        cout<<arr[i]<<" ";
    }
    
}