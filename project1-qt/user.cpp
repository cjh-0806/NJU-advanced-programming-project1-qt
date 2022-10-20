#include "user.h"
#include <cstring>
#include <fstream>
#include <sstream>
#include <iomanip>

User::User() { }

User::User(string id, string name, string pswd, string pnum, string addr, float b, string s)
{
    userID = id;
    username = name;
    passwd = pswd;
    phonenum = pnum;
    address = addr;
    balance = b;
    state = s;
}

string User::get_id() const { return userID; }
string User::get_name() const { return username; }
string User::get_pswd() const { return passwd; }
string User::get_num() const { return phonenum; }
string User::get_addr() const { return address; }
float User::get_balance() const { return balance; }
string User::get_state() const { return state; }

void User::set_name(string name) { username = name; }
void User::set_pswd(string pswd) { passwd = pswd; }
void User::set_num(string pnum) { phonenum = pnum; }
void User::set_addr(string addr) { address = addr; }
void User::set_balance(float b) { balance = b; }
void User::set_state(string s) { state = s; }

UArray::UArray(int s):size(s)
{
    if(s == 0)
        ptr = nullptr;
    else
        ptr = new User[s];
}

UArray::UArray(UArray & a)
{
    if(!a.ptr)
    {
        ptr = nullptr;
        size = 0;
        return;
    }
    ptr = new User[a.size];
    for(int i = 0; i < a.size; ++i)
        ptr[i] = a.ptr[i];
    size = a.size;
}

UArray::~UArray()
{
    if(ptr)
        delete[] ptr;
}

UArray & UArray::operator=(const UArray & a)
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
        ptr = new User[a.size];
    }
    for(int i = 0; i < a.size; ++i) //复制原数组内容
        ptr[i] = a.ptr[i];
    size = a.size;
    return *this;
}

void UArray::push_back(User u)
{
    if(ptr)
    {
        User* tmpPtr = new User[size + 1]; //重新分配空间
        for(int i = 0; i < size; ++i) //复制原数组内容
            tmpPtr[i] = ptr[i];
        delete[] ptr;
        ptr = tmpPtr;
    }
    else //数组本来是空的
        ptr = new User[1];
    ptr[size] = u; //加入新的数组元素
    size++;
}

void UArray::array2file(const char* src)
{
    ofstream fout(src);
    fout << "userID,username,password,phoneNumber,address,balance,userstate" << endl;
    for(int i = 0; i < size; ++i)
    {
        fout << ptr[i].get_id() << ',' << ptr[i].get_name() << ',' << ptr[i].get_pswd() << ','
        << ptr[i].get_num() << ',' << ptr[i].get_addr() << ',' << fixed << setprecision(1) << ptr[i].get_balance()
        << ',' << ptr[i].get_state() << endl;
    }
    fout.close();
}

void UArray::file2array(const char* src)
{
    ifstream fin(src);
    string line;
    getline(fin, line);
    while(getline(fin, line))
    {
        stringstream ss(line);
        string tmp;
        int i = 0;
        string userID, username, passwd, phonenum, address, state;
        float balance;
        while(getline(ss, tmp, ','))
        {
            if(i == 0) userID = tmp;
            else if(i == 1) username = tmp;
            else if(i == 2) passwd = tmp;
            else if(i == 3) phonenum = tmp;
            else if(i == 4) address = tmp;
            else if(i == 5) balance = stof(tmp);
            else state = tmp;
            i++;
        }
        push_back(User(userID, username, passwd, phonenum, address, balance, state));
    }
    fin.close();
}

void UArray::clear()
{
    size = 0;
}
