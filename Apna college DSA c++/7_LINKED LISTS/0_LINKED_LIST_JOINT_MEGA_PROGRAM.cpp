//Make and display a linked list

#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int val)
    {
        data= val;
        next=NULL;
    }
};

void addToTail(Node* head, int val)
{
    Node* temp=head;
    
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    
    temp->next= new Node(val);
    return;
    
}


void displayList(Node* head)
{
    Node* temp=head;
    
    while(temp!=NULL)
    {
        
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }
    
    cout<<"NULL";
}

void deleteAtHead(Node* head)//function to delete Node at head
{
    Node* deleteNode= head->next;
    head->data= head->next->data;
    head->next= head->next->next;
    delete(deleteNode);
    
}

void deletion(Node* head, int index)//function for deletion in linked list
{
    if(head==NULL)
    {
        cout<<"NuLL head, no deletion possible";
        return;
    }
    
    if(index==0)
    {
        deleteAtHead(head);
        return;
    }
    
    int counter= 0;
    bool flag = false; 
    
    Node* temp= head;
    
    while(temp->next != NULL)
    {
        counter++;
        temp= temp->next;
        
        if(counter==index-1)
        {
            break;
        }
    }
    
    Node* deleteNode=temp->next; 
    temp->next = temp->next->next;
    
    delete(deleteNode);
}

Node* reverseListIterative(Node* head)//Iterative Method to reverse a linked list
{
    Node* temp= head;
    Node* prev=NULL;
    Node* curr=temp; 
    Node* last;
    
    while(curr!= NULL)
    {
        last=curr->next;
        curr->next= prev;
        prev=curr;
        curr=last;
        
        
    }
    
    return prev;
}

Node* reverseListRecursive(Node* &head)//recursive function to reverse a linked list
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node* newhead= reverseListRecursive(head->next);
    head->next->next= head;
    head->next= NULL;
    
    return newhead;
}

Node* reversek(Node* &head, int k)//Function to reverse k nodes
{
    Node* prev= NULL;
    Node* curr= head;
    Node* next;
    
    int count= 0;
    
    if(head->next==NULL)
    {
        return head;
    }
    
    while(count<k)
    {
        next= curr->next;
        curr->next= prev;
        
        prev= curr;
        curr=next;
        count++;
    }
    
    if(next!= NULL)
    {
        head->next= reversek(next, k);
    }
    
    return prev;
}

void addCycle(Node* head, int index)//function to add cycle to a linked list
{
    int count=0;
    
    Node* storage;
    
    Node* temp= head;
    
    
    while(temp->next != NULL)
    {
        if(count==index)
        {
            storage= temp;
        }
        
        temp=temp->next;
        count++;
    }
    
    temp->next=storage;
}

bool detectCycle(Node* head)//function to detect cycle;
{
    Node* slow= head, *fast= head;
    
    
    while(fast!= NULL && fast->next!=NULL)
    {
        slow= slow->next;
        fast= fast->next->next;
        
        if(slow==fast)
        {
            return true;
        }
    }
    
    return false;
}

void removeCycle(Node* head)
{
    Node* slow= head, *fast= head;
    
    Node* flag=NULL;
    
    
    while(fast!= NULL && fast->next!=NULL)
    {
        
        
        if(slow->next==fast->next->next)
        {
            flag=slow;
            break;
        }
        
        slow= slow->next;
        fast= fast->next->next;
    }
    
    if(flag == NULL)
    {
        cout<<"There are no cycles in this list lol"<<endl;
        
        return;
    }
    
    slow=head;
    
    while(1)
    {
        slow=slow->next;
        if(slow->next==flag)
        {
            slow->next=NULL;
            cout<<"Cycle removal successful"<<endl;
            return;
        }
    }
}

