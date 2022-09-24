//Flatten Binary Tree

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

void flatten(Node* root)
{
    if(root==NULL || (root->left==NULL && root->right==NULL))
    {
        return;
    }
    if(root->left != NULL)
    {
        flatten(root->left);
        
        Node* temp= root->right;
        root->right = root->left;
        root->left = NULL;
        
        Node* t= root->right;
        
        while(t->right != NULL)
        {
            t=t->right;
        }
        
        t->right= temp;
    }
    
    flatten(root->right);
}

void inorderprint(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
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
    
    
   flatten(root);
   inorderprint(root);
    
}