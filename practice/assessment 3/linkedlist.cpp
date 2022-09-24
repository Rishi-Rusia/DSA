#include <iostream>

using namespace std;

class node{
    public:
  int data;
  node* next;
  
  node(int val)
  {
      data= val;
      next=NULL;
  }
};

void display(node*head)
{
    node* temp=head;
    
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main()
{
    node* head= new node(1);
    head->next= new node(2);
    head->next->next= new node(3);
    
    
    
    display(head);
    
}