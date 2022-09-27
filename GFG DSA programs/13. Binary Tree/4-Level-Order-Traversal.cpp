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

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return max(height(root->left), height(root->right)) + 1;
    }
}

// FUNCTION WITH HIGHER AUXILLARY SPACE and TIME COMPLEXITY
//
//
//  void leverOrder(node *root)
//  {
//      queue<node *> q;

//     int n = height(root);

//     q.push(root);

//     for (int i = 1; i <= n; i++)
//     {
//         queue<node *> q2;
//         while (q.empty() == false)
//         {
//             node *p = q.front();

//             q.pop();

//             if (p->left != NULL)
//             {
//                 q2.push(p->left);
//             }
//             if (p->right != NULL)
//             {
//                 q2.push(p->right);
//             }

//             cout << p->data << " ";
//         }

//         q = q2;
//     }
// }

// OPTIMIZED FUNCTION

void leverOrder(node *root)
{
    queue<node *> q;

    int n = height(root);

    q.push(root);

    while (q.empty() == false)
    {
        node *p = q.front();

        q.pop();

        if (p->left != NULL)
        {
            q.push(p->left);
        }
        if (p->right != NULL)
        {
            q.push(p->right);
        }

        cout << p->data << " ";
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

    leverOrder(root);
}