#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
using namespace std;


class Book
{
    public:
    
    string name;
    string author;
    int id;
    int bno;
    
    
};



int blen=0;

void add(Book *X)
{
    cout<<"Current blen="<<blen;
    
    
    (*X).bno=blen+1;
    cout<<"\nEnter the name of the book:";
    cin.ignore(1000, '\n');
    getline(cin,(*X).name);
    cout<<"\nEnter the name of the author:";
    getline(cin,(*X).author);
    cout<<"\nEnter the book id:";
    cin>>(*X).id;
    cout<<"Congratulations your book has been added to the system\n";
    blen++;
    cout<<"New blen ="<<blen;
}

int check(Book X, int id)
{
        if(X.id==id)
        {
            printf("Book found \n");
        return 1;
        }

        else
        {return 0;}

    
}

Book b[1000];
Book *ptr;

void welcome()
{
    cout<<"****************************************************"<<endl;
    cout<<"\n\nWelcome to the library management system\n\n";
    cout<<"1.Add new book\n2.Search A book\n3.Delete a book\n4.Print Book details\n\nEnter 0 to Exit the program\n";

    int choice,id;
    int flag=0;
    cout<<"Enter the choice\n";
    cin>>choice;
    
    switch(choice)
    {
        case 1:
        ptr=&b[blen];
        add(&b[blen]);
        break;
        case 2:
        
        cout<<"\nEnter the id of the book:";
        cin>>id;
        for(int i=0;i<=blen;i++)
        {
            cout<<b[i].id;
            flag=0;
            int result=check(b[i],id);
          if(result==1)  
            {
                flag=1;
                cout<<"Book found at index "<<i<<endl;
                cout<<"Details of the book are:\n";
                cout<<"Book Name ="<<b[i].name<<endl;
                cout<<"Book Author ="<<b[i].author<<endl;
                cout<<"Book id ="<<b[i].id<<endl;
                cout<<"Book number ="<<b[i].bno<<endl;
                break;
            }
        }

        if(flag==0)
        {
            printf("\nSorry book not found:(\n");
            
        }
        break;
        case 0:
        exit(0);
    }
    
    cout<<"\n\n\n";
    
    

    printf("Enter c to continue\n");
    char key;
    cin>>key;
    
    if(key=='c')
    {
        system("cls");
        welcome();
    }
     

}

int main()
{
    
    welcome();
    
}