#include <iostream>
#include <stack>
#include <climits>

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

struct Info{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBST(Node* root)
{
    if(root==NULL)
    {
        return {0,INT_MIN,INT_MAX,0,true};
    }
    if(root->left==NULL && root->right==NULL)
    {
        return {1,root->data,root->data,1,true};
    }
    
    Info leftSubTree= largestBST(root->left);
    Info rightSubTree= largestBST(root->right);
    
    Info curr;
    
    curr.size= (1+leftSubTree.size+ rightSubTree.size);
    
    if(leftSubTree.isBST && rightSubTree.isBST && leftSubTree.max< root->data && rightSubTree.min>root->data)
    {
        curr.max= max(leftSubTree.max,max(rightSubTree.max,root->data));
        curr.min= min(leftSubTree.min,min(rightSubTree.min, root->data));
        
        curr.ans= curr.size;
        curr.isBST=true;
        
        return curr;
    }
    
    curr.ans= max(leftSubTree.ans,rightSubTree.ans);
    curr.isBST=false;
    return curr;
}



int main()
{
    Node* root= new Node(15);
    root->left= new Node(20);
    root->right= new Node(30);
    root->left->left= new Node(5);
    
    cout<<"largestBSTinBT :"<<largestBST(root).ans<<endl;
    return 0;
    
    
}