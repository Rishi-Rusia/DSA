#include <iostream>
#include <bits/stdc++.h>

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

node *insertBST(node *root, int n)
{
    if (root == NULL)
    {
        node *newnode = new node(n);
        root = newnode;
        return root;
    }

    if (n > root->data)
    {
        root->right = insertBST(root->right, n);
    }

    if (n < root->data)
    {
        root->left = insertBST(root->left, n);
    }

    return root;
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// node *floorBST(node *root, int key)
// {
//     if (root == NULL)
//     {
//         return root;
//     }

//     node *small;

//     small->data = 0;

//     while (root != NULL)
//     {
//         if (root->data > small->data && root->data <= key)
//         {
//             small->data = root->data;
//         }

//         if (key < root->data)
//         {
//             root = root->left;
//         }
//         else if (key > root->data)
//         {
//             root = root->right;
//         }
//         else
//         {
//             return root;
//         }
//     }

//     return small;
// }

node *floorBST(node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    node *res;

    while (root != NULL)
    {
        if (root->data == key)
        {
            return root;
        }
        else if (root->data > key)
        {

            root = root->left;
        }
        else
        {
            res = root;
            root = root->right;
        }
    }

    return res;
}

int main()
{
    node *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    // insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    insertBST(root, 6);

    inorder(root);
    cout << endl;
    cout << floorBST(root, 7)->data;
    cout << endl;
    cout << floorBST(root, 4)->data;
}