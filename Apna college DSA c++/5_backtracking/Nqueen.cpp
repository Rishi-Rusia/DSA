//Nqueen problem

#include <iostream>

using namespace std;

bool safe(int** arr,int x,int y,int n)//This function checks if the pawn being placed is safe
{
    for(int i=x;i>=0;i--)
    {
        if(arr[i][y]==1)
        {
            return false;
        }
    }
    
    for(int i=x;i>=0;i--)
    {
        if(arr[i][y]==1)
        {
            return false;
        }
    }
    
    int col1=y;
    
    for(int i=x;i>=0;i--)
    {
        if(arr[i][col1]==1)
        {
            return false;
        }
        col1--;
        
        if(col1<0)
        {
            break;
        }
    }
    
    col1=y;
    
    for(int i=x;i>=0;i--)
    {
        if(arr[i][col1]==1)
        {
            return false;
        }
        col1++;
        
        if(col1>(n-1))
        {
            break;
        }
    }
    
    return true;
}

bool queen(int **arr,int x,int y,int n)//This function places the pawns
{
    if(x>=n)
    {
        return true;
    }
    for(int i=0;i<n;i++)
    {
        
            if(safe(arr,x,i,n))
            {
                arr[x][i]=1;
                
                if(queen(arr,x+1,i,n))
                {
                    return true;
                }
                
                arr[x][i]=0;//backtracking
            }
            
    }
    
    return false;
}

int main()
{
    int n;
    
    cin>>n;
    
    int** arr= new int*[n];
    
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
        
        for(int j;j<n;j++)
        {
            arr[i][j]=0;
        }
    }
    
    if(queen(arr,0,0,n))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}