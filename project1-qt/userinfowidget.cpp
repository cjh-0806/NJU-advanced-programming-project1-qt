#include "userinfowidget.h"
#include "ui_userinfowidget.h"

userinfoWidget::userinfoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userinfoWidget)
{
    ui->setupUi(this);
}

userinfoWidget::~userinfoWidget()
{
    delete ui;
}
