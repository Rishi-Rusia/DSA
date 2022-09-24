//BALANCED BINARY tree
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

int height(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+1;
}

bool isBalanced(Node* root)
{
    if(root==NULL)
    {
        return true;
    }
    
    if(isBalanced(root->left)==false)
    {
        return false;
    }
    if(isBalanced(root->right)==false)
    {
        return false;
    }
    
    int lh=height(root->left);
    int rh=height(root->right);
    
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
    
    if(isBalanced(root))
    {
        cout<<"Balanced";
    }
    else
    {
        cout<<"Unbalanced";
    }
    
}