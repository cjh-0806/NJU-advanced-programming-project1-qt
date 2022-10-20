#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    string userID;
    string username;
    string passwd;
    string phonenum;
    string address;
    float balance;
    string state;
public:
    User();
    User(string id, string name, string pswd, string pnum, string addr, float b, string s);

    string get_id() const;
    string get_name() const;
    string get_pswd() const;
    string get_num() const;
    string get_addr() const;
    float get_balance() const;
    string get_state() const;

    void set_name(string name);
    void set_pswd(string pswd);
    void set_num(string pnum);
    void set_addr(string addr);
    void set_balance(float b);
    void set_state(string s);
};

class UArray
{
    int size; //数组元素的个数
    User* ptr; //指向动态分配的数组
public:
    UArray(int s = 0);
    UArray(UArray & a);
    ~UArray();
    void push_back(User u); //在数组尾部添加一个元素v
    void clear(); //清空
    UArray & operator= (const UArray & a); //用于数组对象间的赋值

    int length() const { return size; } //返回数组元素个数
    User & operator[](int i) { return ptr[i]; }//用以支持根据下标访问数组元素

    void array2file(const char* src);
    void file2array(const char* src);
};

#endif // USER_H
