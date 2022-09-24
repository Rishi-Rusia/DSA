//Program to check for BST

#include <iostream>
#include <climits>

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


bool isBST(Node* root, Node* min=NULL, Node* max=NULL)
{
    if(root==NULL)
    {
        return true;
    }
    if(min != NULL && root->data <= min->data)
    {
        return false;
    }
    
    if(max!=NULL && root->data >= max->data)
    {
        return false;
    }
    
    bool leftValid= isBST(root->left,min,root);
    bool rightValid=isBST(root->right,root,max);
    return (leftValid && rightValid);
}

int main()
{
   Node* root= new Node(5);
   root->left= new Node(1);
   root->right= new Node(8);
   
   if(isBST(root))
   {
       cout<<"BST";
   }
   else
   {
       cout<<"not";
   }
}