//Binary Tree Revision
//3- Construct Binary tree from inorder and preorder

#include <iostream>

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

int search(int inorder[], int start, int end, int key)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==key)
        {
            return i;
        }
    }
    
    return -1;
}


Node* buildTree(int preorder[],int inorder[], int start, int end)
{
    if(start>end)
    {
        return NULL;
    }
    
    static int idx= 0;
    
    int curr= preorder[idx];
    
    idx++;
    
    Node* newnode= new Node(curr);
    
    if(start==end)
    {
        return newnode;
    }
    
    int pos= search(inorder,start, end, curr); 
    
    newnode->left= buildTree(preorder, inorder, start, pos-1);
    newnode->right= buildTree(preorder, inorder, pos+1,end);
    
    return newnode;
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
    int preorder[]={1,2,4,3,5};//elements are stored in pre-order sequence
    int inorder[]={4,2,1,5,3};//elements are stored in in-order sequence
    
    //buildTree
    
    Node* root=buildTree(preorder,inorder,0,4);
    inorderprint(root);
}