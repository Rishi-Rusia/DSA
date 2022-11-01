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

// bool checkBST(node* root,int low, int high)
// {
//     if(root==NULL)
//     {
//         return true;
//     }

//     bool resleft=false;
//     bool resright=false;

//     // if(root->left==NULL)
//     // {
//     //     resleft=true;
//     // }

//     // if(root->right==NULL)
//     // {
//     //     resright= true;
//     // }

//     if(root->data < high)
//     {

//         resleft= checkBST(root->left,low,root->data);
//     }

//     if(root->data>low)
//     {
//         resright= checkBST(root->right,root->data,high);
//     }

//     return resleft&&resright;
// }

// OPTIMAL SOLUTION
bool checkBST(node *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }

    return (root->data > min && root->data < max && checkBST(root->left, min, root->data) && checkBST(root->right, root->data, max));
}

// inorder traversal solution for BST checking
int prevv = INT_MIN;
bool checkBST(node *root)
{
    if (root == NULL)
    {
        return true;
    }

    if (checkBST(root->left) == false)
    {
        return false;
    }

    if (root->data <= prevv)
    {
        return false;
    }

    prevv = root->data;
    return checkBST(root->right);
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

    // Uncommenting this tree with ruin the binary tree
    //  root->left->right = new node(18);

    inorder(root);
    cout << endl;
    cout << checkBST(root, INT_MIN, INT_MAX);
    cout << endl;
    cout << checkBST(root);
}