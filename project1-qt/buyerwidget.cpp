#include "buyerwidget.h"
#include "ui_buyerwidget.h"

buyerWidget::buyerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::buyerWidget)
{
    ui->setupUi(this);
}

buyerWidget::~buyerWidget()
{
    delete ui;
}

void buyerWidget::on_returnButton_clicked()
{
    this->close();
}

void buyerWidget::on_viewcommoButton_clicked()
{

}

void buyerWidget::on_srchcommoButton_clicked()
{

}

void buyerWidget::on_auctionButton_clicked()
{

}

void buyerWidget::on_vieworderButton_clicked()
{

}
