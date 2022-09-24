#include <iostream>
#include <stack>

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

void zigzag(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    stack<Node*> currLevel;
    stack<Node*> nextLevel;
    currLevel.push(root);
    bool leftToRight=true;
    
    while(!currLevel.empty())
    {
        Node* temp= currLevel.top();
        currLevel.pop();
        
        if(temp)
        {
            cout<<temp->data<<" ";
            
            if(leftToRight)
        {
            if(temp->left){
                nextLevel.push(temp->left);
            }
            if(temp->right)
            {
                nextLevel.push(temp->right);
            }
        }
        
        if(!leftToRight)
        {
            if(temp->right)
            {
                nextLevel.push(temp->right);
            }
            if(temp->left){
                nextLevel.push(temp->left);
            }
        }
        }
        
        if(currLevel.empty())
        {
            leftToRight = !leftToRight;
            swap(currLevel,nextLevel);
        }
    }
    
    
}


bool identicalTree(Node* root1, Node* root2)
{
    if(root1==NULL && root2==NULL)
    {
        return true;
    }
    
    if((root1 != NULL && root2==NULL) || (root1==NULL && root2 != NULL))
    {
        return false;
    }
    
    if(root1->data==root2->data && identicalTree(root1->left, root2->left) && identicalTree(root1->right,root2->right))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Node* root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);
    
    Node* root1= new Node(1);
    root1->left= new Node(2);
    root1->right= new Node(3);
    root1->left->left= new Node(4);
    root1->left->right= new Node(5);
    root1->right->left= new Node(6);
    root1->right->right= new Node(7);
    
    cout<<identicalTree(root,root1);
}