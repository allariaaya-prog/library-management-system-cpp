#include<iostream>
#include<string>
#include<vector>

using namespace std;
vector<user> users;

#include "User.h"

User::User(string n) {
    name = n;
}

string User::getName() {
    return name;
}

int User::getId() {
    return id;
}

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
};