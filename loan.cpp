#include<iostream>
#include<string>
#include<vector>

using namespace std;
vector<loan> book;
vector<loan> loans; 


#include "Loan.h"

Loan::Loan(Book b, User u) : book(b), user(u) {}

Book Loan::getBook() {
    return book;
}

User Loan::getUser() {
    return user;
}

class loan
{
    private:
    int bookId;
    int userId;
    string loanDate;

    public:

    //setters and getters
    void setBookId(int bId)
    {
        bookId = bId;
    }

    int getBookId()
    {
        return bookId;
    }

    void setUserId(int uId)
    {
        userId = uId;
    }

    int getUserId()
    {
        return userId;
    }

    void setLoanDate(string date)
    {
        loanDate = date;
    }

    string getLoanDate()
    {
        return loanDate;
    }

    //constructors
    loan()
    {
        bookId = 0;
        userId = 0;
        loanDate = "";
    }

    loan(int bId, int uId, string date)
    {
        bookId = bId;
        userId = uId;
        loanDate = date;
    }

    //functions

    string borrowBook(int userId, int bookId)
    {
        // check if the book is available
        for(int i=0;i<book.size();i++)
        {
            if(book[i].getBookId() == bookId)// if the book is found
            {
                if(book[i].getIsAvailable())// if the book is available
                {
                    book[i].setIsAvailable(false);// set the book as not available, bcz you berrow it
                    loan newLoan(bookId, userId, "2024-06-01");// create a new loan
                    book.push_back(newLoan);// add the loan to the list of loans
                    return "Book borrowed successfully";
                }

                else
                {
                    return "Book is not available";
                }
            }
        }
    }

    void returnBook(int bookId)
    {
        for(int i=0;i<book.size();i++)// searching in the library for the book
        {
            if(book[i].getBookId() == bookId)// if the book is found
            {
                book.erase(book.begin() + i);
                cout<<"book removed successfully"<<endl;
                book[i].setIsAvailable(true);// set the book as available
            }         
            
            cout<<"book not found"<<endl;
        }
    }
};
