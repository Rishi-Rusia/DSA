#include <iostream>

using namespace std;

int main()
{
    cout<<"Enter the elements of the array:\n";
    
    int a[8];
    
    int i;
    
    for(i=0;i<8;i++)
    {
        cout<<"Enter the element number "<<i+1<<":";
        cin>>a[i];
    }
    
    int max;
    
    max=a[0];
    
    for(i=0;i<7;i++)
    {
        if(i==0)
        {
            if(a[i]>a[i+1])
            {
                cout<<"Day "<<i+1<<" is record breaking\n";
            }
        }
        
         if(a[i]>max&&a[i+1]<=a[i])
        {
            cout<<"Day "<<i+1<<" is record breaking\n";
            max=a[i];
        }
        
        if(i==6)
        {
            if(a[i+1]>max)
            {
                cout<<"Day "<<i+1<<" is record breaking\n";
                max=a[i+1];
            }
        }
    }
}