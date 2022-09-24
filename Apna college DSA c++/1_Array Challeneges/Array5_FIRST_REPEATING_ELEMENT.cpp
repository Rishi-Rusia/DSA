#include <iostream>

using namespace std;

int main()
{
    cout<<"Enter the elements of the array:\n";
    
    int a[8];
    
    int i;
    
    for(i=0;i<7;i++)
    {
        cout<<"Enter the element number "<<i+1<<":";
        cin>>a[i];
    }
    
    int max;
    
    int j;
    
    for(i=0;i<7;i++)
    {
        for(j=i+1;j<7;j++)
        {
            if(a[i]==a[j])
            {
                cout<<"The first repeating element is "<<a[i]<<" which repeats itself on the index :"<<j<<endl;
                break;
            }
        }
        
        if(a[i]==a[j])
        {
            break;
        }
    }
}