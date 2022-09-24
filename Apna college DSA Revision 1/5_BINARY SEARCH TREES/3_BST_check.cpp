#include <iostream>
#include <climits>

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

Node* insertBST(Node* root, int val)
{
    if(root==NULL)
    {
        return new Node(val);
    }
    
    if(root->data>val)
    {
        root->left= insertBST(root->left,val);
    }
    
    if(root->data<val)
    {
        
        root->right= insertBST(root->right, val);
    }
    
    return root;
}

bool isBST(Node* root,Node* max, Node* min)
{
    if(root==NULL)
    {
        return true;
    }
    if(max!=NULL && root->data >= max->data)
    {
        return false;
    }
    
    if(min!= NULL && root->data <= min->data)
    {
        return false;
    }

    bool isBSTleft= isBST(root->left,root,min );
    bool isBSTright= isBST(root->right,max,root);
    
    return (isBSTleft && isBSTright);
}

//This is the original function from apna college:

// bool isBST(Node* root, Node* min=NULL, Node* max=NULL)
// {
//     if(root==NULL)
//     {
//         return true;
//     }
//     if(min != NULL && root->data <= min->data)
//     {
//         return false;
//     }
    
//     if(max!=NULL && root->data >= max->data)
//     {
//         return false;
//     }
    
//     bool leftValid= isBST(root->left,min,root);
//     bool rightValid=isBST(root->right,root,max);
//     return (leftValid && rightValid);
// }

int main()
{
    
    Node* root= NULL;
    root=insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);
    
    cout<<isBST(root,NULL ,NULL)<<endl;
    
    
}