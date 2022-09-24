#include <iostream>

using namespace std;

class node{
  public:
  
  int data;
  node* next;
  node* random;
  
  node(int val)
  {
      data=val;
      next= NULL;
      random=NULL;
  }
};

void insert(node* head,int val)
{
    node* temp=head;
    
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    
    temp->next= new node(val);
}

node* merge(node* head,node* head2)
{
    node* temp1=head;
    node* temp2=head2;
    
    node* newhead;
    
    node* returninghead;
    
    if(temp1->data<temp2->data)
    {
        newhead=temp1;
        temp1=temp1->next;
    }
    else
    {
        newhead=temp2;
        temp2=temp2->next;
    }
    
    returninghead=newhead;
   
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data<temp2->data)
        {
            newhead->next=temp1;
            temp1=temp1->next;
        }
        else
        {
            newhead->next= temp2;
            temp2=temp2->next;
        }
        
        newhead=newhead->next;
    }
    
   while(temp1!=NULL  )
   {
       newhead->next=temp1;
       newhead=newhead->next;
       temp1=temp1->next;
   }
   
   while(temp2!=NULL)
   {
       newhead->next=temp2;
       newhead=newhead->next;
       temp2=temp2->next;
   }
   
    return returninghead;
}

void display(node* head)
{
    node* temp=head;
    
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
    cout<<endl;
}

int main()
{
    node* head=new node(1);
    node* head2=new node(2);

    for(int i=3;i<=10;i++)
    {
        if(i%2==0)
        {
                    insert(head2,i);

        }
        else
        {
                    insert(head,i);

        }
        
    }
    
    display(head);
    display(head2);
    
    node* disphead= merge(head,head2);
    display(disphead);
}