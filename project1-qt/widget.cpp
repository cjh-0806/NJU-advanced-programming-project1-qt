#include "widget.h"
#include "ui_widget.h"
#include "regiwidget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPixmap pix("/home/cjh/Pictures/auction.jpg");
    ui->picLabel->setPixmap(pix);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_registerButton_clicked()
{
    regiwidget* r_w = new regiwidget;
    r_w->show();
}

void Widget::on_exitButton_clicked()
{
    this->close();
}
