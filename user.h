#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
private:
    string name;
    int id;

public:
    User(string n);
    string getName();
    int getId();
};

#endif