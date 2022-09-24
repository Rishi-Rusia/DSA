//identical BST

#include <iostream>
#include <climits>
#include <stack>

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

bool isIdentical(Node* root1,Node* root2)
{
    if(root1==NULL && root2==NULL)
    {
        return true;
    }
    
    else if(root1==NULL || root2==NULL)
    {
        return false;
    }
    
    else
    {
        bool cond1= root1->data ==root2->data;
        bool cond2= isIdentical(root1->left,root2->left);
        bool cond3= isIdentical(root1->right,root2->right);
        if(cond1 && cond2 && cond3)
    {
        return true;
    }
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
    
    struct Node* root2= new Node(1);//Head of the binary tree
    
    root2->left= new Node(2);//left node
    root2->right= new Node(3);//right node
    
    root2->left->left= new Node(4);//left node of left node
    root2->left->right= new Node(5);//right node of left node
    
    root2->right->left= new Node(6);//left node of right node
    root2->right->right= new Node(7);//right node of right node
    
    
    if(isIdentical(root,root2))
    {
        cout<<"identical";
    }
    else{
        cout<<"not identical";
    }
    
}