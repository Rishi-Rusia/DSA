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

vector<int> result;
int flag = 0;

void path(node *root, int target)
{
    if (root == NULL)
    {
        return;
    }

    if (root->data == target)
    {
        // result.push_back(root->data);
        flag = 1;
        return;
    }

    path(root->left, target);
    path(root->right, target);

    if (flag == 1)
    {
        result.push_back(root->data);
    }
}

void copy(vector<int> &vect1, vector<int> &vect2)
{
    for (int i = 0; i < vect1.size(); i++)
        vect2.push_back(vect1[i]);
}

void display(vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
}

int LCA(node *root, int first, int second)
{
    vector<int> one;
    vector<int> two;

    path(root, first);

    copy(result, one);

    display(one);

    result.clear();
    flag = 0;

    path(root, second);

    copy(result, two);

    display(two);

    reverse(one.begin(), one.end());
    reverse(two.begin(), two.end());

    int answer = 0;

    for (int i = 0; i < one.size(); i++)
    {
        for (int j = 0; j < two.size(); j++)
        {
            if (one[i] == two[j])
            {
                answer = one[i];
            }
        }
    }

    return answer;
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

    cout << LCA(root, 4, 5);
}

// I am not entirely sure about this solution, please check