int main()
{
    Node* head= new Node(1);
    
    addToTail(head,2);
    addToTail(head,3);
    addToTail(head,4);
    addToTail(head,5);
    
    displayList(head);
    
    cout<<endl<<"The linked list after deletion will be:"<<endl;
    
    deletion(head, 2);
    
    displayList(head);
    
    cout<<endl<<"Trying to invoke the deleteAtHead function:"<<endl;
    
    deletion(head, 0);
    
    displayList(head);
    
    cout<<endl<<"Function to reverse a linked list (Iterative):"<<endl;
    
    Node* newhead= reverseListIterative(head);
    
    displayList(newhead);
    
    cout<<endl<<"Reverse Recursive function: "<<endl;
    
    Node* newhead2= reverseListRecursive(newhead);
    
    displayList(newhead2);
    
    cout<<endl<<"Reverse k nodes function: "<<endl;
    
    Node* head2= new Node(1);
    
    addToTail(head2,2);
    addToTail(head2,3);
    addToTail(head2,4);
    addToTail(head2,5);
    addToTail(head2,6);
    
    Node* newhead3= reversek(head2,2);
    
    displayList(newhead3);
    
    cout<<endl<<"Hare and tortoise algorithm \n /Cycle creation and removal in linked list:"<<endl;
    
    addCycle(newhead3,3);
    
    
    if(detectCycle(newhead3)==true)
    {
        cout<<"Cycle detected"<<endl;
    }
    else
    {
        cout<<endl<<"No cycle present in the list"<<endl;
    }
    
    cout<<endl<<"Testing function for cycle removal:"<<endl;
    
    removeCycle(newhead3);
    
    if(detectCycle(newhead3)==true)
    {
        cout<<"Cycle detected"<<endl;
    }
    else
    {
        cout<<endl<<"No cycle present in the list"<<endl;
    }
}

//Make and display a linked list

#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int val)
    {
        data= val;
        next=NULL;
    }
};

void addToTail(Node* head, int val)
{
    Node* temp=head;
    
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    
    temp->next= new Node(val);
    return;
    
}


void displayList(Node* head)
{
    Node* temp=head;
    
    while(temp!=NULL)
    {
        
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }
    
    cout<<"NULL";
}

void deleteAtHead(Node* head)//function to delete Node at head
{
    Node* deleteNode= head->next;
    head->data= head->next->data;
    head->next= head->next->next;
    delete(deleteNode);
    
}

void deletion(Node* head, int index)//function for deletion in linked list
{
    if(head==NULL)
    {
        cout<<"NuLL head, no deletion possible";
        return;
    }
    
    if(index==0)
    {
        deleteAtHead(head);
        return;
    }
    
    int counter= 0;
    bool flag = false; 
    
    Node* temp= head;
    
    while(temp->next != NULL)
    {
        counter++;
        temp= temp->next;
        
        if(counter==index-1)
        {
            break;
        }
    }
    
    Node* deleteNode=temp->next; 
    temp->next = temp->next->next;
    
    delete(deleteNode);
}

Node* reverseListIterative(Node* head)//Iterative Method to reverse a linked list
{
    Node* temp= head;
    Node* prev=NULL;
    Node* curr=temp; 
    Node* last;
    
    while(curr!= NULL)
    {
        last=curr->next;
        curr->next= prev;
        prev=curr;
        curr=last;
        
        
    }
    
    return prev;
}

Node* reverseListRecursive(Node* &head)//recursive function to reverse a linked list
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node* newhead= reverseListRecursive(head->next);
    head->next->next= head;
    head->next= NULL;
    
    return newhead;
}

Node* reversek(Node* &head, int k)//Function to reverse k nodes
{
    Node* prev= NULL;
    Node* curr= head;
    Node* next;
    
    int count= 0;
    
    if(head->next==NULL)
    {
        return head;
    }
    
    while(count<k)
    {
        next= curr->next;
        curr->next= prev;
        
        prev= curr;
        curr=next;
        count++;
    }
    
    if(next!= NULL)
    {
        head->next= reversek(next, k);
    }
    
    return prev;
}

void addCycle(Node* head, int index)//function to add cycle to a linked list
{
    int count=0;
    
    Node* storage;
    
    Node* temp= head;
    
    
    while(temp->next != NULL)
    {
        if(count==index)
        {
            storage= temp;
        }
        
        temp=temp->next;
        count++;
    }
    
    temp->next=storage;
}

