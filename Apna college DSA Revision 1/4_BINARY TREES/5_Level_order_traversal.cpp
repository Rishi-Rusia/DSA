//Binary Tree Revision
//5- Level order Traversal

#include <iostream>
#include <queue>

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

void printLevelOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty())
    {
        Node* node= q.front();
        q.pop();
        
        if(node!= NULL)
        {
            cout<<node->data<<" ";
            
            if(node->left)
            {
                q.push(node->left);
            }
            
            if(node->right)
            {
                q.push(node->right);
            }
        }
        else if(!q.empty())
        {
            q.push(NULL);
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
    
    printLevelOrder(root);
}