#include <iostream>

using namespace std;

class node
{
  public:
  int data;//dara is the value that is contained in this node of the linked list
  node* next;//next is a pointer to a node object which will store the next element in the linked list
  
  node(int val)
  {
      data=val;
      next=NULL;
  }
};

void insertAtTail(node* &head, int val)//This function takes the node head and value and places it at the end of the linked list.
{
    node* n= new node(val);//creating a new node
    
    if(head==NULL)
    {
        //  here we check if head is equal to null or not
        //  if the head is null that means the list is empty
        //  in that case we enter the node we created 
        //  as the head of the list.
        
        head=n;
        return;
    }
    
    node* temp=head;
    
    while(temp->next != NULL)//Traversing the list till NULL is not found
    {
        temp=temp->next;//iterating
    }
    
    temp->next=n;//Assign the new node to the next element
}

void display(node* &head)
{
    node* temp=head;
    
    while(temp!=NULL)
    {
        cout<<(temp->data)<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}
    
void searchlist(node* head,int key)//Program to search in linked list
{
    node* temp=head;
    
    while((temp->next)!=NULL)
    {
        if(temp->data == key)
        {
            cout<<"\nElement is present in the list";
            return;
        }
        temp=temp->next;
    }
    
    cout<<"\nThe element was not found";
}

int main()
{
    node a(5);
    
    node* p=&a;
    
    insertAtTail(p,1);
    insertAtTail(p,2);
    insertAtTail(p,2);
      
      display(p);
      
      searchlist(p,4);
}