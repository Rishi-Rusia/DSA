//Right view of binary tree
//In a Balanced binary tree, the difference between height of each node in left and right is <=1

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

void rightView(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    queue<Node*> q;
    
    q.push(root);
    
    while(!q.empty())
    {
        int n= q.size();
        
        for(int i=0;i<n;i++)
        {
            Node* curr= q.front();
            q.pop();
            
            if(i==n-1)
            {
                cout<<curr->data<<" ";
                
            }
            
            if(curr->left !=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
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
    
    rightView(root);
    
}