//Print all nodes at distance K

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

void printSubtreeNodes(Node* root, int k)
{
    if(root==NULL || k<0)
    {
        return;
    }
    
    if(k==0)
    {
        cout<<root->data<<" ";
        return;
    }
    
    printSubtreeNodes(root->left,k-1);
    printSubtreeNodes(root->right,k-1);
}

int printNodesAtK(Node* root, Node* target,int k)
{
    if(root==NULL)
    {
        return -1;
    }
    
    if(root==target)
    {
        printSubtreeNodes(root,k);
        return 0;
    }
    
    int dl= printNodesAtK(root->left,target,k);
    
    if(dl != -1)
    {
        if(dl+1==k)
        {
            cout<<root->data<<" ";
        }
        else
        {
            printSubtreeNodes(root->right,k-dl-2);
        }
        return 1+dl;
    }
    
    int dr= printNodesAtK(root->right,target,k);
    
    if(dl != -1)
    {
        if(dl+1==k)
        {
            cout<<root->data<<" ";
        }
        else
        {
            printSubtreeNodes(root->left,k-dr-2);
        }
        return 1+dr;
    }
    
    return -1;
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
    
    
  printNodesAtK(root,root->left,1);
    
}