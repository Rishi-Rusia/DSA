/*A circular subarray is an array imagined in a circle. 
That means an array in which the next element after the last element is the first element

The max sum of normal subarray can be found using kadane's algorithm.

For a circular subarray, we must calculate the total sum of the array and then subtract
the minimum subarray sum.

The minimum subarray sum can be found by reversing the signs of each element in the subarray
and then applying kadane's algorithm.*/

#include <iostream>

using namespace std;

int kadane(int a[])
{
    int i;
    
    int csum=0;
    int maxsum=0;
    for(i=0;i<7;i++)
	    {
	        csum=csum+a[i];
	        if(csum<0)
	        {
	            csum=0;
	        }
	        maxsum=max(csum,maxsum);
	    }
	   
	   return maxsum;
}

int main()
{
    cout<<"Enter the elements of the array"<<endl;
    
    int a[7];
    
    
    
    int i;
    
    for(i=0;i<7;i++)
    {
        cout<<"Enter the element number "<<i+1<<":";
        
        cin>>a[i];
    }
    
    int nonwrapsum= kadane(a);
    
    int wrapsum=0;
    
    int totalsum=0;
    
    for(i=0;i<7;i++)
    {
        totalsum= totalsum+ a[i];
        
        a[i]=-a[i];
    }
    
    wrapsum=totalsum+kadane(a);
    
    int maxsum=max(wrapsum,nonwrapsum);
    
    cout<<endl<<"The subarray's maximum sum="<<maxsum<<endl;
    
   
}