// Program throws segmentation error for one particular case only

#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            bool b1 = (s[i] == ')') && (st.top() == '(');
            bool b2 = (s[i] == ']') && (st.top() == '[');
            bool b3 = (s[i] == '}' && st.top() == '{');

            if (s[i] == '{' || s[i] == '(' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else if (b1 || b2 || b3)
            {
                st.pop();
            }
            else if ((s[i] == ']' || s[i] == '}' || s[i] == ')') && i == 0)
            {
                return false;
            }
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
    Solution sol;

    cout << sol.isValid("]");
}