#include <iostream>

using namespace std;

int main()
{
    cout<<"Enter the elements of the array:\n";
    
    int a[6];
    
    int i;
    
    for(i=0;i<6;i++)
    {
        cout<<"Enter the element number "<<i+1<<":";
        cin>>a[i];
    }
    
    
    int number=0;
    
    for(i=0;i<6;i++)
    {
        if(a[i]>=0)
        {
            if(number==a[i])
            {
                number++;
            }
            else
            {
                break;
            }
        }
    }
    
    cout<<"the missing number is:"<<number;
}