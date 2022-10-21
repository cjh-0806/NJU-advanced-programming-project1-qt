#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QTimer>

#define TIMEOUT 1 * 60*1000 //单位：毫秒 结算订单时间间隔：1min
#define INTERVAL 10 * 60 //单位：秒 拍卖结算时间间隔：10min

class myThread : public QThread
{
    Q_OBJECT
public:
    myThread(QThread *parent = nullptr);
    ~myThread();
    void run(); //QThread的虚函数，线程处理函数，通过start()间接调用

private:
    QTimer *timer;

private slots:
    void timeoutSlot();
};

#endif // MYTHREAD_H
