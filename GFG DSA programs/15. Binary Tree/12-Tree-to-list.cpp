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

// void insert(node* head,node* val)
// {
//     node* temp=head;

//     while(temp->right!=NULL)
//     {
//         temp=temp->right;
//     }

//     temp->right=val;
// }

// node* treelist(node* root,node* prev=NULL)
// {
//     if(root->left ==NULL && root->right==NULL)
//     {
//         return root;
//     }

//     prev=root;
//     node* lefty;
//     if(root->left!=NULL)
//     {
//         lefty= treelist(root->left,root);
//         insert(lefty,prev);

//     }

//      if(root->right!=NULL)
//      {
//          prev->right= treelist(root->right,root);
//      }

//   return lefty;
// }

node *pprev = NULL;

node *treelist(node *root)
{
    if (root == NULL)
    {
        return root;
    }

    node *head = treelist(root->left);

    if (pprev == NULL)
    {
        head = root;
    }
    else
    {
        root->left = pprev;
        pprev->right = root;
    }

    pprev = root;

    treelist(root->right);

    return head;
}

void display(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    // root->left->left = new node(4);
    // root->left->right = new node(5);
    // root->right->left = new node(6);
    // root->right->right = new node(7);
    // root->right->left->right= new node(8);
    // root->right->left->right->left= new node(9);

    root = treelist(root);
    display(root);
}