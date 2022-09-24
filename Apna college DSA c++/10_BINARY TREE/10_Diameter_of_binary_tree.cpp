

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

int calcHeight(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lHeight=calcHeight(root->left);
    int rHeight=calcHeight(root->right);
    
    return max(lHeight,rHeight)+1;
}

int calcDiameter(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lHeight=calcHeight(root->left);
    int rHeight=calcHeight(root->right);
    int currDiameter= lHeight+rHeight+1;
    
    int lDiameter= calcDiameter(root->left);
    int rDiameter= calcDiameter(root->right);
    
    return max(currDiameter, max(lDiameter,rDiameter));
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
    
    cout<<calcDiameter(root);
}