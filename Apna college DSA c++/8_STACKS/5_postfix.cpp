#include <iostream>
#include <stack>

using namespace std;

int prefix(string s)
{
    stack<int> st;
    int op1,op2;
   for(int i=0;i<=s.length()-1;i++)
   {
       if(s[i]>='0' && s[i]<='9')
       {
           st.push(s[i]-'0');
       }
       else{
           
           op2=st.top();
           st.pop();
           op1=st.top();
           st.pop();
           switch(s[i])
           {
               case '+':
               st.push(op1+op2);
               break;
               
               case '-':
               st.push(op1-op2);
               break;
               
               case '*':
               st.push(op1*op2);
               break;
               
               case '/':
               st.push(op1/op2);
               break;
           }
       }
   }
   
   return st.top();
}


int main()
{
    cout<<prefix("46+2/5*7+");
}
