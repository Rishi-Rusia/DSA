//Program for linked list reversal

#include <iostream>

using namespace std;

class node
{
    public:
    int data;
    node* next;
    
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
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    
    cout<<"NULL"<<endl;
}

node* reverse(node* &head)//iterative method to reverse a linked list
{
    node* prev=NULL;//previous pointer points at the previous element
    node* curr=head;//current pointer for current element
    node* nextptr;//next pointer for next element
    
    
    
    while(curr!=NULL)//The loop will end when the current pointer it NULL.
    {
        nextptr=curr->next;//pointing NEXT to CURRENT
        curr->next=prev;//Pointing CURRENT to PREVIOUS
        
        prev=curr;//SHIFTING CURRENT to PREVIOUS
        curr=nextptr;//SHIFTING NEXT to CURRENT
    }
    
    return prev;
}

node* recursiveReverse(node* &head)//recursive function to reverse linked list
{
    if(head==NULL || head->next==NULL )//base case 
    {
        return head;
    }
    
    node* newhead= recursiveReverse(head->next);//recursion call
    
    /*Since we are sending head->next in the recursion call
    we weill start reversig with the second last element*/
    
    head->next->next=head;//Turning the next pointer of the next element towards the head
    head->next=NULL;//Turning head of next to NULL
    
    return newhead;//returning NEW HEAD
}

int main()
{
    node a(5);
    
    node* p=&a;
    
    insertAtTail(p,2);
    insertAtTail(p,5);
    insertAtTail(p,6);
    insertAtTail(p,1);
    
    cout<<"The initial list: ";
    
    display(p);
    
    cout<<"Iterative reverse: ";
    
    p=reverse(p);
    
    display(p);
    
    cout<<"Recursive reverse: ";
    
    p=recursiveReverse(p);
    
    display(p);
}