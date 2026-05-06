#include<iostream>
#include<string>
#include<vector>
#include "Book.h"

using namespace std;

class book;
class loan;

vector<book> books; // adding vector of books to store all the books in the library
vector<loan> loans;
Book::Book(string t, string a, int i) {
    title = t;
    author = a;
    id = i;
}

string Book::getTitle() {
    return title;
}

string Book::getAuthor() {
    return author;
}

int Book::getId() {
    return id;
}

class book
{
    // data members
    private:
    int id;
    string title;
    string author;
    bool isAvailable;

    public:

    //setters and getters
    void setId(int i)
    {
       id = i;
    }

    int getId()
    {
        return id;
    }

    void setTitle(string t)
    {
        title = t;
    }

    string getTitle()
    {
        return title;
    }

    void setAuthor(string a)
    {
        author = a;
    }

    string getAuthor()
    {
        return author;
    }

    void setIsAvailable(bool a)
    {
        isAvailable = a;
    }

    bool getIsAvailable()
    {
        return isAvailable;
    }

    //constructors

    //empty
    book()
    {
        id = 0;
        title = "none";
        author = "none";
        isAvailable = true;
    }

    //parameterized
    book(int i, string t, string a, bool avail)
    {
        id = i;
        title = t;
        author = a;
        isAvailable = avail;
    }

    //functions: these functions should be added to the library class too

    void addBook(int i, string t, string a)// to add any book we need id, title and author data
    {
        cout<<"enter book title: ";
        cin>>title;
        cout<<"enter book author: ";
        cin>>author;
        cout<<"the book ID is: "<<id<<endl;
        /*book newBook(title, author, id);
        books.push_back(newBook); */
    }

    void removeBook(int i)
    {
        cout<<"enter book ID to remove: ";
        cin>>id;

        for(int j=0; j<books.size(); j++)
        {
            if(books[j].getId() == id)
            {
                books.erase(books.begin() + j);
                cout<<"book removed successfully"<<endl;
                return;
            }
        }
        cout<<"book not found"<<endl;
    }

    void listBook() // the goal is to let the user know what books are available in the library, so we will list all the books in the library and their details, and if there are no books available we will print a message to the user
    {
        cout<<"list of books in the library: "<<endl;

        for(int i=0; i<books.size(); i++)
        {
            cout<<"ID: "<<books[i].getId()<<", Title: "<<books[i].getTitle()<<", Author: "<<books[i].getAuthor()<<endl;
        }

        if (books.empty())
        {
            cout << "No books available" << endl;
            return;
        }
    }

    void borrowBook(int i)
    {
        cout<<"enter book ID to borrow: ";
        cin>>id;

        for(int j=0; j<books.size(); j++)
        {
            if(books[j].getId() == id)
            {
                if(books[j].getIsAvailable())
                {
                    books[j].setIsAvailable(false);// bcz, user berrow it so, it is not available now
                    cout<<"book borrowed successfully"<<endl;
                    return;
                }
                else
                {
                    cout<<"book is not available"<<endl;
                    return;
                }
            }
        }
        cout<<"book not found"<<endl;
    }

};