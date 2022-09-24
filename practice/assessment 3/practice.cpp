#include <iostream >

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

node* reverseRecursive(node* head)
{
     
   if(head->next==NULL)
   {
        return head;
   }

   node* newhead= reverseRecursive(head->next);

    head->next->next= head;
    head->next=NULL;

    return newhead;
    
}

node* reverse(node* head)
{
    node* curr;
    node* prev=NULL;
    node* nex;

    while(curr!=NULL)
    {
        nex=curr->next;
        curr->next=prev;
        
        prev=curr;
        curr=nex;
    }

    return prev;
}

void insertion(node* head,int value)
{
    node* temp= head;
    
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    
    temp->next= new node(value);
    
}

void display(node* head)
{
    node* temp= head;
    
    while(temp!=NULL)
    {
        cout<<temp->data;
        cout<<" ";
        
        temp=temp->next;
    }
}

int main()
{
    node* head= new node(1);
    
   for(int i=2;i<5;i++)
   {
       insertion(head,i);
   }

   cout<<"Elements before reversal are:"<<endl;
   display(head);
   cout<<"\nElements after reversal are:"<<endl;
//    head = reverseRecursive(head);
//    display(head);
   head = reverse(head);
   display(head);
}