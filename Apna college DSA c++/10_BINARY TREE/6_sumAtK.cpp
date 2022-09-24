//Level order traversal

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



int sumAtK(Node* root, int K)
{
    if(root==NULL)
    {
        return -1;
    }
    
    queue<Node*> q;
    
    q.push(root);
    q.push(NULL);
    
    int level=0;
    int sum= 0;
    
    while(!q.empty())
    {
        Node* node= q.front();
        q.pop();
        
        if(node!=NULL)
        {
            if(level==K)
            {
                sum+= node->data;
            }
            
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
            level++;
        }
    }
    
    return sum;
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
    
    cout<<sumAtK(root,2);
}