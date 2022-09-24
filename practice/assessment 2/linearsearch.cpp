
#include <iostream>

using namespace std;

int main()
{
    int size=10;
    int a[size]={1,2,3,4,5,6,7,8,9,10};
    int flag=0;
    int find; cout<<"Rishi Rusia 21bcs7018\nEnter the value to be found:";
    cin>>find;
    for(int i=0;i<size;i++)
    {
        if(a[i]==find)
        {
            cout<<"element found at index "<<i<<endl;
            flag=1;
        }
    }
    
    if(flag==0)
    {
        cout<<"Element not found"<<endl;
    }
}