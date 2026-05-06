#include<iostream>
#include<string>
#include<vector>

using namespace std;

// include other header files here
#include "book.h"
#include "loan.h"
#include "user.h"


#include "Library.h"
int main()
{
    Library lib;

    //lib.addBook(Book("Clean Code", "Robert Martin"));
    //lib.addBook(Book("C++ Primer", "Lippman"));
    lib.listBook();

    int choice;
    do
     {
        cout<<"\n====== Library Management System (Home Page) ======\n";
        cout<<"1. Add Book\n";
        cout<<"2. Show Books\n";
        cout<<"3. Add User\n";
        cout<<"4. Borrow Book\n";
        cout<<"5. Return Book\n";
        cout<<"6. Search Book by Title\n";
        cout<<"7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline from input buffer

        string title, author;
        int id;
        int copies;

        switch (choice)
        {
        case 1: //add book
            cout << "Enter Title: ";
            getline(cin, title);

            cout << "Enter Author: ";
            getline(cin, author);

            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore(); // Clear newline from input buffer

            lib.addBook(Book(title, author, id));
            break;

        case 2:
            cout << "Showing all books:\n";
            lib.listBook();
            break;

        case 3:
            cout<<"Add user name that you want to add: ";
            getline(cin, title);
            lib.addUser(User(title));
            break;

        case 4:
            cout<<"Enter book title to borrow: ";
            getline(cin, title);

            cout<<"Enter author name: ";
            getline(cin, author);

            lib.borrowBook(User(title), Book(title, author,id));
            break;

        case 5:
            cout<<"Enter user name to return book: ";
            getline(cin, title);

            cout<<"Enter book title to return: ";
            getline(cin, title);
            cin.ignore();

           lib.returnBook("Aya", "Clean Code");
            break;

            case 6:
            cout<<"Enter the book title to search about: ";
            getline(cin, title);
            lib.searchByTitle(title);
            break;

        case 7:
            cout << "Exiting the program.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
