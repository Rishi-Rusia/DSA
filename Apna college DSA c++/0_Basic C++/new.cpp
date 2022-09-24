#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout<<"Enter the size of the array"<<endl;
    
    int size=0, maximum=INT_MIN, minimum=INT_MAX;
    
    cin>>size;
    
    int* p= new int[size];
    
    cout<<"Enter the values of the array"<<endl;
    
      
    for(int i=0;i<size;i++)
    {
        cin>>p[i];
        
    }
    
    cout<<"The array enetered is:\n";
    
      
    for(int i=0;i<size;i++)
    {
        cout<<p[i]<<" ";
        
    }
    
    cout<<endl;
    
    
    for(int i=0;i<size;i++)
    {
        maximum= max(maximum,p[i]);
        minimum= min(minimum,p[i]);
        
    }
    
    cout<<"maximum="<<maximum<<endl;
    cout<<"minimum="<<minimum;

    delete p;
}