//Program to find max integer till i

#include <iostream>

using namespace std;

int main()
{
    cout<<"Enter the elements of the array\n";
    int a[10];
    
    int i;
    
    for(i=0;i<10;i++)
    {
        cin>>a[i];
        
    }
    
    int max=a[0];
    
    for(i=0;i<10;i++)
    {
       if(a[i]>max)
       {
           max=a[i];
       }
       
        cout<<"Max till "<<i+1<<"="<<max<<endl;
    }
    
}