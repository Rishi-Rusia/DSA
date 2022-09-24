//The merge sort algorithm is a divide and conquer soritng algorithm 

#include <iostream>

using namespace std;

void merge(int arr[],int l, int m, int r)//This function will the merge the arrays sent to it
{
    int n1=m-l+1;//size of temperary array 1
    int n2=r-m;//size of temporary array 2
    
    int a[n1];//first array
    int b[n2];//second array
    

    //Now we will divide the elements in half and enter those in arrays.
    
    
    for(int i=0;i<n1;i++)
    {
        a[i]=arr[l+i];//adding half elements to temp array 1
    }
    
    for(int i=0;i<n2;i++)
    {
        
        b[i]=arr[m+1+i];//adding half elements to temp array 2
    }
    
    int i=0;
    int j=0;
    int k=l;//initializing varibles

    //Now we will sort the array by checking which element is less and which is more
    
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
          arr[k]=a[i];
          i++;k++;
        }
        else
        {
            arr[k]=b[j];
            k++;j++;
        }
    }
    
    //In case any element was left, we will run 2 extra loops for this.

    while(i<n1)
    {
        arr[k]=a[i];
        i++;k++;
    }
    
    while(j<n2)
    {
        arr[k]=b[j];
        j++;k++;
    }
}

void mergesort(int arr[],int l, int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        mergesort(arr,l,m);//Diving and sending the first half
        mergesort(arr,m+1,r);//Dividing and sending the second half
        merge(arr,l,m,r);
    }
}

int main()
{
    cout<<"Enter the size of the fucking array"<<endl;
    int n;
    cin>>n;
    cout<<"Now bitch, you may enter the elements"<<endl;
    
    int arr[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    mergesort(arr,0,n-1);
    
    
      for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}