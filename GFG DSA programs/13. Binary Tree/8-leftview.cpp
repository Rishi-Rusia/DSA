#include <iostream>
#include <queue>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void leftview(node *root)
{
    queue<node *> q;

    q.push(NULL);
    q.push(root);

    while (q.empty() == false)
    {
        node *p = q.front();
        q.pop();

        if (p == NULL && q.empty() == false)
        {
            cout << q.front()->data << " ";
            p = q.front();
            q.pop();
            q.push(NULL);
        }

        if (p != NULL && p->left != NULL)
        {
            q.push(p->left);
        }

        if (p != NULL && p->right != NULL)
        {
            q.push(p->right);
        }
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    leftview(root);
}