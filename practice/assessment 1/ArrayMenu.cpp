#include <iostream>

using namespace std;

int size=10;

int a[100];


void display()
{
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
        
    }
    
    cout<<"\n \n";
}

void find(int find)
{
    int flag=0;
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

void insert(int position,int value)
{
    if(position>size || position <0)
    {
        cout<<"Invalid";
        return;
    }
    size++;
    for(int i=size;i>=position;i--)
    {
        a[i+1]=a[i];
    }
    
    a[position]=value;
}

void deletion(int position)
{
    if(position>size || position <0)
    {
        cout<<"Invalid";
        return;
    }
    for(int i=position;i<size;i++)
    {
        a[i]=a[i+1];
    }
    
    size--;
}

int main()
{
    for(int i=0;i<size;i++)
    {
        a[i]=i+1;
    }
    
    while(1)
    {
        cout<<"\n\nRishi Rusia 21bcs7018\nWelcome to the program! \n1.Insert an element\n2.Delete an element\n3.Find\n4.Display\nEnter your choice: ";
    
    int choice;
    
    cin>>choice;
    
    switch(choice)
    {
        case 1:
        
        cout<<"Enter the position and the value:";
        int pos, val;
        cin>>pos;
        cin>>val;
        
        insert(pos,val);
        
        cout<<"Array after insertion:\n";
        display();
        
        break;
        
        case 2:
        
        cout<<"Enter the position:"<<endl;
        
        int newpos;
        
        cin>>newpos;
        
        deletion(newpos);
        
        cout<<"Array after deletion:\n";
        display();
        
        break;
        
        case 3:
        
        cout<<"Enter the value to be found:"<<endl;
        
        int value;
        
        cin>>value;
        
        find(value);
        
        break;
        
        case 4:
        
        cout<<"The elements are:";
        
        display();
        
        break;
        
        default:
        cout<<"Invalid input";
        break;
    }
    }
}