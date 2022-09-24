//Replace all nodes with sum of node and all subtree

#include <iostream>
#include <queue>

using namespace std;

struct Node{
  int data;
  
  struct Node* left;
  struct Node* right;
  
  Node(int val)
  {
      data=val;
      left=NULL;
      right=NULL;
  }
};

void sumReplace(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    sumReplace(root->left);
    sumReplace(root->right);
    
    if(root->left!=NULL)
    {
        root->data += root->left->data;
    }
    if(root->right != NULL)
    {
        root->data += root->right->data;
    }

    return;
}

void preorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    struct Node* root= new Node(1);//Head of the binary tree
    
    root->left= new Node(2);//left node
    root->right= new Node(3);//right node
    
    root->left->left= new Node(4);//left node of left node
    root->left->right= new Node(5);//right node of left node
    
    root->right->left= new Node(6);//left node of right node
    root->right->right= new Node(7);//right node of right node
    
    preorder(root);
    cout<<endl;
    sumReplace(root);
    preorder(root);
    
}