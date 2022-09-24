//Binary Tree Revision
//6- Finding the Height of a Binary tree

#include <iostream>
#include <queue>

using namespace std;


struct Node
{
  int data;
  Node* left;
  Node* right;
  
  Node(int val)
  {
      data=val;
      left=NULL;
      right=NULL;
  }
};


int Height(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    
    int lefth= Height(root->left);
    int righth= Height(root->right);
    
    return max(lefth,righth)+1;
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
    
    
    
    cout<<endl<<"Height= "<<Height(root);
    
}