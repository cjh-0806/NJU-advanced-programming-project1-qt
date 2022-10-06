#include "aloginwidget.h"
#include "ui_aloginwidget.h"

aloginWidget::aloginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aloginWidget)
{
    ui->setupUi(this);
}

aloginWidget::~aloginWidget()
{
    delete ui;
}
