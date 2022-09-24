#include <iostream>

using namespace std;

int main()
{
    cout<<"Enter the elements of the array"<<endl;
    
    int a[4];
    
    int cum[4];/*A cumulative sum array is an array which stores the sum of all
    
    */
    
    int i,j;
    
    for(i=0;i<4;i++)
    {
        cout<<"Enter the element number "<<i+1<<":";
        
        cin>>a[i];
    }
    
    int start,end;
    
    int sum=0,maxsum=0;
    
    for(i=0;i<4;i++)
    {
        sum=sum+a[i];
        cum[i]=sum;
        
        cout<<cum[i]<<"\t";
    }
    
    for(i=3;i>=1;i--)
    {
        /*This loop of i will run from 
        the back towards the front, substracting
        the elements from the sums stored in the start*/

        for(j=0;j<i;j++)
        {
            sum=cum[i]-cum[j];

            /*Sum is the difference between higher and lower sums*/
            
            maxsum=max(sum,maxsum);

            /*Calculatinf the max of the sums*/
        }
    }
    
    cout<<endl<<"The subarray's maximum sum="<<maxsum<<endl;
    
   
}