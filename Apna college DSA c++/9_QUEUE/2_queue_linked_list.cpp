#include <bits/stdc++.h>

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

class Queue
{
  public:
  node* front=NULL;
  node* back=NULL;
  
  void push(int x)
  {
      node* n=new node(x);
      
      if(front==NULL)
      {
          back=n;
          front=n;
          return;
      }
      back->next=n;
      back=n;
  }
  
  void pop()
  {
      if(front==NULL)
      {
          cout<<"Queue Underflow";
          return;
      }
      
      node* todelete=front;
      front=front->next;
      delete todelete;
  }
  
  int peek()
  {
      if(front==NULL)
      {
          cout<<"Queue Underflow";
          return -1;
      }
      
      return front->data;
  }
  
  bool empty()
  {
      if(front==NULL)
      {
          return true;
      }
      else
      {
          return false;
      }
  }
  
  
};

int main()
{
    Queue q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.empty()<<endl;
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.empty()<<endl;
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.empty()<<endl;
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.empty()<<endl;
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.empty()<<endl;
    
}