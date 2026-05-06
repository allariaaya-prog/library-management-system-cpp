#include<iostream>
#include<string>
#include<vector>
#include "Library.h"// matching the book class in book.h with the book class in book.cpp
using namespace std;

class loan;

vector<book> books; // adding vector of books to store all the books in the library
vector<user> users; // adding vector of users to store all the users in the library
vector<loan> loans; // adding vector of loans to store all the loans in the library


void Library::addBook(Book b) {
    books.push_back(b);
}

void Library::addUser(User u) {
    users.push_back(u);
}

void Library::borrowBook(User u, Book b) {
    loans.push_back(Loan(b, u));
}

void Library::listLoans() {
    for (Loan l : loans) {
        cout << l.getUser().getName()
             << " borrowed "
             << l.getBook().getTitle()
             << endl;
    }
}

 void Library::listBook() // the goal is to let the user know what books are available in the library, so we will list all the books in the library and their details, and if there are no books available we will print a message to the user
    {
        if (books.empty())
        {
            cout << "No books available" << endl;
            return;
        }

        cout<<"list of books in the library: "<<endl;

        for(int i=0; i<books.size(); i++)
        {
            cout<<"Title: "<<books[i].getTitle()<<", Author: "<<books[i].getAuthor()<<endl;
        }
    }

    void Library::returnBook(string userName, string bookTitle) {
    for (int i = 0; i < loans.size(); i++) {
        if (loans[i].getUser().getName() == userName &&
            loans[i].getBook().getTitle() == bookTitle) {

            loans.erase(loans.begin() + i);
            break;
        }
    }
}

   /* void Library::returnBook(int bookId)
    {
        for(int i=0;i<books.size();i++)// searching in the library for the book
        {
            if(books[i].getId() == bookId)// if the book is found
            {
                books.erase(books.begin() + i);
                cout<<"book removed successfully"<<endl;
                books[i].setIsAvailable(true);// set the book as available
            }         
        }
    }*/

using namespace std;

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
    book()
    {
        id = 0;
        title = "none";
        author = "none";
        isAvailable = true;
    }

    book(int i, string t, string a, bool avail)
    {
        id = i;
        title = t;
        author = a;
        isAvailable = avail;
    }

    //functions
    void addBook(int i, string t, string a)// to add any book we need id, title and author data
    {
        cout<<"enter book title: ";
        cin>>title;
        cout<<"enter book author: ";
        cin>>author;
        cout<<id<<endl;
        /*book newBook(title, author, id);
        books.push_back(newBook); */
    }

    void listBook()
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
};

class user
{
    private:
    int id;
    string name;

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

    void setName(string n)
    {
        name = n;
    }

    string getName()
    {
        return name;
    }

    //constructors
    user()
    {
        id = 0;
        name = "none";
    }

    user(int i, string n)
    {
        id = i;
        name = n;
    }

    //functions
    void addUser(int i, string n)
    {
        cout<<"enter user name: ";
        cin>>name;
        cout<<"the user ID is: "<<id<<endl;
        user newUser(id, name);
        users.push_back(newUser); 
    }

    void listUsers()
    {
        cout<<"list of users in the library: "<<endl;

        for(int i=0; i<users.size(); i++)
        {
            cout<<"ID: "<<users[i].getId()<<", Name: "<<users[i].getName()<<endl;
        }

        if (users.empty())
         {
            cout << "No users available" << endl;
            return;
        }
    }

     // Search for book by title
    void searchByTitle(const string& title)
     {
        bool found = false;
        for (const auto& b : books) {
            if (b.getTitle() == title) {
                b.display();
                found = true;
            }
        }
        if (!found)
            cout << "No book found with that title.\n";
    }

    // search for book by author

    void searchByAuthor(const string& author)
     {
        bool found = false;
        for (const auto& b : books) 
        {
            if (b.getAuthor() == author)
             {
                b.display();
                found = true;
            }
        }
        if (!found)
            cout << "No book found by that author.\n";
    }
};