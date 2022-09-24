/*This is a program for spiral order traversal in c++

To traverse a matrix spirally we need 4 varibles 

row start, row end, column start, column end.

we will print the first row then increase the value of row start
then we will print the end column and decrease the value of column end
then we will print the end in row reverse order and decerease the value of row end by one
then we will print the start column in reverse order and increase the value of start column*/

#include <iostream>

using namespace std;

int main()
{
    int a[3][3];
    
    int i,j;
    
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<"Enter the element number"<<i<<"*"<<j<<":";
            
            cin>>a[i][j];
        }
    }
    
    int rs,re,cs,ce;
    
    rs=0;
    re=2;
    cs=0;
    ce=2;
    
    while(re>=rs&&ce>=cs)
    {
        for(int i=cs;i<=ce;i++)
        {
            cout<<a[rs][i]<<endl;
        }
        rs++;
        
        for(int i=rs;i<=re;i++)
        {
            cout<<a[i][ce]<<endl;
        }
        
        ce--;
        
        for(int i=ce;i>=cs;i--)
        {
            cout<<a[re][i]<<endl;
        }
        
        re--;
        
        for(int i=re;i>=rs;i--)
        {
            cout<<a[i][cs]<<endl;
        }
        cs++;
    }
}