#ifndef _ORDERH_
#define _ORDERH_

#include <iostream>
using namespace std;

class Order
{
    string orderID;
    string commodityID;
    float unitPrice;
    float bidPrice;
    string date;
    string sellerID;
    string buyerID;
    string state;
public:
    Order();
    Order(string oid, string cid, float p, float b, string d, string sid, string bid, string s);

    string get_oid() const;
    string get_cid() const;
    float get_price() const;
    float get_bid() const;
    string get_date() const;
    string get_sellerid() const;
    string get_buyerid() const;
    string get_state() const;

    void set_bid(float price);
    void set_state(string s);
};

class OArray
{
    int size; //数组元素的个数
    Order* ptr; //指向动态分配的数组
public:
    OArray(int s = 0);
    OArray(OArray & a);
    ~OArray();
    void push_back(Order u); //在数组尾部添加一个元素v
    void clear(); //清空
    OArray & operator= (const OArray & a); //用于数组对象间的赋值

    int length() const { return size; } //返回数组元素个数
    Order & operator[](int i) { return ptr[i]; }//用以支持根据下标访问数组元素

    void array2file(const char* src);
    void file2array(const char* src);
};

#endif
