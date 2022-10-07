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

void searchBST(node *root, int n)
{
    if (root == NULL)
    {
        cout << "Not found";
        return;
    }

    if (root->data == n)
    {
        cout << "Element found in BST" << endl;
        return;
    }
    else if (n < root->data)
    {
        searchBST(root->left, n);
    }
    else
    {
        searchBST(root->right, n);
    }
}

void interativeSearchBST(node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            cout << "Item found" << endl;
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    cout << "Element not found" << endl;
}

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
    searchBST(root, 4);
    searchBST(root, 8);
    cout << endl
         << endl;
    interativeSearchBST(root, 4);
    interativeSearchBST(root, 8);
}