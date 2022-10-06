#include "uloginwidget.h"
#include "ui_uloginwidget.h"
#include "user.h"
#include <QMessageBox>

uloginWidget::uloginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::uloginWidget)
{
    ui->setupUi(this);
}

uloginWidget::~uloginWidget()
{
    delete ui;
}

void uloginWidget::on_commitButton_clicked()
{
    UArray uarr;
    uarr.file2array("/home/cjh/NJU-advanced-programming-project1-qt/user.txt");
    QString username = ui->usernameLineEdit->text();
    QString pswd = ui->pswdLineEdit->text();
    int i;
    for(i = 0; i < uarr.length(); ++i)
        if (uarr[i].get_name() == username.toStdString() && uarr[i].get_state() == "active")
            break;
    if (i == uarr.length())
        QMessageBox::warning(this, tr("WARNING"), tr("This user doesn't exist!"), QMessageBox::Ok);
    else if(uarr[i].get_pswd() != pswd.toStdString())
        QMessageBox::warning(this, tr("WARNING"),
                             tr("Password wrong! Please input your password again!"),
                             QMessageBox::Ok);
    else
        QMessageBox::information(this, tr("INFOMATION"), tr("Login successfully!"), QMessageBox::Ok);
}

void uloginWidget::on_cancelButton_clicked()
{
    this->close();
}
