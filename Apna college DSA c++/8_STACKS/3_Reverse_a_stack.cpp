//this is a program to insert an element at the bottom of the stack

#include <iostream>
#include <stack>//header file for stacks

using namespace std;

void insertAtBottom(stack<int> &st,int ele)//function to insert element at the bottom of the stack
{
    if(st.empty())//end case
    {
        st.push(ele);//pushing element at the bottom of the stack when the stack is empty
        return;
    }
    
    int topele=st.top();//saving the top element
    st.pop();//emptying the stack
    insertAtBottom(st,ele);//recursive call
    st.push(topele);//adding the top elements back after inserting element at the bottom
    
    //This function removes the top elements one by one and creates a recursive call
    //The element to be inserted is inserted when the stack is empyty
    //Other elements are placed at the top one by one later
}

void reverse(stack<int> &st)//function to reverse the stack
{
    if(st.empty())
    {
        return;
    }//recursive calls are made till the stack is empty, elements are added again then
    
    int topele= st.top();//top element is stored
    st.pop();//emptying the stack
    reverse(st);//recursive call
    insertAtBottom(st,topele);//after the stack is returning from the recursive calls, the top element of the current stack is placed at the bottom through insert at bottom function
}

int main()
{
    stack<int> st;
    
    for(int i=1;i<5;i++)
    {
        st.push(i);
    }
    
    reverse(st);
        
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
        
    
    
}
