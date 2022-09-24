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
    node* temp= head;
    
    while(temp!=NULL)
    {
        cout<<temp->data;
        cout<<" ";
        
        temp=temp->next;
    }
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

void deletion(node* head, int pos)
{
    node* temp=head;
    int count=0;
    int flag=0;
    
    while(temp!=NULL)
    {
        if(count==pos-1 && temp->next!=NULL)
        {
            flag=1;
            break;
        }
        count++;
        temp=temp->next;
    }
    
    if(flag==0)
    {
        cout<<"Invalid input"<<endl;
        return;
    }
    
    node* todelete= temp->next;
    temp->next=temp->next->next;
    
    delete todelete;
}

void insertAt(node* head, int pos,int val)
{
    node* temp=head;
    int count=0;
    int flag=0;
    
    while(temp!=NULL)
    {
        if(count==pos-1 && temp->next !=NULL)
        {
            flag=1;
            break;
        }
        temp=temp->next;
        count++;
    }
    
    node* insertednode= new node(val);
    
    insertednode->next= temp->next;
    temp->next=insertednode;
}

node* insertAtHead(node* head,int val)
{
    node* newhead= new node(val);
    newhead->next=head;
    
    return newhead;
}

node* deleteAtHead(node* head)
{
    node* newhead= head->next;
    delete head;
    return newhead;
    
}

void recursiveDisplay(node* head)
{
    if(head ==NULL)
    {
        return;
    }
    
    cout<<head->data<<" ";
    recursiveDisplay(head->next);
}

void recursiveSearch(node* head,int val)
{
    if(head->data==val)
    {
        cout<<"Element present in list ";
        return;
    }
    if(head->next == NULL)
    {
        cout<<"Element not present in list";
        return;
    }
    
    
    recursiveSearch(head->next, val);
}



int main()
{
    node* head= new node(1);
    
   for(int i=2;i<5;i++)
   {
       insertion(head,i);
   }
    cout<<"The current list is:"<<endl;
    display(head);
    while(1)
    {
        cout<<endl<<"1.Insert element\n2.Delete Element\n3.display Elements\n4.search Elements\nEnter the choice:\n";
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout<<"Enter the value to be inserted"<<endl;
            int val;
            cin>>val;
            insertion(head, val);
            break;
            
            case 2:
            cout<<"Enter the position"<<endl;
            int dval;
            cin>>dval;
            deletion(head, dval);
            break;
            case 3:
            cout<< "Here are the elements:";
            display(head);
            break;
            case 4:
            cout<<"Enter the value of the the element to be searched";
            int searchval;
            cin>>searchval;
            recursiveSearch(head,searchval);
            
            cout<<endl<<endl<<endl;
        }
    }
     
}