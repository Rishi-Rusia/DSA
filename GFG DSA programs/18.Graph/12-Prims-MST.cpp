#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<pair<int,int>> adj[], int u,   int v,int w)
{
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
    
    
}

void display(vector<pair<int,int>> adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        cout<<i<<"->";
        for (pair<int,int> x : adj[i])
        {
            cout << x.first<< "("<<x.second<<")"<<" ";
            
        }
        
        
        
        cout << "\n";
    }
}

int primsMST(vector<pair<int,int>> adj[],int V)
{
    int key[V],res=0;
    
    fill(key,key+V,INT_MAX);
    
    key[0]=0;
    bool mset[V]={false,false,false,false};
    
    for(int count=0;count<V;count++)
    {
        int u=-1;
        for(int i=0;i<V;i++)
        {
            if(mset[i]==false &&(u==-1||key[i]<key[u]))
            {
                u=i;
            }
        }
        
        mset[u]=true;
        
        res=res+key[u];


        for(pair<int,int> v:adj[u])
        {
            int one=v.first;
            int two=v.second;
            if( mset[one]==false)
            {
                key[one]=min(key[one],v.second);
            }
            
            
            
        }
        
    }
    
    cout<<endl;
    for(int x:key)
    {
        cout<<x<<" ";
    }
    cout<<endl<<endl;
    return res;
}

int main()
{
    int V = 4; // size of the vector

    vector<pair<int,int>> adj[V];
    
    addEdge(adj, 0, 1, 1);
    addEdge(adj, 0, 2, 4);
    addEdge(adj, 1, 2, 5);
    addEdge(adj, 1, 3, 2);
    addEdge(adj, 2, 3, 3);
    
     display(adj, V);
    
  
    
    cout<<primsMST(adj,V);
    
}