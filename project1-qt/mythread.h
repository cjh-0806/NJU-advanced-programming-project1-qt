#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QTimer>

#define TIMEOUT 1*60*1000 //结算订单时间间隔：1分钟
#define INTERVAL 5*60 //拍卖结算时间间隔：10分钟

class myThread : public QThread
{
    Q_OBJECT
public:
    myThread(QThread *parent = nullptr);
    ~myThread();
    void run(); //QThread的虚函数，线程处理函数，不能直接调用，通过start()间接调用

private:
    QTimer *timer;

private slots:
    void timeoutSlot();
};

#endif // MYTHREAD_H
