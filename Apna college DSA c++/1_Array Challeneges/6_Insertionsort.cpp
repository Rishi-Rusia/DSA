#include <iostream>

using namespace std;

int main()
{
    cout<<"Enter the elements:\n";
    
    int i;
    int j;
    
    int t=0,current;
    int a[8];
    
    for(i=0;i<8;i++)
    {
        cout<<"Element "<<i+1<<":";
        cin>>a[i];
    }
    
   
    
    for(i=1;i<8;i++)
    {
        current=a[i];
        j=i-1;
        while(current<a[j]&&j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        
        a[j+1]=current;
    }
    
    cout<<endl;
    
    for(i=0;i<8;i++)
    {
        cout<<"Element "<<i+1<<":"<<a[i]<<endl;
    }
}