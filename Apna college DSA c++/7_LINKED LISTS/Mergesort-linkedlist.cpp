/*This is the program to merge two sorted linked lists*/

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
    
  
    return l;
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

node* merge(node* &head1,node* head2)
{
    node* p1=head1;
    node* p2=head2;
    node* dummyNode=new node(-1);
    node* p3=dummyNode;
    
    while(p1!=NULL && p2!= NULL)
    {
        if(p1->data < p2->data)
        {
            p3->next=p1;
            p1=p1->next;
            p3=p3->next;
        }
        else
        {
            p3->next=p2;
            p2=p2->next;
            p3=p3->next;
        }
    }
    
    while(p1!=NULL)
    {
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
    while(p2!=NULL)
    {
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }
    
    return dummyNode->next;
}

/* node* mergeRecursive(node* head1,node* head2)
{
    node* result;
    if(head1==NULL && head2==NULL)
    {
        return result;
    }
    
    if(head1==NULL && head2 !=NULL)
    {
        return head2;
    }
    
    if(head2==NULL && head1 !=NULL)
    {
        return head1;
    }
    
        
    
    
    if(head1->data < head2->data)
    {
        result=head1;
        result->next=mergeRecursive(head1->next,head2);
    }
    else{
        result=head2;
        result->next =mergeRecursive(head1,head2->next);
    }
    
    return result;
} */

node *mergeRecursive(node *head1,node *head2)
{
	node* head=NULL;
	if(head1==NULL)
		return head2;
	if(head2==NULL)
		return head1;

	if(head1->data < head2->data)
	{
		head=head1;
		head->next=mergeRecursive(head1->next,head2);
	}	
	else
	{
		head=head2;
		head->next=mergeRecursive(head1,head2->next);
	}
	return head;
}

int main()
{
    node a(1);
    
    node*head1=&a;
    addAtTail(head1,2);
    addAtTail(head1,3);
    addAtTail(head1,4);
    addAtTail(head1,5);
    addAtTail(head1,6);
    
    cout<<"First List:"<<endl;
    
    display(head1);
    
    cout<<"Second List:"<<endl;
        
    node b(4);
    
    node* head2=&b;
    
    addAtTail(head2,6);
    addAtTail(head2,7);
    addAtTail(head2,8);
    addAtTail(head2,9);
    addAtTail(head2,10);
    
    display(head2);
    
    cout<<"List after merge sort through iterative method:"<<endl;
    
    node* newhead=merge(head1,head2);
    
    display(newhead);
    
    
   cout<<"List after mergesort through recursive method:"<<endl;
    
     
     
     node x(1);
    
    node* head11=&x;
    addAtTail(head11,2);
    addAtTail(head11,3);
    addAtTail(head11,4);
    addAtTail(head11,5);
    addAtTail(head11,6);
    
        
    node y(4);
    
    node* head22=&y;
    
    addAtTail(head22,6);
    addAtTail(head22,7);
    addAtTail(head22,8);
    addAtTail(head22,9);
    addAtTail(head22,10);
    
    node* newhead2=mergeRecursive(head11,head22);
    
   display(newhead2);
    
}