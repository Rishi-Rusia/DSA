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

node *inordersucc(node *root)
{
    root = root->right;

    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

node *deleteBST(node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->data > key)
    {
        root->left = deleteBST(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = deleteBST(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            delete (root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete (root);
            return temp;
        }
        else
        {
            node *succ = inordersucc(root);

            int tempvar = succ->data;

            root->right = deleteBST(root->right, succ->data);

            root->data = tempvar;
        }
    }

    return root;
}

// //Correct code below::

// node* getSucc(node* curr)
// {
//     curr= curr->right;
//     while(curr!=NULL && curr->left!=NULL)
//     {
//         curr= curr->left;
//     }

//     return curr;
// }

// node* delNode(node* root, int x)
// {
//     if(root==NULL)
//     {
//         return root;
//     }

//     if(root->data>x)
//     {
//         root->left= delNode(root->left,x);
//     }
//     else if(root->data<x)
//     {
//         root->right= delNode(root->right,x);
//     }
//     else
//     {
//         if(root->left==NULL)
//         {
//             node* temp= root->right;
//             delete(root);
//             return temp;
//         }
//         else if(root->right==NULL)
//         {
//             node* temp= root->left;
//             delete(root);
//             return temp;
//         }
//         else
//         {
//             node* succ= getSucc(root);
//             root->data=succ->data;
//             root->right= delNode(root->right,succ->data);
//         }

//     }
//     return root;
// }

int main()
{
    node *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    insertBST(root, 6);

    inorder(root);
    cout << endl;
    root = deleteBST(root, 3);
    // root= delNode(root,3);
    inorder(root);
}