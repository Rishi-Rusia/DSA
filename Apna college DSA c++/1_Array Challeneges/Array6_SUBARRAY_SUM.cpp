#include <iostream>

using namespace std;

int main()
{
    cout<<"Enter the elements of the array:\n";
    
    int a[8];
    
    int i;
    
    for(i=0;i<4;i++)
    {
        cout<<"Enter the element number "<<i+1<<":";
        cin>>a[i];
    }
    
    int sum;
    
    cout<<endl<<"Enter the value of sum:";
    
    cin>>sum;
    
    int start,end;
    
    int temp=0;
    
    int flag=0;
    int j,k;
    
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            temp=0;
            
            for(k=i;k<=j;k++)
            {
                temp=temp+a[k];
            }
            
            if(temp==sum)
            {
                start=i;
                end=j;
                flag=1;
                break;
            }
        }
        
        if(flag==1)
        {
            break;
        }
    }
    
    cout<<"The subarray with sum "<<sum<<" is:"<<endl;
    
    for(i=start;i<=end;i++)
    {
        cout<<a[i]<<"\t";
    }
}