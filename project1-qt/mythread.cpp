#include "mythread.h"
#include "user.h"
#include "commodity.h"
#include "order.h"
#include <QDebug>

myThread::myThread(QThread *parent) : QThread(parent) { }
myThread::~myThread()
{
    if(timer != nullptr)
        delete timer;
}

time_t string2time(const string & time_string)
{
    struct tm tm1;
    time_t time1;
    sscanf(time_string.c_str(), "%d-%d-%d %d:%d:%d" ,
        &(tm1.tm_year), &(tm1.tm_mon), &(tm1.tm_mday),
        &(tm1.tm_hour), &(tm1.tm_min), &(tm1.tm_sec));
    tm1.tm_year -= 1900;
    tm1.tm_mon--;
    time1 = mktime(&tm1);
    return time1;
}

void myThread::run()
{
    timer = new QTimer();
    timer->setInterval(TIMEOUT);
    connect(timer, &QTimer::timeout, this, &myThread::timeoutSlot);
    timer->start();
    this->exec();
}

void myThread::timeoutSlot()
{
    qDebug() << "timeout" << endl;
    UArray uarr;
    CArray carr;
    OArray oarr;
    uarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
    carr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
    oarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/order.txt");
    time_t nowtime = time(NULL);
    struct tm* t= localtime(&nowtime);
    nowtime = mktime(t);
    for(int i = 0; i < carr.length(); ++i)
    {
        time_t rlstime = string2time(carr[i].get_date());
        double dTime = difftime(nowtime, rlstime); //现在时间减去商品发布时间
        if(dTime >= INTERVAL && carr[i].get_state() == "onAuction") //拍卖时间到
        {
            OArray tmparr; //暂时存放该商品的所有订单
            for(int j = 0; j < oarr.length(); ++j)
                if(oarr[j].get_cid() == carr[i].get_id() && oarr[j].get_state() == "unfinished")
                    tmparr.push_back(oarr[j]);
            for(int x = 0; x < tmparr.length(); ++x) //根据出价和时间排序
                for(int y = 0; y < tmparr.length()-x-1; ++y)
                {
                    if((tmparr[y].get_bid() < tmparr[y+1].get_bid()) ||
                    (tmparr[y].get_bid() == tmparr[y+1].get_bid() && tmparr[y].get_date() > tmparr[y+1].get_date()))
                    {
                        Order temp = tmparr[y];
                        tmparr[y] = tmparr[y+1];
                        tmparr[y+1] = temp;
                    }
                }
            int k;
            for(k = 0; k < tmparr.length() && carr[i].get_num() > 0; ++k) //卖出商品
            {
                time_t bidtime = string2time(tmparr[k].get_date());
                double dTime2 = difftime(bidtime, rlstime);
                if(dTime2 > INTERVAL) //出价时间减去商品发布时间大于INTERVAL，则不卖
                {
                    string orderid(tmparr[k].get_oid(), 1, 3);
                    int oindex = stoi(orderid) - 1;
                    oarr[oindex].set_state("finished");
                    qDebug() << "set state finished  " << QString::fromStdString(orderid) << endl;
                    continue;
                }
                string buyerid(tmparr[k].get_buyerid(), 1, 3);
                string sellerid(tmparr[k].get_sellerid(), 1, 3);
                int bindex = stoi(buyerid) - 1;
                int sindex = stoi(sellerid) - 1;
                float b_balance = uarr[bindex].get_balance();
                float s_balance = uarr[sindex].get_balance();
                if(b_balance >= tmparr[k].get_bid())
                {
                    b_balance -= tmparr[k].get_bid();
                    uarr[bindex].set_balance(b_balance);
                    s_balance += tmparr[k].get_bid();
                    uarr[sindex].set_balance(s_balance);
                    string orderid(tmparr[k].get_oid(), 1, 3);
                    int oindex = stoi(orderid) - 1;
                    oarr[oindex].set_state("get");
                    carr[i].set_num(carr[i].get_num() - 1);
                }
            }
            for(; k < tmparr.length(); ++k)
            {
                string orderid(tmparr[k].get_oid(), 1, 3);
                int oindex = stoi(orderid) - 1;
                oarr[oindex].set_state("finished");
            }
            carr[i].set_state("removed");
        }
    }
    uarr.array2file("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
    carr.array2file("/home/cjh/NJU-advanced-programming-project1-qt/commodity.txt");
    oarr.array2file("/home/cjh/NJU-advanced-programming-project1-qt/order.txt");
}





