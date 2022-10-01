#include <iostream>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

class node
{
public:
  int data;
  node *left;
  node *right;

  node(int val)
  {
    data = val;
    left = NULL;
    right = NULL;
  }
};

void preorder(node *root)
{
  stack<node *> st;
  node *curr = root;

  while (curr != NULL || st.empty() == false)
  {
    while (curr != NULL)
    {
      cout << curr->data << " ";
      st.push(curr);
      curr = curr->left;
    }

    curr = st.top();
    st.pop();

    curr = curr->right;
  }
}

void preorder2(node *root)
{

  stack<node *> st;

  node *curr = root;

  while (curr != NULL || st.empty() == false)
    ;
  {

    while (curr != NULL)
    {
      cout << curr->data << " ";
      st.push(curr);
      curr = curr->left;
    }

    curr = st.top();
    st.pop();
    curr = curr->right;
  }
}

int main()
{

  node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right->left = new node(6);
  root->right->right = new node(7);

  preorder(root);
  cout << endl;
  preorder2(root);
}