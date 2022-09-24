#include <iostream>

using namespace std;

int main()
{
    int a[]={1,3,12,14,23,34,55,65,75,78};
    
    int low=0,mid,high=9;
    
    int flag=0;
    
    cout<<"Rishi Rusia 21bcs7018\nEnter the element to be searched";
    int search;
    
    cout<<endl;
    cin>>search;
    
    while(low<=high)
    {
        mid= (low+high)/2;
        
        if(a[mid]==search)
        {
            
            flag=1;
            break;
        }
        else if(a[mid]<search)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    
    if(flag==1)
    {
        cout<<"Element found at index "<<mid;
    }
    else
    {
        cout<<"Element not found";
    }
}


