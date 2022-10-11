#include "userinfowidget.h"
#include "ui_userinfowidget.h"
#include "mdfuserwidget.h"

#include <QMessageBox>
#include <QInputDialog>

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

void userinfoWidget::getUserIndex(int i)
{
    this->i = i;
    UArray uarr;
    uarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
    ui->label->setText("Hello, " + QString::fromStdString(uarr[i].get_name()) + "! Please choose your command:");
}

void userinfoWidget::on_returnButton_clicked()
{
    this->close();
}

void userinfoWidget::on_viewinfoButton_clicked()
{
    UArray uarr;
    uarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
    QString text = "username:" + QString::fromStdString(uarr[i].get_name())
            + "\nphone number:" + QString::fromStdString(uarr[i].get_num())
            + "\naddress:" + QString::fromStdString(uarr[i].get_addr())
            + "\nbalance:" + QString::number(uarr[i].get_balance(),'f',1);
    QMessageBox::about(this, "Information", text);
}

void userinfoWidget::on_rechargeButton_clicked()
{
    bool ok;
    double bidPrice = QInputDialog::getDouble(this,"Recharge","Please input the amount you want to recharge:",0,
                                              0,2147483647,1,&ok);
    if(!ok)
        return;
    UArray uarr;
    uarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
    bidPrice += uarr[i].get_balance();
    uarr[i].set_balance(bidPrice);
    uarr.array2file("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
}

void userinfoWidget::on_mdfinfoButton_clicked()
{
    mdfuserWidget* mu_w = new mdfuserWidget;
    connect(this, SIGNAL(sendUserIndex(int)),mu_w,SLOT(getUserIndex(int)));
    emit sendUserIndex(i);
    mu_w->show();
}
