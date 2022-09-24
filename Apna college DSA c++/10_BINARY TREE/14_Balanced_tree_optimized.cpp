//OptimizedBALANCED BINARY tree
//In a Balanced binary tree, the difference between height of each node in left and right is <=1

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

bool isBalanced(Node* root, int* height)
{
    if(root==NULL)
    {
        return true;
    }
    int lh=0,rh=0;
    if(isBalanced(root->left, &lh)==false)
    {
        return false;
    }
    
    if(isBalanced(root->right,&rh)==false)
    {
        return false;
    }
    
    *height=max(lh,rh)+1;
    
    if(abs(lh-rh)<=1)
    {
        return true;
    }
    else
    {
        return false;
    }
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
    
    int height=0;
    
    if(isBalanced(root,&height))
    {
        cout<<"Balanced";
    }
    else
    {
        cout<<"Unbalanced";
    }
    
}