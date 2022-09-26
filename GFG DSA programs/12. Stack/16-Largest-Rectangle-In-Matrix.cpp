// Largest rectangle in a matrix of ones and zeroes.

#include <iostream>
#include <stack>

using namespace std;

int histogram(int a[], int n)
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

int rectangle(int a[][5], int R, int C)
{
    int res = histogram(a[0], C);

    for (int i = 1; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (a[i][j] == 1)
            {
                a[i][j] = a[i][j] + a[i - 1][j];
            }
        }

        res = max(res, histogram(a[i], C));
    }

    return res;
}

int main()
{
    int arr[4][5] = {{1, 0, 0, 1, 1}, {0, 0, 0, 1, 1}, {1, 1, 1, 1, 1}, {0, 1, 1, 1, 1}};

    cout << rectangle(arr, 4, 5);
}