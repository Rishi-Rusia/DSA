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
            
      q1.push(x);//Add an element to empty queue first

      
  }
  
  int pop()
  {
      if(N<=0)
      {
          cout<<"Empty queue\n";
          return -1;
      }
      int temp=N;
      while(!(temp==1))
      {
          q2.push(q1.front());
          q1.pop();
          temp--;
      }
      N--;
      int popele=q1.front();
      q1.pop();
      
      queue<int> tempq=q1;//swap
      q1=q2;
      q2=tempq;//now the element that will be popped first will be the element which was inserted last
      
      return popele;
  
      
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
    
    cout<<q.pop()<<endl;
    
}