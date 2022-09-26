#include <iostream>
#include <stack>

using namespace std;

int rectangle(int a[], int n)
{
    stack<int> st;

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        while (st.empty() == false && a[st.top()] > a[i])
        {
            int tp = st.top();
            st.pop();
            int curr = a[tp] * (st.empty() ? i : (i - st.top() - 1));
            res = max(res, curr);
        }

        st.push(i);
    }

    while (st.empty() == false)
    {
        int tp = st.top();
        st.pop();
        int curr = a[tp] * (st.empty() ? n : (n - tp));
        res = max(res, curr);
    }

    return res;
}

int main()
{
    int arr[] = {2, 4};

    cout << rectangle(arr, 2);
}