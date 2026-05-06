#ifndef LOAN_H
#define LOAN_H

#include "book.h"
#include "user.h"

class Loan {
private:
    Book book;
    User user;

public:
    Loan(Book b, User u);

    Book getBook();
    User getUser();
};

#endif