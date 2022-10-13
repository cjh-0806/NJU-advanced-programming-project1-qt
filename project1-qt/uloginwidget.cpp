#include "uloginwidget.h"
#include "ui_uloginwidget.h"
#include "userwidget.h"

#include <QMessageBox>

uloginWidget::uloginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::uloginWidget)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_QuitOnClose, false);
    ui->pswdLineEdit->setEchoMode(QLineEdit::Password);//密码显示
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
        QMessageBox::warning(this, "WARNING", "This user doesn't exist!");
    else if(uarr[i].get_pswd() != pswd.toStdString())
        QMessageBox::warning(this, "WARNING", "Password wrong! Please input your password again!");
    else
    {
        this->close();
        userWidget* ul_w = new userWidget;
        connect(this,SIGNAL(sendUserIndex(int)),ul_w,SLOT(getUserIndex(int)));
        emit sendUserIndex(i);
        ul_w->show();
    }

}

void uloginWidget::on_cancelButton_clicked()
{
    this->close();
}
