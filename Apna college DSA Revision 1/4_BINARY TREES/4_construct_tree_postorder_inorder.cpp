//Binary Tree Revision
//4- Construct Binary tree from inorder and postorder

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


Node* buildTree(int postorder[],int inorder[], int start, int end)
{
    static int idx=4;
    
    if(start>end)
    {
        return NULL;
    }
    int curr= postorder[idx];
    idx--;
    
    Node* newnode= new Node(curr);
    
    if(start==end)
    {
        return newnode;
    }
    
    int pos= search(inorder,start,end,curr);
    
    newnode->right= buildTree(postorder,inorder, pos+1, end);
    newnode->left= buildTree(postorder, inorder, start, pos-1);
    
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
    int postorder[]={4,2,5,3,1};
   
    int inorder[]={4,2,1,5,3};//elements are stored in in-order sequence
    
    //buildTree
    
    Node* root=buildTree(postorder,inorder,0,4);
    inorderprint(root);
}