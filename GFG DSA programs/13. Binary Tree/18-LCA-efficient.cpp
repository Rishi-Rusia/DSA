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

vector<int> result;
int flag = 0;

node *LCA(node *root, int first, int second)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == first || root->data == second)
    {
        return root;
    }

    node *lca1 = LCA(root->left, first, second);
    node *lca2 = LCA(root->right, first, second);

    if (lca1 != NULL && lca2 != NULL)
    {
        return root;
    }

    if (lca1 != NULL)
    {
        return lca1;
    }
    else
    {
        return lca2;
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

    cout << LCA(root, 4, 5)->data;
}