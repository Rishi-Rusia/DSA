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

int search(int inorder[],int start,int end,int curr)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==curr)
        {
            return i;
        }
    }
    
    return -1;
}

void inorderprint(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
    
}

// Node* buildTree(int preorder[],int inorder[],int start, int end)
// {
//     if(start>end)
//     {
//         return NULL;
//     }
//     static int idx=0;
    
//     int curr=preorder[idx];
    
//     idx++;
    
//     Node* node=new Node(curr);
    
//     if(start==end)
//     {
//         return node;
//     }
    
    
//     int pos= search(inorder,start,end,curr);
    
//     node->left= buildTree(preorder,inorder,start,pos-1);
//     node->right= buildTree(preorder,inorder,pos+1,end);
    
//     return node;
    
// }


Node* buildTree(int postorder[],int inorder[],int start, int end)
{
    static int idx=4;
    if(start>end)
    {
        return NULL;
    }
    
    
    int curr=postorder[idx];
    
    idx--;
    
    Node* node=new Node(curr);
    
    if(start==end)
    {
        return node;
    }
    
    
    int pos= search(inorder,start,end,curr);
    
    node->right= buildTree(postorder,inorder,pos+1,end);
    node->left= buildTree(postorder,inorder,start,pos-1);
    
    return node;
    
}


int main()
{
    int postorder[]={4,2,5,3,1};
    // int preorder[]={1,2,4,3,5};//elements are stored in pre-order sequence
    int inorder[]={4,2,1,5,3};//elements are stored in in-order sequence
    
    //buildTree
    
    Node* root=buildTree(postorder,inorder,0,4);
    inorderprint(root);
}