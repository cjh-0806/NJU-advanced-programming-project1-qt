#include "userinfowidget.h"
#include "ui_userinfowidget.h"

#include <QMessageBox>
#include <QInputDialog>

userinfoWidget::userinfoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userinfoWidget)
{
    ui->setupUi(this);
    //setAttribute(Qt::WA_QuitOnClose, false);
}

userinfoWidget::~userinfoWidget()
{
    delete ui;
}

void userinfoWidget::getUserIndex(int i)
{
    this->index = i;
    UArray uarr;
    uarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
    ui->label->setText("Hello, " + QString::fromStdString(uarr[index].get_name()) + "! Please choose your command:");
}

void userinfoWidget::on_returnButton_clicked()
{
    this->close();
}

void userinfoWidget::on_viewinfoButton_clicked()
{
    UArray uarr;
    uarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
    QString text = "username:" + QString::fromStdString(uarr[index].get_name())
            + "\nphone number:" + QString::fromStdString(uarr[index].get_num())
            + "\naddress:" + QString::fromStdString(uarr[index].get_addr())
            + "\nbalance:" + QString::number(uarr[index].get_balance(),'f',1);
    QMessageBox::about(this, "Information", text);
}

void userinfoWidget::on_rechargeButton_clicked()
{
    bool ok;
    double bidPrice = QInputDialog::getDouble(this,"Recharge","Please input the amount you want to recharge:",0,
                                              0,1000000,1,&ok); //一百万不能再多了
    if(!ok)
        return;
    UArray uarr;
    uarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
    if(uarr[index].get_balance() + bidPrice > INT_MAX)
    {
        QMessageBox::warning(this, "WARNING", "Too much balance!");
        return;
    }
    bidPrice += uarr[index].get_balance();
    uarr[index].set_balance(bidPrice);
    uarr.array2file("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
    QString text = "Recharge successfully!\nYour balance:" + QString::number(uarr[index].get_balance(),'f',1);
    QMessageBox::about(this, "Recharge", text);
}

void userinfoWidget::on_mdfinfoButton_clicked()
{
    mdfuserWidget *mu_w = new mdfuserWidget;
    mu_w->setAttribute(Qt::WA_DeleteOnClose);
    mu_w->setWindowModality(Qt::ApplicationModal);
    connect(this, SIGNAL(sendUserIndex(int)),mu_w,SLOT(getUserIndex(int)));
    emit sendUserIndex(index);
    mu_w->show();
}
