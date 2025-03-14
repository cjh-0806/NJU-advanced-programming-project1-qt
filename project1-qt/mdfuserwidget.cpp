#include "mdfuserwidget.h"
#include "ui_mdfuserwidget.h"
#include "user.h"

#include <QRegExpValidator>
#include <QMessageBox>

mdfuserWidget::mdfuserWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mdfuserWidget)
{
    ui->setupUi(this);
    //setAttribute(Qt::WA_QuitOnClose, false);
    ui->usernameLineEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]{1,10}")));
    ui->pswdLineEdit->setValidator(new QRegExpValidator(QRegExp("[a-z0-9]{1,20}")));
    ui->phonenumLineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{1,20}")));
    ui->addrLineEdit->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z ]{1,40}")));
    //回车
    ui->usernameLineEdit->setFocus();
    connect(ui->usernameLineEdit,SIGNAL(returnPressed()),ui->pswdLineEdit,SLOT(setFocus()));
    connect(ui->pswdLineEdit,SIGNAL(returnPressed()),ui->phonenumLineEdit,SLOT(setFocus()));
    connect(ui->phonenumLineEdit,SIGNAL(returnPressed()),ui->addrLineEdit,SLOT(setFocus()));
    connect(ui->addrLineEdit,SIGNAL(returnPressed()),this,SLOT(on_commitButton_clicked()));
}

mdfuserWidget::~mdfuserWidget()
{
    delete ui;
}

void mdfuserWidget::getUserIndex(int i)
{
    this->index = i;
    UArray uarr;
    uarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
    ui->usernameLineEdit->setPlaceholderText(QString::fromStdString(uarr[index].get_name()));
    ui->pswdLineEdit->setPlaceholderText(QString::fromStdString(uarr[index].get_pswd()));
    ui->phonenumLineEdit->setPlaceholderText(QString::fromStdString(uarr[index].get_num()));
    ui->addrLineEdit->setPlaceholderText(QString::fromStdString(uarr[index].get_addr()));
}

void mdfuserWidget::on_commitButton_clicked()
{
    UArray uarr;
    uarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
    QString name = ui->usernameLineEdit->text();
    QString pswd = ui->pswdLineEdit->text();
    QString num = ui->phonenumLineEdit->text();
    QString addr = ui->addrLineEdit->text();
    int j;
    for(j = 0; j < uarr.length(); ++j)
        if(j != index && uarr[j].get_name() == name.toStdString() && uarr[j].get_state() == "active")
        {
            QMessageBox::warning(this, "WARNING", "This username already exists! Please reset your username!");
            return;
        }
    if(!name.isEmpty())
        uarr[index].set_name(name.toStdString());
    if(!pswd.isEmpty())
        uarr[index].set_pswd(pswd.toStdString());
    if(!num.isEmpty())
        uarr[index].set_num(num.toStdString());
    if(!addr.isEmpty())
        uarr[index].set_addr(addr.toStdString());
    uarr.array2file("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
    QMessageBox::information(this, "INFOMATION", "Modify successfully!");
    this->close();
}

void mdfuserWidget::on_cancelButton_clicked()
{
    this->close();
}
