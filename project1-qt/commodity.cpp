#include "commodity.h"
#include <cstring>
#include <fstream>
#include <sstream>
#include <iomanip>

string category[9] = { {0}, {"life"}, {"study"}, {"food"}, {"clothes"}, {"makeup"}, {"ornament"}, {"digital"}, {"other"} };

Commodity::Commodity() { }

Commodity::Commodity(string id, string name, float p, int n, string a, string d, string sid, string date, string s)
{
    commodityID = id;
    commodityname = name;
    basePrice = p;
    number = n;
    attribute = a;
    description = d;
    sellerID = sid;
    addedDate = date;
    state = s;
}

string Commodity::get_id() const { return commodityID; }
string Commodity::get_name() const { return commodityname; }
float Commodity::get_price() const { return basePrice; }
int Commodity::get_num() const { return number; }
string Commodity::get_attr() const { return attribute; }
string Commodity::get_desc() const { return description; }
string Commodity::get_sid() const { return sellerID; }
string Commodity::get_date() const { return addedDate; }
string Commodity::get_state() const { return state; }

void Commodity::set_name(string name) { commodityname = name; }
void Commodity::set_price(float price) { basePrice = price; }
void Commodity::set_num(int num) { number = num; }
void Commodity::set_attr(string attr) { attribute = attr; }
void Commodity::set_desc(string d) { description = d; }
void Commodity::set_state(string s) { state = s; }

CArray::CArray(int s):size(s)
{
    if(s == 0)
        ptr = nullptr;
    else
        ptr = new Commodity[s];
}

CArray::CArray(CArray & a)
{
    if(!a.ptr)
    {
        ptr = nullptr;
        size = 0;
        return;
    }
    ptr = new Commodity[a.size];
    for(int i = 0; i < a.size; ++i)
        ptr[i] = a.ptr[i];
    size = a.size;
}

CArray::~CArray()
{
    if(ptr)
        delete[] ptr;
}

CArray & CArray::operator=(const CArray & a)
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
        ptr = new Commodity[a.size];
    }
    for(int i = 0; i < a.size; ++i)
        ptr[i] = a.ptr[i];
    size = a.size;
    return *this;
}

void CArray::push_back(Commodity u)
{
    if(ptr)
    {
        Commodity* tmpPtr = new Commodity[size + 1]; //重新分配空间
        for(int i = 0; i < size; ++i) //复制原数组内容
            tmpPtr[i] = ptr[i];
        delete[] ptr;
        ptr = tmpPtr;
    }
    else //数组本来是空的
        ptr = new Commodity[1];
    ptr[size] = u; //加入新的数组元素
    size++;
}

void CArray::array2file(const char* src)
{
    ofstream fout(src);
    fout << "commodityID,commodityname,price,number,attribute,description,sellerID,addedDate,state" << endl;
    for(int i = 0; i < size; ++i)
    {
        fout << ptr[i].get_id() << ',' << ptr[i].get_name() << ',' << fixed << setprecision(1) << ptr[i].get_price()
        << ',' << ptr[i].get_num() << ',' << ptr[i].get_attr() << ',' << ptr[i].get_desc() << ',' <<
        ptr[i].get_sid() << ',' << ptr[i].get_date() << ',' << ptr[i].get_state() << endl;
    }
    fout.close();
}

void CArray::file2array(const char* src)
{
    ifstream fin(src);
    string line;
    getline(fin, line);
    while(getline(fin, line))
    {
        stringstream ss(line);
        string tmp;
        int i = 0;
        string commodityID, commodityname, attr, desc, sellerID, addedDate, state;
        int number;
        float price;
        while(getline(ss, tmp, ','))
        {
            if(i == 0) commodityID = tmp;
            else if(i == 1) commodityname = tmp;
            else if(i == 2) price = stof(tmp);
            else if(i == 3) number = stoi(tmp);
            else if(i == 4) attr = tmp;
            else if(i == 5) desc = tmp;
            else if(i == 6) sellerID = tmp;
            else if(i == 7) addedDate = tmp;
            else state = tmp;
            i++;
        }
        push_back(Commodity(commodityID, commodityname, price, number, attr, desc, sellerID, addedDate, state));
    }
    fin.close();
}

void CArray::clear()
{
    size = 0;
}
