#include "sellerwidget.h"
#include "ui_sellerwidget.h"

sellerWidget::sellerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sellerWidget)
{
    ui->setupUi(this);
}

sellerWidget::~sellerWidget()
{
    delete ui;
}
