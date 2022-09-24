//Optimized program for diameter of binary tree

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

int calcDiameter(Node* root,int* height)
{
    if(root==NULL)
    {
        *height=0;
        return 0;
    }
    
    int lh=0,rh=0;
    int lDiameter=calcDiameter(root->left,&lh);
    int rDiameter=calcDiameter(root->right,&rh);
    
    int currDiameter=lh+rh+1;
    *height=max(lh,rh)+1;
    
    return max(currDiameter,max(lDiameter,rDiameter));
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
    
    int height;
    
    cout<<calcDiameter(root,&height);
}