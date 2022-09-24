/*The following is a program to search for an element
in a 2d of 3x3 array whose rows and columns are sorted.*/

#include <iostream>

using namespace std;


int main()
{
    //Taking input for elements
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
    
    //k is the element to be searched
    cout<<"Enter the number to be searched";
    
    int k;
    
    cin>>k;
    
    int r=2,c=0;//Starting from the element int the last row and first column
    
    /*THe logic here is that we will compare elements towards the top and towards the right
    simultaneously. If the element on the starting position is lesser than k then we move 
    right, otherwise we move up.*/

    bool flag=false;
    
    while(r>=0 && c>=0 &&r<=2 &&c<=2)
    {
        if(a[r][c]==k)
        {
            cout<<"Element found at "<<r<<" X "<<c;
            flag=true;
            break;
        }
        else if(a[r][c]<k)
        {
            c++;
        }
        else
        {
            r--;
        }
    }
    
    if(flag==false)
    {
        cout<<"Element not found"<<endl;
    }
    
}