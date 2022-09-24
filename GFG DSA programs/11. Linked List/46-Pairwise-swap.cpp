#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void display(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

node *insert(node *head, int val)
{
    if (head == NULL)
    {
        head = new node(val);
        return head;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new node(val);
    return head;
}

node *pairswap(node *head)
{

    node *temp = head;

    int count = 0;
    node *newhead;
    node *prev;
    while (temp != NULL && temp->next != NULL)
    {
        node *store;

        store = temp->next;
        temp->next = temp->next->next;
        store->next = temp;

        count++;

        if (count > 1)
        {
            prev->next = store;
        }
        if (count == 1)
        {
            newhead = store;
        }

        prev = temp;
        temp = temp->next;
    }

    return newhead;
}

int main()
{

    node *head;

    for (int i = 1; i < 10; i++)
    {
        head = insert(head, i);
    }

    display(head);
    head = pairswap(head);
    cout << endl
         << "The output after swapping is:" << endl;
    display(head);
}
