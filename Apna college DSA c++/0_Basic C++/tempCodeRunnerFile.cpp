#include <stack>
#include <iostream>

using namespace std;

#include <stack>

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        int i = 0;
        for (int i = 0; i < s.length(); i++)
        {

            if (s[i] == '{' || s[i] == '(' || s[i] == '[')
            {
                st.push(st.top());
            }

            if ((s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '[') || (s[i] == '}' && st.top() == '{'))
            {
                st.pop();
            }

            i++;
        }

        if (st.empty())
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
    Solution s;
    cout << s.isValid("()");
}