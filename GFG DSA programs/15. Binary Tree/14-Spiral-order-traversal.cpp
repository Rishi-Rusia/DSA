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

void spiral(node *root)
{
    vector<node *> v;
    queue<node *> q;

    q.push(root);

    q.push(NULL);

    bool even = false;

    while (q.empty() == false)
    {
        node *p = q.front();

        q.pop();

        if (p == NULL && q.empty() == false)
        {
            p = q.front();

            q.pop();

            q.push(NULL);

            if (even == true)
            {
                reverse(v.begin(), v.end());
            }

            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i]->data << " ";
            }

            v.clear();

            if (even == false)
            {
                even = true;
            }
            else
            {
                even = false;
            }
        }

        if (p == NULL && q.empty())
        {

            if (even == true)
            {
                reverse(v.begin(), v.end());
            }

            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i]->data << " ";
            }
        }

        if (p != NULL && p->left != NULL)
        {
            q.push(p->left);
        }
        if (p != NULL && p->right != NULL)
        {
            q.push(p->right);
        }

        v.push_back(p);
    }
}

void stackspiral(node *root)
{
    stack<node *> s1, s2;

    int counter = 1;

    s1.push(root);

    while (s1.empty() == false || s2.empty() == false)
    {
        if (counter % 2 == 0)
        {
            while (s2.empty() == false)
            {
                node *p = s2.top();

                s2.pop();

                if (p->right != NULL)
                {
                    s1.push(p->right);
                }

                if (p->left != NULL)
                {
                    s1.push(p->left);
                }

                cout << p->data << " ";

                if (s2.empty())
                {
                    counter++;
                }
            }
        }
        else
        {
            while (s1.empty() == false)
            {
                node *p = s1.top();

                s1.pop();

                if (p->left != NULL)
                {
                    s2.push(p->left);
                }

                if (p->right != NULL)
                {
                    s2.push(p->right);
                }

                cout << p->data << " ";

                if (s1.empty())
                {
                    counter++;
                }
            }
        }
    }
}

//----------------------------------------------------------------------

int predex;

node *buildtree(int preorder[], int inorder[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int curr = preorder[predex];

    node *root = new node(curr);

    predex++;

    int idex;

    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            idex = i;
            break;
        }
    }

    root->left = buildtree(preorder, inorder, start, idex - 1);
    root->right = buildtree(preorder, inorder, idex + 1, end);

    return root;
}

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

int main()
{
    // int in[]={5,4,2,1,3,7,6};
    // int pre[]={1,2,4,5,3,7,6};

    // node* root= buildtree(pre,in,0,6);

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->left->left = new node(8);
    root->left->left->right = new node(9);

    inorderprint(root);
    cout << endl;
    spiral(root);
    cout << endl;
    stackspiral(root);
}