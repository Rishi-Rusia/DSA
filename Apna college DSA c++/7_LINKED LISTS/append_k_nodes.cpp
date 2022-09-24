/*This is the program to append k nodes in a linked list

Basically appending k nodes means taking "k" nodes from the end of the list
and putting them to the beginning of the list.*/

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

int length(node* &head)//FUNCTION TO FIND LENGTH
{
    int l=0;
    node* temp=head;
    
    while(temp!=NULL)
    {
        temp=temp->next;
        l++;
        
        /*Traverse the list till null is found, count the iterations to get the length*/
    }
    
    cout<<"The length of the linked list is="<<l<<endl;
    
    return l;
}

node* appendk(node* &head,int k)//FUNCTION TO APPEND K NODES
{
    node* temp=head;//temporary node
    
    int l=length(head);//length
    
    int count=1;//to find position
    
    if(k>l)//for the case in which k > l
    {
        k=k%l;
    }
    
    node* newhead;
    node* newtail;
    node* tail=head;//initializing tail with head to find the new terminating node
    
    while(tail->next!=NULL)//loop to find the new terminating node
    {
        if(count==l-k)
        {
            newtail=tail;//Finding the new terminating point
        }
        
        if(count==l-k+1)
        {
            newhead=tail;//finding the new starting point
        }
        
        tail=tail->next;//iterating
         count++;//incrementing
    }
    
    newtail->next=NULL;//Pointing new terminating node to NULL
    tail->next=head;//pointing previous terminating node to head
    
    return newhead;
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
    
    node* newhead= appendk(head,2);
    
    display(newhead);
    display(head);
  
    
}