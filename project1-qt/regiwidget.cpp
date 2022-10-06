#include "regiwidget.h"
#include "ui_regiwidget.h"
#include <QRegExpValidator>
#include <QMessageBox>

#include <cstring>
#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

regiWidget::regiWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::regiWidget)
{
    ui->setupUi(this);

    ui->usernameLineEdit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]{1,10}")));
    ui->pswdLineEdit->setValidator(new QRegExpValidator(QRegExp("[a-z0-9]{1,20}")));
    ui->phonenumLineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{1,20}")));
    ui->addrLineEdit->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z ]{1,40}")));

}

regiWidget::~regiWidget()
{
    delete ui;
}

void regiWidget::on_commitButton_clicked()
{
    UArray uarr;
    uarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
    QString username = ui->usernameLineEdit->text();
    QString pswd = ui->pswdLineEdit->text();
    QString phonenum = ui->phonenumLineEdit->text();
    QString addr = ui->addrLineEdit->text();
    stringstream ss;
    ss << 'U' << setfill('0') << setw(3) << uarr.length() + 1;
    string userID = ss.str();
    string state = "active";
    float balance = 0;
    int i;
    for(i = 0; i < uarr.length(); ++i)
        if(uarr[i].get_name() == username.toStdString() && uarr[i].get_state() == "active")
        {
            QMessageBox::warning(this, tr("WARNING"),
                                 tr("This username already exists! Please reset your username!"),
                                 QMessageBox::Ok);
            break;
        }
    if(i == uarr.length())
    {
        uarr.push_back(User(userID, username.toStdString(), pswd.toStdString(), phonenum.toStdString(), addr.toStdString(), balance, state));
        uarr.array2file("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
        QMessageBox::information(this, tr("INFOMATION"), tr("Register successfully!"),QMessageBox::Ok);
    }
    this->close();
}

void regiWidget::on_cancelButton_clicked()
{
    this->close();
}

