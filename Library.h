#pragma once
#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>

#include "book.h"
#include "user.h"
#include "loan.h"
#include<string>
#include<iostream>

using namespace std;

class Library
{
private:
    vector<Book> books;
    vector<User> users;
    vector<Loan> loans;

    
public:
    void addBook(Book b);
    void addUser(User u);
    void borrowBook(User u, Book b);
    void listBook();
    void listLoans();
    void searchByTitle(string title);
    void returnBook(string userName, string bookTitle);
};

#endif