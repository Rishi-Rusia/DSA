#include <iostream>

using namespace std;

int a[100];
int s;
int flag=0;

void show(int* pointer)
{
    int i;
    for(i=0;i<s;i++)
    {
        printf("%d\t",*pointer);
        
        pointer++;
    }
    
}




int linear(int search)
{
    int i;
    
    
    
    for(i=0;i<s;i++)
    {
        if(a[i]==search)
        {
           flag=1;
           break;
        }
    }
    
    if(flag==1)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

int binary(int search)
{
    int mid,h,l;
    
    
    
    l=0;
    h=s-1;
    
    while(l<=h)
    {
        mid=(l+h)/2;
        
        if(a[mid]==search)
        {
            flag=1;
            break;
        }
        else if(a[mid]>search)
        {
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
    }
    
    if(flag==1)
    {
        return mid;
    }
    else
    {
        return -1;
    }

}

void selection()
{
    int i,j;
    
    int t;
    
    
    
    for(i=0;i<s-1;i++)
    {
        for(j=i+1;j<s;j++)
        {
            if(a[i]>a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
                
            }
        }
        
    }
    int *p=&a[0];
    show(p);
    
    
    
}

void bubble()
{
    int i,j;
    
    int t;
    
    
    
    for(i=0;i<s-1;i++)
    {
        for(j=0;j<s-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                
            }
        }
        
    }
    
    int *p=&a[0];
    show(p);
    
}





int main()
{
    
    cout<<"Enter the size of the array:\n";
    
    cin>>s;
    
    
    cout<<"Enter the elements of the array\n";
    
    int i;
    
    for(i=0;i<s;i++)
    {
        cout<<"Element "<<i<<":";
        cin>>a[i];
    }
    
    
    
    flag=0;
    cout<<"THE MENU:\n1.Linear Search\n2.Binary Search\n3.Selection Sort\n4.Bubble Sort\n";
    cout<<"Enter the choice: ";
    int c;
    
    cin>>c;
    int ele;
    
    int result,*res;
    switch(c)
    {
        case 1:
        cout<<"Enter the element to be searched";
        cin>>ele;
        result=linear(ele);
        if(result==-1)
        {
            cout<<"element not found during linear search\n";
        }
        else
        {
            cout<<"element found at index "<<result;
        }
        break;
        
        case 2:
        cout<<"Enter the element to be searched";
        cin>>ele;
        result=binary (ele);
        if(result==-1)
        {
            cout<<"element not found during linear search\n";
        }
        else
        {
            cout<<"element found at index "<<result;
        }
        break;
        
        case 3:
        selection();
        break;
        
        case 4:
        bubble();
        
        break;
        
        default:
        cout<<"Invalid choice\n";
    }
    
    
}