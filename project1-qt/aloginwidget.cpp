#include "aloginwidget.h"
#include "ui_aloginwidget.h"
#include "admin.h"
#include "adminwidget.h"
#include <QMessageBox>

aloginWidget::aloginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::aloginWidget)
{
    ui->setupUi(this);
    //setAttribute(Qt::WA_QuitOnClose, false);
    ui->pswdLineEdit->setEchoMode(QLineEdit::Password);//密码显示
    //回车
    ui->adminnameLineEdit->setFocus();
    connect(ui->adminnameLineEdit,SIGNAL(returnPressed()),ui->pswdLineEdit,SLOT(setFocus()));
    connect(ui->pswdLineEdit,SIGNAL(returnPressed()),this, SLOT(on_commitButton_clicked()));
}

aloginWidget::~aloginWidget()
{
    delete ui;
}

void aloginWidget::on_commitButton_clicked()
{
    Admin admin;
    QString name = ui->adminnameLineEdit->text();
    QString pswd = ui->pswdLineEdit->text();
    if(admin.get_name() == name.toStdString() && admin.get_pswd() == pswd.toStdString())
    {
        this->close();
        adminWidget* a_w = new adminWidget;
        a_w->setAttribute(Qt::WA_DeleteOnClose);
        a_w->setWindowModality(Qt::ApplicationModal);
        a_w->show();
    }
    else
        QMessageBox::warning(this, "WARNING", "Administrator name or password is wrong!", QMessageBox::Close);
}

void aloginWidget::on_cancelButton_clicked()
{
    this->close();
}
