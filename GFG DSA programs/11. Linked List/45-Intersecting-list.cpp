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

void display(node* head)
{
    node* temp=head;
    
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
}

void findIntersection(node* head1,node* head2)
{
    int c1=0,c2=0;
    
    node* temp1=head1;
    node* temp2=head2;
    while(1)
    {
        if(temp1==NULL && temp2==NULL)
        {
            break;
        }
        
        if(temp1!=NULL)
        {
            c1++;
            temp1=temp1->next;
        }
        
        if(temp2!=NULL)
        {
            c2++;
            temp2=temp2->next;
        }
    }   
    
    int diff;
    node* maxnode;
    node* minnode;
    
   if(c1>c2)
   {
       maxnode=head1;
       minnode=head2;
       diff=c1-c2;
   }
   else
   {
       maxnode=head2;
       minnode=head1;
       diff=c2-c1;
   }
   
    
    while(diff)
    {
        maxnode=maxnode->next;
        diff--;
    }
    
    while(maxnode!=NULL && minnode!=NULL)
    {
        if(maxnode==minnode)
        {
            cout<<endl<<"The list intersects at "<<maxnode->data;
            break;
        }
        
        maxnode=maxnode->next;
        minnode=minnode->next;
    }
    
}

int main()
{
    node* head= new node(17);
    
    head->next= new node(15);
    
    head->next->next= new node(8);
    
    head->next->next->next= new node(12);
    
    node* head2= new node(25);
    
    head2->next= head->next->next->next;
    
    head->next->next->next->next= new node(10);
    
    head->next->next->next->next->next= new node(5);
    
    head->next->next->next->next->next->next= new node(4);
    
    display(head);
    
    cout<<endl<<"The second list is:"<<endl;
    
    display(head2);
    
    findIntersection(head,head2);
    
}
