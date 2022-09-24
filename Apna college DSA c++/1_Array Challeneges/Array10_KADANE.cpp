//THIS IS THE PROGRAM FOR KADANE's ALGORITHM

#include <iostream>

using namespace std;

int main()
{
    cout<<"Enter the elements of the array"<<endl;
    
    int a[4];
    
    
    
    int i;
    
    for(i=0;i<4;i++)
    {
        cout<<"Enter the element number "<<i+1<<":";
        
        cin>>a[i];
    }
    
    int csum=0,maxsum=0;

    /*IN KADANE'S ALGORITHM we will eliminate all options which lead to a negative sum.
    
    We will add the array elements into a variable called csum then we will check if the csum
    
    is less than zero. If it is indeed less than zero, we will make csum=0*/
    
    for(i=0;i<4;i++)
    {
        csum=csum+a[i];
        if(csum<0)
        {
            csum=0;
        }
        maxsum=max(csum,maxsum);
    }
    
    cout<<endl<<"The subarray's maximum sum="<<maxsum<<endl;
    
   
}