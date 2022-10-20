#include "widget.h"
#include "ui_widget.h"
#include "regiwidget.h"
#include "uloginwidget.h"
#include "userwidget.h"
#include "aloginwidget.h"
#include "adminwidget.h"
#include "commodity.h"
#include "order.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_QuitOnClose, true);
    QPixmap pix("/home/cjh/Pictures/auction.jpg");
    ui->picLabel->setPixmap(pix);

    thread = new myThread();  //分配空间
    connect(this, &Widget::destroyed, this, &Widget::stopThread);

    thread->start();
    qDebug() << "start timer" << endl; //会输出
}

Widget::~Widget()
{
    delete ui;
}

void Widget::reshow()
{
    this->show();
}

void Widget::on_uloginButton_clicked()
{
    uloginWidget* ul_w = new uloginWidget;
    this->hide();
    ul_w->show();
}

void Widget::on_registerButton_clicked()
{
    regiWidget* r_w = new regiWidget;
    r_w->show();
}

void Widget::on_aloginButton_clicked()
{
    aloginWidget* al_w = new aloginWidget;
    this->hide();
    al_w->show();
}

void Widget::on_exitButton_clicked()
{
    this->close();
}

void Widget::stopThread()
{
    //停止线程
    thread->quit();

    //等待线程处理完手头工作
    thread->wait();
    qDebug() << "stop timer" << endl;
}
