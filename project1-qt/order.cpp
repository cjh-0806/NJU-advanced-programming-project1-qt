#include "order.h"
#include <cstring>
#include <fstream>
#include <sstream>
#include <iomanip>

Order::Order() {}
Order::Order(string oid, string cid, float p, float b, string d, string sid, string bid, string s)
{
    orderID = oid;
    commodityID = cid;
    unitPrice = p;
    bidPrice = b;
    date = d;
    sellerID = sid;
    buyerID = bid;
    state = s;
}

string Order::get_oid() const { return orderID; }
string Order::get_cid() const { return commodityID; }
float Order::get_price() const { return unitPrice; }
float Order::get_bid() const { return bidPrice; }
string Order::get_date() const { return date; }
string Order::get_sellerid() const { return sellerID; }
string Order::get_buyerid() const { return buyerID; }
string Order::get_state() const { return state; }

void Order::set_bid(float price) { bidPrice = price; }
void Order::set_state(string s) { state = s; }

OArray::OArray(int s):size(s)
{
    if(s == 0)
        ptr = nullptr;
    else
        ptr = new Order[s];
}

OArray::OArray(OArray & a)
{
    if(!a.ptr)
    {
        ptr = nullptr;
        size = 0;
        return;
    }
    ptr = new Order[a.size];
    for(int i = 0; i < a.size; ++i)
        ptr[i] = a.ptr[i];
    size = a.size;
}

OArray::~OArray()
{
    if(ptr)
        delete[] ptr;
}

OArray & OArray::operator=(const OArray & a)
{
    if(ptr == a.ptr) //防止a=a这样的赋值导致出错
        return *this;
    if(a.ptr == nullptr) //a数组为空
    {
        if(ptr)
            delete[] ptr;
        ptr = nullptr;
        size = 0;
        return *this;
    }
    if(size < a.size) //原有空间小于a空间
    {
        if (ptr)
            delete[] ptr;
        ptr = new Order[a.size];
    }
    for(int i = 0; i < a.size; ++i)
        ptr[i] = a.ptr[i];
    size = a.size;
    return *this;
}

void OArray::push_back(Order u)
{
    if(ptr)
    {
        Order* tmpPtr = new Order[size + 1]; //重新分配空间
        for(int i = 0; i < size; ++i) //复制原数组内容
            tmpPtr[i] = ptr[i];
        delete[] ptr;
        ptr = tmpPtr;
    }
    else //数组本来是空的
        ptr = new Order[1];
    ptr[size] = u; //加入新的数组元素
    size++;
}

void OArray::array2file(const char* src)
{
    ofstream fout(src);
    fout << "orderID,commodityID,unitPrice,bidPrice,date,sellerID,buyerID,state" << endl;
    for(int i = 0; i < size; ++i)
    {
        fout << ptr[i].get_oid() << ',' << ptr[i].get_cid() << ',' << fixed << setprecision(1) << ptr[i].get_price() <<
        ',' << ptr[i].get_bid() << ',' << ptr[i].get_date() << ',' << ptr[i].get_sellerid() << ',' <<
        ptr[i].get_buyerid() << ',' << ptr[i].get_state() << endl;
    }
    fout.close();
}

void OArray::file2array(const char* src)
{
    ifstream fin(src);
    string line;
    getline(fin, line);
    while(getline(fin, line))
    {
        stringstream ss(line);
        string tmp;
        int i = 0;
        string orderID, commodityID, date, sellerID, buyerID, state;
        float unitPrice, bidPrice;
        while(getline(ss, tmp, ','))
        {
            if(i == 0) orderID = tmp;
            else if(i == 1) commodityID= tmp;
            else if(i == 2) unitPrice = stof(tmp);
            else if(i == 3) bidPrice = stof(tmp);
            else if(i == 4) date = tmp;
            else if(i == 5) sellerID = tmp;
            else if(i == 6)buyerID = tmp;
            else state = tmp;
            i++;
        }
        push_back(Order(orderID, commodityID, unitPrice, bidPrice, date, sellerID, buyerID, state));
    }
    fin.close();
}

void OArray::clear()
{
    size = 0;
}
