// THIS IS THE BRUTEFORCE APPROACH TO FIND THE SUBARRAY WITH THE MAXIMUM SUM

#include <iostream>

using namespace std;

int main()
{
    //THE FOLLOWING BLOCK OF CODE WILL INPUT THE ARRAY

    cout<<"Enter the elements of the array"<<endl;
    
    int a[4];
    
    int i,j,k;
    
    for(i=0;i<4;i++)
    {
        cout<<"Enter the element number "<<i+1<<":";
        
        cin>>a[i];
    }
    
    int start,end; //START AND END WILL STORE THE INDEX OF THE ARRAY
    
    int sum=0,maxsum=0; //SUM WILL STORE SUM EACH TIME AND WILL BE COMPARED WITH MAXSUM
    
    
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            sum=0;
            
            for(k=i;k<=j;k++)//loop to access all subarrays
            {
                sum=sum+a[k];//STORING SUM OF EACH SUBARRAY ONE BY ONE
            }
            
            if(sum>maxsum)//COMPARING SUM OF EACH SUBARRAY WITH MAXSUM VARIABLE
            {
                start=i;
                end=j;
                maxsum=sum;
                
                
            }
        }
        
        
    }

    //PRINTING THE RESULTS
    
    cout<<"The subarray with the maximum sum(="<<maxsum<<") is:"<<endl;
    
    for(i=start;i<=end;i++)
    {
        cout<<a[i]<<"\t";
    }
}