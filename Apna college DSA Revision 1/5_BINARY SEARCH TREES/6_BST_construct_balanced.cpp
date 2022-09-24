#include <iostream>

using namespace std;

struct Node{
  int data; 
  Node* left= NULL;
  Node* right= NULL;
  
  Node(int val)
  {
      data= val;
      left= NULL;
      right= NULL;
  }
};

Node* BalancedBST(int arr[],int start, int end)
{
    if(start>end)
    {
        return NULL;
    }
    int mid= (start+end)/2;
    
    Node* root= new Node(arr[mid]);
    
    root->left= BalancedBST(arr,start, mid-1);
    root->right= BalancedBST(arr,mid+1,end);
    
    return root;
}

void preorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    preorder(root->left);
    cout<<root->data<<" ";
    preorder(root->right);
}

int main()
{
    int arr[]={1,2,3,4,5};
    Node* root= BalancedBST(arr,0,4);
    preorder(root);
}