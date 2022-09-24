#include <iostream>

using namespace std;

class Stack
{
private:
    int data[10];
    int count = -1;

public:
    void isfull()
    {
        if (count >= 9)
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            cout << "Stack is not full" << endl;
        }
    }

    void isEmpty()
    {
        if (count == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Stack is not empty" << endl;
        }
    }

    void display()
    {
        for (int i = 0; i <= count; i++)
        {
            cout << data[i] << " ";
        }

        cout << endl;
    }

    void push(int val)
    {
        count++;
        data[count] = val;
    }

    void top()
    {
        cout << "The top element is" << data[count];
    }

    void pop()
    {
        count--;
    }
};

int main()
{
    Stack st;
    st.isEmpty();
    for (int i = 0; i < 10; i++)
    {
        st.push(i);
    }

    st.display();
    st.isfull();
    st.pop();

    st.display();
    st.isfull();
    st.isEmpty();
    st.top();
}