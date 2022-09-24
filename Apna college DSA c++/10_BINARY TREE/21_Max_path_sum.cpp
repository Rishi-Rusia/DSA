//Print the sum of the maximum path 

#include <iostream>
#include <queue>
#include <vector>
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

int maxPathSumUtil(Node* root, int &ans)
{
    if(root==NULL)
    {
        return 0;
    }
    
    int left= maxPathSumUtil(root->left,ans);
    int right= maxPathSumUtil(root->right, ans);
    
    int nodeMax=max(max(root->data, root->data+left+right),max(root->data+left, root->data+ right));
    
    ans= max(ans,nodeMax);
    
    int singlePathSum = max(root->data,max(root->data + left, root->data+right));
    
    return singlePathSum;
}

int maxPathSum(Node* root)
{
    int ans= INT_MIN;
    maxPathSumUtil(root, ans);
    return ans;
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
    
    cout<<maxPathSum(root);
  
    
}