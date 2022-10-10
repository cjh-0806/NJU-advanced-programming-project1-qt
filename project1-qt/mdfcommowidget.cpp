#include "mdfcommowidget.h"
#include "ui_mdfcommowidget.h"

mdfcommoWidget::mdfcommoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mdfcommoWidget)
{
    ui->setupUi(this);
    //ui->cnameLineEdit
}

mdfcommoWidget::~mdfcommoWidget()
{
    delete ui;
}

void mdfcommoWidget::on_commitButton_2_clicked()
{

}

void mdfcommoWidget::on_cancelButton_2_clicked()
{
    this->close();
}
