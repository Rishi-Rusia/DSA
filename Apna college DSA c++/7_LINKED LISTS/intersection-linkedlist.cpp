/*This is the program to find the intersection point of two linked lists*/

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

int intersection(node* &head1, node* &head2)//THIS IS A FUNCTION TO CHECK FOR INTERSECTION IN THE LINKED LIST
{
    int l1=length(head1);//Getting the length of the first list
    int l2=length(head1);//Getting the length of the second list
    
    int d=0;//D is the difference between the lists
    
    node* ptr1;
    node* ptr2;
    
    if(l1>l2)//checking for the bigger list. The bigger list will be store in ptr1 and smaller in ptr2.
    {
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else
    {
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
        
    }
    
    while(d--)
    {
        /*This loop will get us the position where ptr 1 and ptr 2 have the same number of elements
        Remaning to be traversed.*/
        ptr1=ptr1->next;
        
        if(ptr1==NULL)
        {
          return -1;//if the list ends, there was no intersection
        }
        //d--;
    }
    
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1==ptr2)//checking for the intersection by comparing elements
        {
            return ptr1->data;//returning the data at which the list is connected to another
        }
        
        ptr1=ptr1->next;//""
        ptr2=ptr2->next;//ITERATING
    }
    
    return -1;
}

void intersect(node* head1,node* head2,int pos)//FUNCTION TO INTERSECT THE TWO LISTS
{
    node* temp1=head1;
    pos--;
    
    while(pos--)
    {
        temp1=temp1->next;
    }
    node* temp2=head2;
    
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    
    temp2->next=temp1;
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
        
    node b(9);
    
    node* head2=&b;
    
    addAtTail(head2,10);
    addAtTail(head2,10);
    
    intersect(head1,head2,4);
    
    display(head2);
    
    
    cout<<"Intersection point:"<<intersection(head1,head2);
    
}