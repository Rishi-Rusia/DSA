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

int maxwidth(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    queue<node *> q;

    q.push(root);
    q.push(NULL);

    int res = 0;
    int counter = 0;

    while (q.empty() == false)
    {
        node *p = q.front();

        q.pop();

        if (p == NULL && q.empty() == false)
        {
            res = max(counter, res);
            counter = 0;
            p = q.front();
            q.pop();
            q.push(NULL);
        }

        if (p != NULL && p->left != NULL)
        {
            q.push(p->left);
            counter++;
        }

        if (p != NULL && p->right != NULL)
        {
            q.push(p->right);
            counter++;
        }
    }

    return res;
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

    cout << maxwidth(root);
}