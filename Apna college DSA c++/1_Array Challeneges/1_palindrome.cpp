#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    cout<<"enter your string:\n";
    char ch[50];
    
    
    cin>>ch;
    
    
    
    int last;
    
    last=strlen(ch);
    
    //next loop has code to convert an entire string to lowercase in cpp

    for(int i=0;i<last;i++)
    {
        ch[i]=tolower(ch[i]);
    }
    
    int half=last/2;
    
    last--;
    
    bool check=true;
    
    for(int i=0;i<=half;i++)
    {
        if(ch[i]!=ch[last])
        {
            check=false;
            break;
        }
        last--;
    }
    
    if(check==true)
    {
        cout<<"Pallindrome\n";
    }
    else
    {
        cout<<"Not Pallindrome\n";
    }
}