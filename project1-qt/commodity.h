#ifndef COMMODITY_H
#define COMMODITY_H

#include <iostream>

using namespace std;

extern string category[9];

class Commodity
{
    string commodityID;
    string commodityname;
    float basePrice;
    int number;
    string attribute;
    string description;
    string sellerID;
    string addedDate;
    string state;
public:
    Commodity();
    Commodity(string id, string name, float p, int n, string a, string d, string sid, string date, string s);

    string get_id() const;
    string get_name() const;
    float get_price() const;
    int get_num() const;
    string get_attr() const;
    string get_desc() const;
    string get_sid() const;
    string get_date() const;
    string get_state() const;

    void set_name(string name);
    void set_price(float price);
    void set_num(int num);
    void set_attr(string attr);
    void set_desc(string d);
    void set_state(string s);
};

class CArray
{
    int size; //数组元素的个数
    Commodity* ptr; //指向动态分配的数组
public:
    CArray(int s = 0);
    CArray(CArray & a);
    ~CArray();
    void push_back(Commodity u); //在数组尾部添加一个元素v
    CArray & operator= (const CArray & a); //用于数组对象间的赋值

    int length() const { return size; } //返回数组元素个数
    Commodity & operator[](int i) { return ptr[i]; } //用以支持根据下标访问数组元素

    void array2file(const char* src);
    void file2array(const char* src);
};

#endif // COMMODITY_H
