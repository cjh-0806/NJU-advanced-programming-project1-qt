#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include "mythread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void stopThread();  //停止线程

private slots:
    void on_uloginButton_clicked();

    void on_registerButton_clicked();

    void on_aloginButton_clicked();

    void on_exitButton_clicked();

    void reshow();

private:
    Ui::Widget *ui;
    myThread *thread; //线程对象
};

#endif // WIDGET_H
