#include <iostream>

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

Node* insertBST(Node* root,int val)
{
    if(root==NULL)
    {
        return new Node(val);
    }
    
    if(val<root->data)
    {
        root->left= insertBST(root->left, val);
    }
    
    if(val>root->data)
    {
        root->right= insertBST(root->right, val);
    }
    
    return root;
}

void inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


bool searchInBST(Node* root, int val)
{
    if(root==NULL)
    {
        return false;
    }
    
    if(root->data==val)
    {
        return true;
    }
    else if(val<root->data)
    {
         searchInBST(root->left,val);
    }
    else{
        searchInBST(root->right,val);
    }
   
}

int main()
{
    Node* root= NULL;
    root=insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);
    insertBST(root,6);
    
    inorder(root);
    cout<<endl;
    
    cout<<searchInBST(root, 6);
}