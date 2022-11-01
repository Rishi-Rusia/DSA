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

// bool childsum(node *root)
// {
//     if (root == NULL || (root->left == NULL && root->right == NULL))
//     {
//         return true;
//     }

//     if (root->right == NULL)
//     {
//         return false;
//     }

//     if (root->left == NULL)
//     {
//         return false;
//     }

//     if (childsum(root->left) && childsum(root->right) && (root->data == (root->left->data + root->right->data)))
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

int childsum(node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }

    if (root->right == NULL || root->left == NULL)
    {
        return 0;
    }

    if (root->data == childsum(root->left) + childsum(root->right))
    {
        return root->data;
    }
    else
    {
        return -1;
    }
}

int main()
{
    // node *root = new node(1);
    // root->left = new node(2);
    // root->right = new node(3);
    // root->left->left = new node(4);
    // root->left->right = new node(5);
    // root->right->left = new node(6);
    // root->right->right = new node(7);

    node *root = new node(3);
    root->left = new node(1);
    root->right = new node(2);
    root->right->left = new node(1);
    root->right->right = new node(1);

    cout << childsum(root);
}