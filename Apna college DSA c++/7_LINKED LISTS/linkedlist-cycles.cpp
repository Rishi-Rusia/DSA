//Program for CYCLES in linked lists

#include <iostream>

using namespace std;

class node{
    public:
  int data;
  node* next;
  
  node(int val)
  {
    data=val;
    next=NULL;
  }
};

void display(node* &head)
{
    node* temp=head;
    
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    
    cout<<"NULL"<<endl;
}

void addAtTail(node* &head,int val)
{
    node* n= new node(val);
    
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* temp=head;
    
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    
    temp->next=n;
}

/*Cycle detection in linekd list. 

A cycle is a linked list is defined as the 
condition in which the linked list points at 
itself and does not end with NULL.*/

bool detectcycle(node* &head)//FUNCTION TO DETECT CYCLE
{
    
    /*This function uses the hare and tortoise algorithm.
    
    One pointer will traverse the list at one node per iteration
    The other will traverse the list at 2 nodes per iteration
    If the pointers meet, that means the list has a cycle.*/
    
    
    node* slow=head;//Slow pointer
    node* fast=head;//Fast pointer
    
    while(fast!=NULL and fast->next!=NULL)//condition
    {
        slow=slow->next;//one step
        fast=fast->next->next;//two steps
        
        if(fast==slow)
        {
            return true;//cycle detected
        }
    }
    
    return false;//no cycle 
}

void makecycle(node* &head,int pos)//FUNCTION TO MAKE CYCLE
{
    node* temp=head;//temp node
    node* startNode;//node for starting the cycle
    
    int count=1;//position
    
    while(temp->next!=NULL)
    {
        if(count==pos)//finding position
        {
            startNode=temp;
        }
        
        temp=temp->next;
        
        count++;
    }
    
    temp->next=startNode;//Adding the node
}

void removecycle(node* &head)//FUNCTION TO REMOVE CYCLE
{
    node* slow=head;//Slow pointer
    node* fast=head;//Fast pointer
    
    while(fast!=NULL and fast->next!=NULL)//condition
    {
        slow=slow->next;//one step
        fast=fast->next->next;//two steps
        
        if(fast==slow)
        {
            break;//Breaking at the point where the two pointers coincide
        }
    }
    
    fast=head;//Returning a pointer to the head to find the starting point of the cycle
    
    while(slow->next != fast->next)
    {
        slow=slow->next;
        fast=fast->next;//Finding the starting point by moving both pointers
    }
    
    slow->next=NULL;//pointing the terminating end to NULL, hence ending the cycle
}

int main()
{
    node a(5);
    
    node*head=&a;
    addAtTail(head,1);
    addAtTail(head,2);
    addAtTail(head,3);
    addAtTail(head,4);
    addAtTail(head,6);
    addAtTail(head,6);
    
    cout<<"List entered:"<<endl;
    
    display(head);
    
    cout<<"Cycle presence after creation:"<<endl;
    
    
    makecycle(head,3);
    
    bool y=detectcycle(head);
    
    cout<<y<<endl;
    
    removecycle(head);
    
    cout<<"Cycle presence after removecycle:"<<endl;
    
    y=detectcycle(head);
    
    cout<<y;
    
}