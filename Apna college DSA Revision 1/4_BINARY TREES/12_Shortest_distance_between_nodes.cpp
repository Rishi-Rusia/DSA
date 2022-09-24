#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    
    Node(int val)
    {
        data= val;
        left= NULL;
        right= NULL;
    }
};


Node* LCA2(Node* root, int n1, int n2)
{
    if(root==NULL)
    {
        return NULL;
    }
    
    if(root->data ==n1 || root->data== n2)
    {
        return root;
    }
    
    Node* leftLCA= LCA2(root->left, n1, n2);
    Node* rightLCA= LCA2(root->right, n1, n2);
    
    if(leftLCA && rightLCA)
    {
        return root;
    }
    
    if(leftLCA !=NULL)
    {
        return leftLCA;
    }
    
    return rightLCA;
    
}

int findist(Node* root, int n,int dist)
{
   
    if(root==NULL)
    {
        return -1;
    }
    
    if(root->data==n)
    {
        return dist;
    }
    
    int left=findist(root->left,n,dist+1);
    
    if(left!=-1)
    {
        return left;
    }
    
    
    
    return findist(root->right,n,dist+1);
    
    
    
}

int shortestDistance(Node* root, int n1, int n2)
{
    Node* lca= LCA2(root,n1,n2);
    int d1= findist(lca,n1,0);
    int d2= findist(lca,n2,0);
    
    return d1+d2+1;
}


int main()
{
    struct Node* root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);
    
    int n1=4, n2=7;
    
    cout<<shortestDistance(root,n1,n2);
}