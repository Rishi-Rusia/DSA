#include <iostream>
#include <stack>

using namespace std;

void reverse(string s)
{
    stack<string> st;
    
    string word="";
    
    for(int i=0;i<s.length();i++)
    {
        while(s[i]!=' ' && i<s.length())
        {
            word=word+s[i];
            i++;
        }
        
        word=word+" ";
        st.push(word);
        word="";
    }
    
    while(st.empty() != true)
    {
        cout<<st.top();
        st.pop();
    }
    
}


int main()
{
    reverse("My name is Rishi Rusia.");
}