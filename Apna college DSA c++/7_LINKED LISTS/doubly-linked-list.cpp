//Program for doubly linked lists

#include <iostream>

using namespace std;


//node class for a doubly linked list
class node{
    public:
  int data;
  node* next;
  node* prev;
  
  node(int val)
  {
    data=val;
    next=NULL;
    prev=NULL;
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

void insertAtHead(node* head,int val)
{
    node* n= new node(val);

    n->next= head;
    if(head!=NULL)
    {
        head->prev=n;
    }

    head =n;
}

void addAtTail(node* &head,int val)
{
    node* n= new node(val);
    
    if(head==NULL)
    {
        insertAtHead(head,val);
        return;
    }
    node* temp=head;
    
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    
    temp->next=n;
    n->prev=temp;
}


int main()
{
    //node a(5);
    
    node *head=NULL;
    addAtTail(head,1);
    addAtTail(head,2);
    addAtTail(head,3);
    addAtTail(head,4);
    addAtTail(head,6);
    addAtTail(head,6);
    
    cout<<"List entered:"<<endl;
    
    display(head);
    
     cout<<"List after insertAtHead:"<<endl;
     
     insertAtHead(head,3);
    
    display(head);
    
    
    
}