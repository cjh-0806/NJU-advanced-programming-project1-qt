#include "widget.h"
#include "ui_widget.h"
#include "regiwidget.h"
#include "uloginwidget.h"
#include "aloginwidget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPixmap pix("/home/cjh/Pictures/auction.jpg");
    ui->picLabel->setPixmap(pix);

    //connect(ui->registerButton, &QPushButton::clicked, this, &Widget::on_registerButton_clicked);
    //connect(ui->exitButton, &QPushButton::clicked, this, &Widget::on_exitButton_clicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_uloginButton_clicked()
{
    uloginWidget* ul_w = new uloginWidget;
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
    al_w->show();
}

void Widget::on_exitButton_clicked()
{
    this->close();
}
