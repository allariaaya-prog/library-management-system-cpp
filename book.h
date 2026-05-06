#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int id;
    

public:
    Book(string t, string a, int i);
    string getTitle();
    string getAuthor();
    int getId();

};

#endif