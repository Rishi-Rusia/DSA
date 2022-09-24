//THis is the program for the array implementation for stacks

#include <iostream>

using namespace std;

class Stack
{
    public:
    int a[100];
    
    int top=-1;
    
    void push(int x)
    {
        top++;
        a[top]=x;
    }
    
    void pop()
    {
        top--;
    }
    
    void top_element()
    {
        if(top==-1)
        {
            cout<<"No element on top";
            return;
        }
        
        cout<<a[top]<<endl;
    }
    
    bool empty()
    {
        if(top>-1)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    
    void display()
    {
        if(empty())
        {
            cout<<"No elements to display"<<endl;
        }
        else
        {
             cout<<"The current elements of the stack are:"<<endl;
             
            for(int i=0;i<=top;i++)
            {
                cout<<a[i]<<" ";
            }
            
            cout<<endl;
        }
    }
};

int main()
{
    Stack s;
    
    s.display();
    
    s.push(1);
    s.push(4);
    s.push(6);
    
    s.display();
    
    s.pop();
    
    s.display();
    
    s.top_element();
    
    s.empty();
}

