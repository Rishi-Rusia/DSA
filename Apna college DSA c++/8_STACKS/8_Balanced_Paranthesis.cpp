#include <iostream>
#include <stack>

using namespace std;

bool Balanced(string s)
{
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='{' || s[i]=='[' || s[i]=='(')
        {
            st.push(s[i]);
            cout<<s[i]<<endl;
        }
        else if(s[i]=='}' || s[i]==']' || s[i]==')')
        {
            cout<<s[i]<<endl;
            if(s[i]=='}' && st.top()=='{')
            {
                st.pop();
            }
            else if(s[i]==']' && st.top()=='[')
            {
                st.pop();
            }
            else if(s[i]==')' && st.top()=='(')
            {
                st.pop();
                
            }
            else
            {
                return false;
            }
            
        }
        else
        {
            continue;
        }
    }
    
    return true;
}

int main()
{
    cout<<Balanced("{[()]}");
}