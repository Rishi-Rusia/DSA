#include <iostream>
#include <stack>
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

int completeTree(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lefth = 0, righth = 0;

    node *temp = root;

    while (temp != NULL)
    {
        temp = temp->left;
        lefth++;
    }

    temp = root;

    while (temp != NULL)
    {
        temp = temp->right;
        righth++;
    }

    if (lefth == righth)
    {
        return pow(2, lefth) - 1;
    }

    return 1 + completeTree(root->left) + completeTree(root->right);
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

    cout << completeTree(root);
}