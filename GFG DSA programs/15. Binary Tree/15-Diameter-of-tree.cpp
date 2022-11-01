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

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lefth = height(root->left);
    int righth = height(root->right);

    int res = max(lefth, righth) + 1;

    return res;
}

int diameter(node *root, int res = 0)
{
    if (root == NULL)
    {
        return 0;
    }

    int h = height(root->left) + height(root->right) + 1;

    int lefth = diameter(root->left);
    int righth = diameter(root->right);

    return max(h, max(lefth, righth));
}

// int maxdi(node* root, int res=0)
// {
//     if(root==NULL)
//     {
//         return 0;
//     }

//     maxdi(root->left);
//     int ldi=diameter(root->left);
//     maxdi(root->right);
//     int rdi= diameter(root->right);

//     res= max(res, max(rdi,ldi));

//     return res;
// }

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

int result = 0;

int modifiedheight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lefth = modifiedheight(root->left);
    int righth = modifiedheight(root->right);

    result = max(result, lefth + righth + 1);

    return max(lefth, righth) + 1;
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

    inorderprint(root);
    cout << endl;
    cout << diameter(root) << endl;
    cout << modifiedheight(root);
    cout << endl
         << result << endl;
}