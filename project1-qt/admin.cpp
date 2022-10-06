#include "admin.h"

Admin::Admin()
{
    name = "admin";
    pswd = "123456";
}

string Admin::get_name() const { return name; }
string Admin::get_pswd() const { return pswd; }
