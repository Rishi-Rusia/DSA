#include <iostream>

using namespace std;

void check(int a,int b,int c)
{
    int sum=0,h=0;
    h=a*a;
    sum=b*b+c*c;
    
    if(h==sum)
    {
        cout<<"Pythagoarean triplet\n";
    }
    else
    {
        cout<<"Not a Pythagoarean triplet\n";
    }
    
}

int main()
{
    cout<<"Enter the sides of the triangle\n";
    
    int a,b,c;
    
    cin>>a>>b>>c;
    
    if(a>b&&a>c)
    {
        check(a,b,c);
    }
    
    else if(b>a&&b>c)
    {
        check(b,a,c);
    }
    else
    {
        check(c,b,a);
    }
}