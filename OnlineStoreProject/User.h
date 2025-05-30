#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
protected:
    string username, password;
public:
    virtual void menu() = 0;
};

#endif
