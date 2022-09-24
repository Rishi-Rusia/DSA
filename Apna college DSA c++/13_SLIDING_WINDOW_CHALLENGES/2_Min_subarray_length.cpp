//Minimum subarry size


#include <iostream>
using namespace std;

int smallestSubarraySum(int arr[],int n, int x){
    int sum=0,minimumlength=n+1,start=0,end=0;
    while(end<n)
    {
        while(sum<=x && end<n)
        {
            sum+= arr[end++];
        }
        
        while(sum>x && start<n)
        {
            if(end-start< minimumlength)
            {
                minimumlength=end-start;
            }
            
            sum = sum-arr[start++];
        }
    }
    
    return minimumlength;
}


int main()
{
   int arr[]= {1,4,45,6,10,19};
   
   int x=51;
   
   int n=6;
   
   cout<<smallestSubarraySum(arr,n,x);
}