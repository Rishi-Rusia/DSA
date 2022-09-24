

#include <iostream>

using namespace std;

int main()
{
    int a[3][3],b[3][3],c[3][3];
    cout<<"Enter the first matrix:\n\n";
    
    int i,j;
    int e=1;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<"Enter element "<<e<<":";
            cin>>a[i][j];
            e++;
        }
    }
    
    cout<<"Enter the second matrix::\n\n";
    
    e=1;
    
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<"Enter element "<<e<<":";
            cin>>b[i][j];
            e++;
        }
    }
    
    int k;
    
    /*THE CODE BELOW THIS COMMENT IS THE CODE TO MULTIPLY TWO MATRICES
    
    In the following algorithm/method to mulitply matrices
    we simply create a third loop(of k) to traverse the array horizontally
    and vertically at the same time and as we do so we keep multiplying the 
    elements of the two arrays and adding them to sum.
    
    sum, then become an element of the third array and is stored there.
    
    NOTE==> This particular program was made with the assump that the matrices
    are 3X3. If the value of matrices was entered by the user we would have to
    check the two matrices of compatibility of multiplication.*/
    
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            int sum=0;
            for(k=0;k<3;k++)
            {
                sum=sum + a[i][k]*b[k][j];
            }
            
            c[i][j]=sum;
        }
        
    }
    
    cout<<endl<<"The resultant matrix is:\n"<<endl;
    
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<c[i][j]<<"\t";
        }
        
        cout<<endl;
    }
}