//ZigZag Traversal

#include <iostream>
#include <climits>
#include <stack>

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


void zigzagTraversal(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    stack<Node*> currLevel;
    stack<Node*> nextLevel;
    
    bool leftToRight= true;
    
    currLevel.push(root);
    
    while(!currLevel.empty())
    {
        Node* temp= currLevel.top();
        currLevel.pop();
        
        if(temp)
        {
            cout<<temp->data<<" ";
       
        
        if(leftToRight)
        {
            if(temp->left)
            {
                nextLevel.push(temp->left);
            }
            if(temp->right)
            {
                nextLevel.push(temp->right);
            }
        }
        
        //right to left
        
        else{
            if(temp->right)
            {
                nextLevel.push(temp->right);
            }
            
            if(temp->left)
            {
                nextLevel.push(temp->left);
            }
        }
        
        }
        
        if(currLevel.empty())
        {
            leftToRight= !leftToRight;
            swap(currLevel,nextLevel);
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
    
    zigzagTraversal(root);
    
}