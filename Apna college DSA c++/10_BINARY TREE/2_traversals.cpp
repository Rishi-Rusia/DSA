#include <iostream>

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

void preorder(struct Node* root)//function for preorder traversal
{
   if(root==NULL)
   {
       return;
   }
   cout<<root->data<<" ";
   preorder(root->left);
   preorder(root->right);
}

void inorder(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
}

void postorder(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    
    cout<<root->data<<" ";
    
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
    
    preorder(root);//preorder function
    cout<<endl;
    
    inorder(root);//inorder function
    cout<<endl;
    
    postorder(root);//postorder function
    cout<<endl;
    
}