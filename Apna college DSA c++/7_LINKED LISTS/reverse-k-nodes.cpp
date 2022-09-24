//Program to reverse k nodes

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

node* reversek(node* &head, int k)
{
    node* prevptr=NULL;
    node* curr=head;
    node* nextptr;
    
    int count=0;
    
    while(curr!=NULL && count<k)
    {
        nextptr=curr->next;
        curr->next=prevptr;
        
        prevptr=curr;
        curr=nextptr;
        count++;
    }
    
    
    
    if(nextptr!=NULL)
    {
        head->next = reversek(nextptr,k);
    }
    
    return prevptr;
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
    
    cout<<"List before reversal:"<<endl;
    
    display(head);
    
    cout<<"List after reversal:"<<endl;
    
    //node* newhead=;
    
    node* y=reversek(head, 2);
    
    display(y);
    
}