bool detectCycle(Node* head)//function to detect cycle;
{
    Node* slow= head, *fast= head;
    
    
    while(fast!= NULL && fast->next!=NULL)
    {
        slow= slow->next;
        fast= fast->next->next;
        
        if(slow==fast)
        {
            return true;
        }
    }
    
    return false;
}

void removeCycle(Node* head)
{
    Node* slow= head, *fast= head;
    
    Node* flag=NULL;
    
    
    while(fast!= NULL && fast->next!=NULL)
    {
        
        
        if(slow->next==fast->next->next)
        {
            flag=slow;
            break;
        }
        
        slow= slow->next;
        fast= fast->next->next;
    }
    
    if(flag == NULL)
    {
        cout<<"There are no cycles in this list lol"<<endl;
        
        return;
    }
    
    slow=head;
    
    while(1)
    {
        slow=slow->next;
        if(slow->next==flag)
        {
            slow->next=NULL;
            cout<<"Cycle removal successful"<<endl;
            return;
        }
    }
}

Node* appendk(Node* head, int index)
{
    int count= 0;
    Node* flag= NULL;
    Node* temp=head;
    
    while(temp->next != NULL)
    {
        if(count==index)
        {
            flag= temp->next;
            temp->next=NULL;
            cout<<"count equal index"<<endl;
            break;
        }
        
        count++;
        temp= temp->next;
    }
    
    if(flag==NULL)
    {
        cout<<"The list is too short for the index"<<endl;
        return head;
    }
    
    Node* newhead= flag;
    
    while(1)
    {
        flag=flag->next;
        
        if(flag->next==NULL)
        {
            break;
        }
    }
    
    flag->next =head;
    
    return newhead;
}

int main()
{
    Node* head= new Node(1);
    
    addToTail(head,2);
    addToTail(head,3);
    addToTail(head,4);
    addToTail(head,5);
    
    displayList(head);
    
    cout<<endl<<"The linked list after deletion will be:"<<endl;
    
    deletion(head, 2);
    
    displayList(head);
    
    cout<<endl<<"Trying to invoke the deleteAtHead function:"<<endl;
    
    deletion(head, 0);
    
    displayList(head);
    
    cout<<endl<<"Function to reverse a linked list (Iterative):"<<endl;
    
    Node* newhead= reverseListIterative(head);
    
    displayList(newhead);
    
    cout<<endl<<"Reverse Recursive function: "<<endl;
    
    Node* newhead2= reverseListRecursive(newhead);
    
    displayList(newhead2);
    
    cout<<endl<<"Reverse k nodes function: "<<endl;
    
    Node* head2= new Node(1);
    
    addToTail(head2,2);
    addToTail(head2,3);
    addToTail(head2,4);
    addToTail(head2,5);
    addToTail(head2,6);
    
    Node* newhead3= reversek(head2,2);
    
    displayList(newhead3);
    
    cout<<endl<<"Hare and tortoise algorithm \n /Cycle creation and removal in linked list:"<<endl;
    
    addCycle(newhead3,3);
    
    
    if(detectCycle(newhead3)==true)
    {
        cout<<"Cycle detected"<<endl;
    }
    else
    {
        cout<<endl<<"No cycle present in the list"<<endl;
    }
    
    cout<<endl<<"Testing function for cycle removal:"<<endl;
    
    removeCycle(newhead3);
    
    if(detectCycle(newhead3)==true)
    {
        cout<<"Cycle detected"<<endl;
    }
    else
    {
        cout<<endl<<"No cycle present in the list"<<endl;
    }
    
    cout<<endl<<"Testing the appendk program:"<<endl;
    
    cout<<"Before Appending:";
    Node* newhead5=reverseListRecursive(newhead3);
    addToTail(newhead5,3);
    addToTail(newhead5,4);
    
    displayList(newhead5);
    cout<<endl<<"List after appending:";
    Node* newhead4=appendk(newhead5,1);
    
    displayList(newhead4);
}

