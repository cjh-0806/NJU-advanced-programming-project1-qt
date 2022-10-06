#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
using namespace std;

class Admin
{
    string name;
    string pswd;
public:
    Admin();
    string get_name() const;
    string get_pswd() const;
};

#endif // ADMIN_H
