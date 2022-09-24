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
    
    while(temp->next != NULL)
    {
        temp=temp->next;
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
    
void searchlist(node* head,int key)
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

void deletelist(node* &head,int val)//function to delete list
{
    node* temp=head;//temporary variable
    
    while(temp->next->data != val)//finding the node before the node to be deleted
    {
        temp=temp->next;//iterating
    }
    
    node* todelete= temp->next;//assigning the deletion node to todelete variable
    
    temp->next=temp->next->next;//changing the link of n-1 and pointing it to n+1
    
    delete todelete;
}

void deleteAtHead(node* &head)//function to delete head
{
    node* todelete= head;//storing the head node
    head= head->next;//assigning a new head to the list
    
    delete todelete;//deleting head
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
      
      deletelist(p,2);
      
      cout<<endl;
      
      display(p);
      
      cout<<endl;
      
      cout<<"Head deletion:"<<endl;
      
      deleteAtHead(p);
      
      display(p);
      
}