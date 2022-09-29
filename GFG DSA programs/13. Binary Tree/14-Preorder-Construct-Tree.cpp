#include <iostream>
#include <queue>

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

int predex = 0;

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
    int in[] = {4, 2, 5, 1, 6, 3, 7};
    int pre[] = {1, 2, 4, 5, 3, 6, 7};

    node *root = buildtree(pre, in, 0, 6);
    inorderprint(root);
}