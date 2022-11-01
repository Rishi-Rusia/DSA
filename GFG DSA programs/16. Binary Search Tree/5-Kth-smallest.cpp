#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    int lcount;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
        lcount = 0;
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
        root->lcount++;
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

void inorderLeftCount(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorderLeftCount(root->left);
    cout << root->lcount << " ";
    inorderLeftCount(root->right);
}

node *ksmall(node *root, int n)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->lcount + 1 == n)
    {
        cout << root->data;
        return root;
    }
    else if (n < root->lcount + 1)
    {
        root->left = ksmall(root->left, n);
    }
    else
    {
        root->right = ksmall(root->right, n - root->lcount - 1);
    }

    return root;
}

int main()
{
    node *root = NULL;
    root = insertBST(root, 52);
    insertBST(root, 11);
    insertBST(root, 32);
    insertBST(root, 41);
    insertBST(root, 214);
    insertBST(root, 712);
    insertBST(root, 644);

    inorder(root);
    cout << endl;
    inorderLeftCount(root);
    cout << endl;
    ksmall(root, 5)->data;
}