#include "widget.h"
#include "ui_widget.h"

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

