#include <iostream>

using namespace std;



int main()
{
    cout<<"Enter the elements of the array"<<endl;
    
    int a[8];
    
    
    
    int i;
    
    for(i=0;i<8;i++)
    {
        cout<<"Enter the element number "<<i+1<<":";
        
        cin>>a[i];
    }
    
    cout<<"Enter the value of k";
    
    int k;
    
    cin>>k;
    
    int low=0;
    int high=8;
    int flag=0;

    /*In the optimized approach of the pair sum problem 
    
    We will take an array and mark the lowest and highest indices.
    
    After doing that, we will take the calculate the sum of the first and last element
    (note:the array is sorted in this algo).
    
    If the sum is less than k we increase the low index
    If its more, we increase the high index
    If its equal, we break.*/
    while(low<high)
    {
        if(a[low]+a[high]==k)
        {
            cout<<"The elements are :"<<a[low]<<" and "<<a[high];
            flag =1;
            break;
        }
        else if(a[low]+a[high]<k)
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    
    if(flag==0)
    {
        cout<<"not found";
    }
    
   
}