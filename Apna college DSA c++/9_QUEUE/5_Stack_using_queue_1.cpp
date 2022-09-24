#include <iostream>
#include <queue>

using namespace std;

class Stack
{ 
    public:
    queue<int> q1;
    queue<int> q2;
    int N;
    
    Stack()
  {
     N=0;
  }
  
  void push(int x)
  {
      N++;
      
      q2.push(x);//Add an element to empty queue first
      
      while(!q1.empty())
      {
          q2.push(q1.front());//Add other elements behind it
          q1.pop();
      }
      
      queue<int> temp=q1;//swap
      q1=q2;
      q2=temp;//now the element that will be popped first will be the element which was inserted last
  }
  
  int pop()
  {
      int val=q2.front();
      q2.pop();
      N--;
      return val;
  }
  
  bool empty()
  {
     if(N>0)
     {
         return false;
     }
     else
     {
         return true;
     }
  }
};

int main()
{
    Stack q;
    q.push(1);
    q.push(2);
    q.push(3);
    
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.empty()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.empty()<<endl;
}