#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book
{
public:
    string title, author;
    int id;
    bool isbooked;
    Book(string title, string author, int id)
    {
        this->title = title;
        this->author = author;
        this->id = id;
        this->isbooked = false;
    }
    virtual void Display()
    {
        cout << "Title : " << title << endl;
        cout << "Author : " << author << endl;
        cout << "ID : " << id << endl;
        if (isbooked == false)
        {
            cout << "The book is currently available" << endl;
        }
        else
        {
            cout << "The Book : " << title << " with ID : " << id << " is already booked." << endl;
        }
    }
};

class Member
{

public:
    int memberid;
    string name;
    Member(string name, int memberid)
    {
        this->name = name;
        this->memberid = memberid;
    }
    void Display()
    {
        cout << "The Name of the User : " << name << endl
             << "The ID of the User : " << memberid << endl;
    }
};

class Library 
{
    vector<Book> Books;

public:
    void addbook(string title, string author, int id)
    {
        Books.push_back(Book(title, author, id));
        cout<<"Book : "<<title <<" added successfully."<<endl;
    }

    void Displaybook(){
        for(auto &book : Books){
            book.Display();
        }
    }

    void issuebook(string title)
    {
        for (auto &book : Books)
        {
            if (book.title == title && !book.isbooked)
            {
                book.isbooked=true;
                cout<<"The book : "<<title<<" issued successfully."<<endl;
            }
            else{
                cout<<"The book : "<<title<<" is already issued."<<endl;
            }
        }
    }

    void returnbook(string title){
       for(auto &book:Books){
           book.isbooked=false;
           cout<<"Book : "<<title<<" returned successfully."<<endl;
       }
    }
};

int main()
{
    Library *ptr=new Library;
    ptr->addbook("Wings Of Fire","Dr.Apj Abdul Kalam",4141);
    ptr->Displaybook();
    ptr->issuebook("Wings Of Fire");
    ptr->Displaybook();
    ptr->returnbook("Wings Of Fire");
    ptr->Displaybook();
    return 0;
}