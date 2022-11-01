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

void inorderprint(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorderprint(root->left);
    cout << root->data << " ";
    inorderprint(root->right);
}

void inorder(node *root)
{
    stack<node *> st;
    node *curr = root;

    while (curr != NULL || st.empty() == false)
    {
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;
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

    inorderprint(root); // recursive solution
    cout << endl;
    inorder(root); // iterative solution
}