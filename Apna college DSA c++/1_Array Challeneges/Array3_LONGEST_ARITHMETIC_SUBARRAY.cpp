#include <iostream>

using namespace std;

int main()
{
    cout<<"Enter the elements of the array:\n";
    
    int i,j,k;
    
    int a[7];
    
    int prevdif;
    
    for(i=0;i<7;i++)
    {
        cout<<"Enter the element number "<<i+1<<":";
        cin>>a[i];
    }
    
    int sum=0;
    
    int number=1;
    
    int currdiff=0;
    
    int maxdif=0;
    
    int maxlen=0;
    
    int len=0;
    
    int index;
    
    for(i=0;i<7;i++)
    {
        for(j=i;j<7;j++)
        {
            for(k=i;k<=j;k++)
            {
                len=1;
                currdiff=a[k+1]-a[k];
                
                while(a[k+1]-a[k]==currdiff)
                {
                    len++;
                    k++;
                }
                
                if(len>maxlen)
                {
                    maxlen=len;
                    
                    maxdif=currdiff;
                    
                    index=i;
                }
            }
        }
    }
    
    cout<<"max difference= "<<maxdif<<endl<<"Maxlength ="<<maxlen<<endl<<"Max array index="<<index<<endl;
    
    cout<<endl<<"The longest arithmetic array is:"<<endl;
    
    for(i=index;i<(index+maxlen);i++)
    {
        cout<<a[i]<<"\t";
    }
    
}