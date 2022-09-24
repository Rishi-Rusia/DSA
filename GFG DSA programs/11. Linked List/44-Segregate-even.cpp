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

node* segregate(node* head)
{
    node* temp=head;
    
    node* odd=NULL;
    node* even=NULL;
    node* oddhead;
    node* evenhead;
    int oddcount=0,evencount=0;
    
    while(temp!=NULL)
    {
        if(temp->data %2==0)
        {
            evencount++;
            if(evencount==1)
            {
                even=temp;
                evenhead=even;
                
            }
            else
            {
               even->next=temp;
            even=even->next; 
            }
            
            
            
        }
        else
        {
            oddcount++;
            
            if(oddcount==1)
            {
                
                odd=temp;
                oddhead=odd;
                
            }
            else
            {
                odd->next=temp;
            odd=odd->next;
            }
            
            
            
            
        }
        
        temp=temp->next;
    }
    
    if(oddcount==0)
    {
        even->next=NULL;
        
        return evenhead;
    }
    
    if(evencount==0)
    {
        odd->next=NULL;
        return oddhead;
    }
    
    even->next=oddhead;
    
    odd->next=NULL;
    
    return evenhead;
}

int main()
{
    node* head= new node(17);
    
    head->next= new node(15);
    
    head->next->next= new node(8);
    
    head->next->next->next= new node(12);
    
    head->next->next->next->next= new node(10);
    
    head->next->next->next->next->next= new node(5);
    
    head->next->next->next->next->next->next= new node(4);
    
    display(head);
    
    cout<<endl<<"Results after segregate are:"<<endl;
    
    head=segregate(head);
    
    display(head);
}
