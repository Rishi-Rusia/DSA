// previous greater element

#include <iostream>
#include <stack>

using namespace std;

void pge(int a[], int n)
{
    stack<int> st;

    st.push(0);

    cout << -1 << ' ';

    for (int i = 1; i < n; i++)
    {
        while (st.empty() == false && a[st.top()] <= a[i])
        {
            st.pop();
        }

        if (st.empty() == true)
        {
            cout << -1 << " ";
        }
        else
        {
            cout << a[st.top()] << " ";
        }

        st.push(i);
    }
}

int main()
{
    int a[] = {15, 10, 18, 12, 4, 6, 2, 8};

    pge(a, 8);
}